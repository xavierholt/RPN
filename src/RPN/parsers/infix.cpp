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
/**
 * Constructor.
 * @param context The context in which to parse.
 */
	InfixParser::InfixParser(const Context& context): Parser(context)
	{
		//Nothing else to do...
	}
	
/**
 * Convenience constructor.
 * @param string A string to parse.
 * @param context The context in which to parse it.
 *
 * Parses \p string in the given context.  Call store() to save the parsed
 * expression into an RPN::Expression for evaluation.
 * @see parse(), parseInternal(), store()
 */
	InfixParser::InfixParser(const std::string& string, const Context& context): Parser(context)
	{
		parse(string);
	}
	
/**
 * Clears the parser in preparation for parsing.
 */
	void InfixParser::clear()
	{
		Parser::clear();
		mStack.clear();
	}
	
/**
 * Checks if there are tokens on the "shunt" stack.
 * @return True if there is at least one token on the shunt stack; false otherwise.
 */
	bool InfixParser::hasStack() const
	{
		return (mStack.size() > 0);
	}
	
/**
 * Performs the actual parsing.
 */
	void InfixParser::parseInternal()
	{
		Node::Flags flags = Node::PRESENTS_OP;
		Parser::Token token;
		
		while((token = next()).node != NULL)
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
	
/**
 * Pops a token off the "shunt" stack and returns it.
 * @return the popped token.
 */
	Parser::Token InfixParser::pop()
	{
		Token ret = mStack.back();
		mStack.pop_back();
		return ret;
	}
	
/**
 * Pushes a token to the "shunt" stack.
 * @param token The token to push.
 */
	void InfixParser::push_to_stack(Token& token)
	{
		mStack.push_back(token);
	}
	
/**
 * Pops a token off the "shunt" stack and pushes it onto the expression stack.
 */
	void InfixParser::shunt()
	{
		push_to_expression(mStack.back());
		mStack.pop_back();
	}
	
/**
 * Gets a reference to the token on top of the "shunt" stack.
 * @return A token reference.
 */
	Parser::Token& InfixParser::top()
	{
		return mStack.back();
	}
}

