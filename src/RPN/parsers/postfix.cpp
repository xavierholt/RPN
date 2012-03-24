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
#include "postfix.h"

namespace RPN
{
/**
 * Constructor.
 * @param context The context in which to parse.
 */
	PostfixParser::PostfixParser(const Context& context): Parser(context)
	{
		//Nothing else to do...
	}
	
/**
 * Convenience constructor.
 * @param string A string to parse.
 * @param context The context in which to parse it.
 *
 * Parses \p string in the given context.  Call store() after parsing to
 * save the parsed expression into an RPN::Expression for evaluation.
 * @see parse(), parseInternal(), store()
 */
	PostfixParser::PostfixParser(const std::string& string, const Context& context): Parser(context)
	{
		parse(string);
	}
	
/**
 * Does the actual parsing.
 */
	void PostfixParser::parseInternal()
	{
		Parser::Token token;
		while((token = next()).node != NULL)
		{
			push_to_expression(token);
		}
		
		checkResult();
	}
}

