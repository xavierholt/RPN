#ifndef RPN_LIBHEADER
	#include <cstdlib>
	#include <sstream>
#endif

#include "context.h"
#include "exception.h"
#include "expression.h"
#include "nodes/values/constant.h"
#include "parser.h"

namespace RPN
{
	typedef std::vector<const Node*>::iterator EItr;
	typedef std::vector<const Node*>::const_iterator ECItr;
	
	Parser::Token::Token(): name(""), node(NULL)
	{
		//Nothing else to do...
	}
	
	Parser::Token::Token(const std::string& name, const Node* node): name(name), node(node)
	{
		//Nothing else to do...
	}
	
	Parser::Token& Parser::Token::operator =(const Parser::Token& other)
	{
		name = other.name;
		node = other.node;
		return *this;
	}
	
	Parser::Parser(const Context& context): mContext(context)
	{
		//Nothing else to do...
	}
	
	void Parser::checkResult()
	{
		if(mAvailable != 1)
		{
			std::ostringstream mess;
			//TODO: Clarify this error message:
			mess << "Invalid expression: Expected 1 result; got " << mAvailable;
			throw Exception(mess.str());
		}
	}
	
	Parser::Token Parser::next(std::string::const_iterator& itr, std::string::const_iterator& end)
	{
		//Skip any whitespace...
		while(cInitial[(int) *itr] & BLANK)
		{
			++itr;
		}
		
		//Make sure it's not the end of the string...
		if(itr == end)
		{
			return Parser::Token();
		}
		
		//What token type starts like this?
		char type = cInitial[(int) *itr];
		
		//Make sure it's a valid token starter...
		if(!type)
		{
			std::ostringstream mess("Unprocessable character: '");
			mess << *itr << "' (" << (int) *itr << ")";
			throw Exception(mess.str());
		}
		
		//Read the rest of the token...
		Parser::Token token;
		do
		{
			token.name.push_back(*itr);
			if(++itr == end)
			{
				break;
			}
		}
		while(cSubsequent[(int) *itr] & type);
		
		//Look it up (or make it)...
		switch(type)
		{
		case NUMBER:
			token.node = new ConstantNode(strtod(token.name.c_str(), NULL));
			break;
		default:
			token.node = mContext.lookup(token.name);
			if(token.node == NULL)
			{
				std::ostringstream mess;
				mess << "Unrecognized name: \"" << token.name << '"';
				throw Exception(mess.str());
			}
		}
		
		return token;
	}
	
	void Parser::push_to_expression(Parser::Token& token)
	{
		int args = token.node->arguments();
		if(mAvailable < args)
		{
			std::ostringstream mess;
			mess << "Too few arguments to \"" << token.name << "\": expected " << args << "; got " << mAvailable;
			throw Exception(mess.str());
		}
		
		mAvailable -= (args - 1);
		if(mAvailable > mMaxAvailable)
		{
			mMaxAvailable = mAvailable;
		}
		
		mExpression.push_back(token.node);
	}
	
	void Parser::reset()
	{
		mAvailable = 0;
		mMaxAvailable = 0;
		mExpression.clear();
	}
	
	void Parser::store(Expression& expression)
	{
		expression.clear();
		
		EItr end = mExpression.end();
		for(EItr i = mExpression.begin(); i != end; ++i)
		{
			expression << *i;
		}
		
		expression.mMaxAvailable = mMaxAvailable;
	}
}
