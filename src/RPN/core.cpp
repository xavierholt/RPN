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
#include "context.h"
#include "core.h"
#include "parser.h"

namespace RPN
{
/**
 * Checks if a given string is a valid name for a node.
 * @param name The name to check.
 * @return Whether or not \p name was valid.
 * Use this function to make sure that user-generated names can be recognized
 * by the parser.
 */
	bool isValidName(const std::string& name)
	{
		std::string::const_iterator i = name.begin();
		char type = Parser::cInitial[(int) *i];
		
		if(!type)
		{
			return false;
		}
		
		std::string::const_iterator end = name.end();
		for(++i; i != end; ++i)
		{
			if(Parser::cSubsequent[(int) *i] != type)
			{
				return false;
			}
		}
		
		return true;
	}
}

