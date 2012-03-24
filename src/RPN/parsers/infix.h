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
#ifndef RPN_PARSERS_INFIX_H
#define RPN_PARSERS_INFIX_H

#include "../context.h"
#include "../parser.h"

namespace RPN
{
/**
 * A parser for Infix Notation.
 * Implements Dijkstra's "Shunting Yard" algorithm.
 * @see https://en.wikipedia.org/wiki/Shunting_yard_algorithm
 */
	class InfixParser : public Parser
	{
	protected:
		std::vector<Token> mStack; ///< The function/operator "shunt" stack.
		
	protected:
		virtual void clear();
		virtual void parseInternal();
		
	public:
		InfixParser(const Context& context = Context::ROOT);
		InfixParser(const std::string& string, const Context& context);
		
		bool   hasStack() const;
		Token  pop();
		void   push_to_stack(Token& token);
		void   shunt();
		Token& top();
	};
}

#endif

