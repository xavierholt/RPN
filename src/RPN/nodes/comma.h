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
#ifndef RPN_NODES_COMMA_H
#define RPN_NODES_COMMA_H

#include "../node.h"

namespace RPN
{
/**
 * A node to represent a function argument separator.
 * This node will never occur in an RPN::Expression; it is only used when
 * parsing infix expressions.
 */
	class CommaNode : public Node
	{
	public:
		CommaNode();
		
		virtual Flags flags() const;
		virtual void  infixParse(InfixParser& parser, Parser::Token& token) const;
	};
}

#endif

