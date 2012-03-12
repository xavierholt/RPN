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
	PostfixParser::PostfixParser(const Context& context): Parser(context)
	{
		//Nothing else to do...
	}
	
	PostfixParser::PostfixParser(const std::string& string, const Context& context): Parser(context)
	{
		parse(string);
	}
	
	void PostfixParser::parseInternal(const std::string& string)
	{
		reset();
		std::string::const_iterator itr = string.begin();
		std::string::const_iterator end = string.end();
		
		Parser::Token token;
		while((token = next(itr, end)).node != NULL)
		{
			push_to_expression(token);
		}
		
		checkResult();
	}
}

