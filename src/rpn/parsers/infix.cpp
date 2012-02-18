#ifndef RPN_LIBHEADER
	#include <sstream>
#endif

#include "../exception.h"
#include "infix.h"
#include "../nodes/bracket.h"
#include "../nodes/operators/multiplication.h"
#include "../nodes/operators/negation.h"

namespace RPN
{
	InfixParser::InfixParser(const std::string& string, const Context& context): Parser(context)
	{
		auto itr = string.begin();
		auto end = string.end();
		
		int presented = Node::OPERATOR;
		Parser::Token token;
		
		while((token = next(itr, end)).node != NULL)
		{
			if(token.node->infixSucceeds() != presented)
			{
				if(presented == Node::OPERATOR)
				{
					//TODO: Configurable implicit negation
					if(token.name == "-")
					{
						//Negation
						//TODO: Use a common instance to prevent memory leaks:
						token.node = new NegationNode;
					}
					else
					{
						std::ostringstream mess;
						mess << "Syntax error: Expected value; got \"" << token.name << '"';
						throw Exception(mess.str());
					}
				}
				else
				{
					//TODO: Configurable implicit multiplication
					if(true)
					{
						//Implicit Multiplication
						//TODO: Use a common instance to prevent memory leaks:
						Parser::Token impmult("[implicit multiplication]", new MultiplicationNode);
						impmult.node->infixParse(*this, impmult);
					}
					else
					{
						std::ostringstream mess;
						mess << "Syntax error: Expected operator; got \"" << token.name << '"';
						throw Exception(mess.str());
					}
				}
			}
			
			token.node->infixParse(*this, token);
			presented = token.node->infixPresents();
		}
		
		while(hasStack())
		{
			if(top().node->type() == Node::BRACKET)
			{
				std::ostringstream mess;
				mess << "Bracket mismatch: Unclosed '" << ((BracketNode*) top().node)->opener() << '\'';
				throw Exception(mess.str());
			}
			
			shunt();
		}
		
		if(mAvailable != 1)
		{
			std::ostringstream mess;
			//TODO: Clarify this error message:
			mess << "Invalid expression: Expected 1 result; got " << mAvailable;
			throw Exception(mess.str());
		}
	}
	
	bool InfixParser::hasStack() const
	{
		return (mStack.size() > 0);
	}
	
	Parser::Token InfixParser::pop()
	{
		Token ret = mStack.back();
		mStack.pop_back();
		return ret;
	}
	
	void InfixParser::push_to_stack(Token& token)
	{
		mStack.push_back(token);
	}
	
	void InfixParser::shunt()
	{
		push_to_expression(mStack.back());
		mStack.pop_back();
	}
	
	Parser::Token& InfixParser::top()
	{
		return mStack.back();
	}
}

