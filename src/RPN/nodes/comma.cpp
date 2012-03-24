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
#include "../parsers/infix.h"
#include "comma.h"

namespace RPN
{
/**
 * Constructor.
 */
	CommaNode::CommaNode(): Node()
	{
		//Nothing else to do...
	}
	
/**
 * Gets the description of this node.
 * @return An or'd combination of node flags.
 */
	Node::Flags CommaNode::flags() const
	{
		return Node::Flags(Node::PRESENTS_OP | Node::INFIX);
	}
	
/**
 * Parses this node out of an infix expression.
 * @param parser The parser.
 * @param token The token representing this node (unused).
 *
 * Pops nodes from the "shunt" stack to the expression until a left bracket is
 * encountered.
 */
	void CommaNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		(void)(token); //Unused
		
		while(parser.hasStack())
		{
			if(parser.top().node->isBracket())
			{
				return;
			}
			else
			{
				parser.shunt();
			}
		}
	}
}

