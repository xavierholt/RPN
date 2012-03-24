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
#ifndef RPN_NODES_VALUE_H
#define RPN_NODES_VALUE_H

#include "../node.h"

namespace RPN
{
/**
 * Base class for nodes that store values.
 */
	class ValueNode : public Node
	{
	public:
		ValueNode();
		
		virtual int   arguments() const;
		virtual Flags flags() const;
		virtual void  infixParse(InfixParser& parser, Parser::Token& token) const;
	};
}

#endif

