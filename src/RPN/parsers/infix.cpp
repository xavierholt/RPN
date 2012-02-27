/******************************************************************************
   Copyright 2012 Kevin Burk
   
   This file is part of RPN.
  
   RPN is free software: you can redistribute it and/or modify it under the
   terms of the GNU General Public License as published by the Free Software
   Foundation, either version 3 of the License, or (at your option) any later
   version.
  
   RPN is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
   details.
  
   You should have received a copy of the GNU General Public License along
   with RPN.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/
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
		parse(string);
	}
	
	bool InfixParser::hasStack() const
	{
		return (mStack.size() > 0);
	}
	
	void InfixParser::parse(const std::string& string)
	{
		reset();
		std::string::const_iterator itr = string.begin();
		std::string::const_iterator end = string.end();
		
		Node::Flags flags = Node::PRESENTS_OP;
		Parser::Token token;
		
		while((token = next(itr, end)).node != NULL)
		{
			if(!token.node->succeeds(flags))
			{
				if(flags & Node::PRESENTS_OP)
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
			flags = token.node->flags();
		}
		
		while(hasStack())
		{
			if(top().node->isBracket())
			{
				std::ostringstream mess;
				mess << "Bracket mismatch: Unclosed '" << ((BracketNode*) top().node)->opener() << '\'';
				throw Exception(mess.str());
			}
			
			shunt();
		}
		
		checkResult();
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

