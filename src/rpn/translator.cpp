#ifndef RPN_LIBHEADER
	#include <iostream>
	#include <sstream>
#endif

#include "context.h"
#include "exception.h"
#include "expression.h"
#include "node.h"
#include "nodes/bracket.h"
#include "nodes/values/constant.h"
#include "translator.h"

namespace RPN
{
	Translator::Translator(const Context& context, Expression& expression, const std::string& string):
		mAvailable(0),
		mMaxAvailable(0),
		mContext(context),
		mExpression(expression),
		mString(string)
	{
		mToken.reserve(string.length());
		mIterator = mString.begin();
	}
	
	bool Translator::hasStack() const
	{
		return (mStack.size() > 0);
	}
	
	const Node* Translator::next()
	{
		//Skip and whitespace...
		while(cInitial[(int) *mIterator] & BLANK)
		{
			++mIterator;
		}
		
		//Make sure it's not the end of the string...
		if(mIterator == mString.end())
		{
			return NULL;
		}
		
		//What token type starts like this?
		char type = cInitial[(int) *mIterator];
		
		//Make sure it's a valid token starter...
		if(!type)
		{
			std::ostringstream mess("Unprocessable character: '");
			mess << *mIterator << "' (" << (int) *mIterator << ")";
			throw Exception(mess.str());
		}
		
		//Read the rest of the token...
		mToken.clear();
		do
		{
			mToken.push_back(*mIterator);
			if(++mIterator == mString.end())
			{
				break;
			}
		}
		while(cSubsequent[(int) *mIterator] & type);
		
		//Look it up (or make it)...
		switch(type)
		{
		case NUMBER:
			return new ConstantNode(strtod(mToken.c_str(), NULL));
		default:
			const Node* ret = mContext.lookup(mToken);
			if(ret == NULL)
			{
				std::ostringstream mess;
				mess << "Unrecognized name: \"" << mToken << "\"";
				throw Exception(mess.str());
			}
			return ret;
		}
	}
	
	const Node* Translator::pop()
	{
		const Node* ret = mStack.back();
		mStack.pop_back();
		return ret;
	}
	
	void Translator::push_to_expression(const Node* node)
	{
		mExpression << node;
		mAvailable -= (node->arguments() - 1);
		if(mAvailable > mMaxAvailable)
		{
			mMaxAvailable = mAvailable;
		}
	}
	
	void Translator::push_to_stack(const Node* node)
	{
		mStack.push_back(node);
	}
	
	void Translator::shunt()
	{
		push_to_expression(mStack.back());
		mStack.pop_back();
	}
	
	const Node* Translator::top()
	{
		return mStack.back();
	}
	
	void Translator::translate()
	{
		const Node* node;
		while((node = next()))
		{
			node->translate(*this);
		}
		
		while(hasStack())
		{
			if(top()->isBracket())
			{
				std::stringstream mess;
				mess << "Bracket mismatch: Unclosed '" << ((BracketNode*) top())->opener() << '\'';
				throw Exception(mess.str());
			}
			
			shunt();
		}
		
		if(mAvailable != 1)
		{
			std::stringstream mess;
			mess << "Invalid expression: Expected 1 result; got " << mAvailable;
			throw Exception(mess.str());
		}
		
		mExpression.mMaxAvailable = mMaxAvailable;
	}
}

