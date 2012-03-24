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
/**
 * Default constructor.
 * Sets \p node to NULL and \p name to an empty string.
 */
	Parser::Token::Token(): name(""), node(NULL)
	{
		//Nothing else to do...
	}
	
/**
 * Convenience constructor.
 * @param name The string that yielded this token.
 * @param node The node yielded by \p name .
 *
 * Sets \p name and \p node to the values provided.
 */
	Parser::Token::Token(const std::string& name, const Node* node): name(name), node(node)
	{
		//Nothing else to do...
	}
	
/**
 * Assignment operator.
 * @param other Another Token.
 * @return A reference to this token.
 *
 * Sets the members of this token equal to those of \p other .  Needed when
 * storing tokens in a std::vector.
 */
	Parser::Token& Parser::Token::operator =(const Parser::Token& other)
	{
		name = other.name;
		node = other.node;
		return *this;
	}
	
/**
 * Constructor.
 * @param context the context in which this parser operates.  Defaults to RPN::Context::ROOT.
 */
	Parser::Parser(const Context& context): mContext(&context)
	{
		//Nothing else to do...
	}
	
/**
 * Checks the result of the parsed expression.
 * Throws an RPN::Exception if the expression doesn't eave exactly one value on
 * the evaluation stack when its evaluation is complete.
 */
	void Parser::checkResult()
	{
		if(mAvailable != 1)
		{
			std::ostringstream mess;
			if(mAvailable > 1)
			{
				mess << "Invalid expression: Leaves too many (" << mAvailable << ") values after evaluation.";
			}
			else
			{
				mess << "Invalid expression: Leaves too few (" << mAvailable << ") values after evaluation.";
			}
			throw Exception(mess.str());
		}
	}
	
/**
 * Clears this expression to prepare for a new parsing.
 * Reimplementations of the RPN::Parser class should reimplement this function
 * to clear any extra class members that are involved in parsing.
 * @see parseInternal()
 */
	void Parser::clear()
	{
		mAvailable = 0;
		mMaxAvailable = 0;
		mExpression.clear();
	}
	
/**
 * Gets the next unparsed token from the input string.
 * @return The next token, or NULL if the end of the string was reached.
 *
 * This function throws an exception if unrecognized characters are
 * encountered, or if there is no translation for an operator/identifier in the
 * current context.
 */
	Parser::Token Parser::next()
	{
		//Skip any whitespace...
		while(cInitial[(int) *mIterator] & BLANK)
		{
			++mIterator;
		}
		
		//Make sure it's not the end of the string...
		if(mIterator == mEndIterator)
		{
			return Parser::Token();
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
		Parser::Token token;
		do
		{
			token.name.push_back(*mIterator);
			if(++mIterator == mEndIterator)
			{
				break;
			}
		}
		while(cSubsequent[(int) *mIterator] & type);
		
		//Look it up (or make it)...
		switch(type)
		{
		case NUMBER:
			token.node = new ConstantNode(strtod(token.name.c_str(), NULL));
			break;
		default:
			token.node = mContext->lookup(token.name);
			if(token.node == NULL)
			{
				std::ostringstream mess;
				mess << "Unrecognized name: \"" << token.name << '"';
				throw Exception(mess.str());
			}
		}
		
		return token;
	}
	
/**
 * Parses a string.
 * @param string The string to parse.
 *
 * Sets \p mInputString and its corresponding "begin" and "end" iterators
 * and passes control to parseInternal(), which does the actual parsing.  Call
 * store() when this function returns to save the parsed expression into an
 * RPN::Expression for evaluation.
 * @see parseInternal(), store()
 */
	void Parser::parse(const std::string& string)
	{
		mInputString = string;
		mEndIterator = mInputString.end();
		mIterator = mInputString.begin();
		
		clear();
		parseInternal();
	}
	
/**
 * Parses a string in the given context.
 * @param string The string to parse.
 * @param context the context in which to parse it.
 *
 * This function changes \p mContext; all future strings will also be
 * parsed in the given context (until yet another context is supplied). Call
 * store() after parsing to save the parsed expression into an RPN::Expression
 * for evaluation.
 * @see parse(), parseInternal(), store()
 */
	void Parser::parse(const std::string& string, const Context& context)
	{
		mContext = &context;
		parse(string);
	}
	
/**
 * Pushes a token to the "finalized" stack.
 * @param token the token to push.
 *
 * A PostfixParser will call this function directly.  An InfixParser will store
 * functions and operators on a temporary "shunt" stack to preserve order of
 * operations.  Users shouldn't call this function at all.
 */
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
	
/**
 * Stores a parsed expression into an RPN::Expression.
 * @param expression The expression to save to.
 *
 * This function removes all existing data from \p expression.  It does not
 * clear the parser; this function can be called multiple times without needing
 * to reparse (though why this would be necessary is beyond me).
 */
	void Parser::store(Expression& expression)
	{
		expression.clear();
		
		for(std::vector<const Node*>::const_iterator i = mExpression.begin(); i != mExpression.end(); ++i)
		{
			expression << *i;
		}
		
		expression.mMaxAvailable = mMaxAvailable;
	}
}
