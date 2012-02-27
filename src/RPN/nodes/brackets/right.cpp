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

#include "../../exception.h"
#include "../../parsers/infix.h"
#include "right.h"

namespace RPN
{
	RightBracketNode::RightBracketNode(char opener, char closer): BracketNode(opener, closer)
	{
		//Nothing else to do...
	}
	
	Node::Flags RightBracketNode::flags() const
	{
		return Node::Flags(Node::BRACKET | Node::INFIX);
	}
	
	void RightBracketNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		(void)(token); //Unused
		
		while(parser.hasStack())
		{
			Parser::Token tmp = parser.pop();
			const Node* node = tmp.node;
			
			if(node->isBracket())
			{
				const BracketNode* bracket = (BracketNode*) node;
				
				if(bracket->isClosedBy(this))
				{
					if(parser.hasStack() && parser.top().node->isFunction())
					{
						parser.shunt();
					}
					return;
				}
				else
				{
					std::ostringstream mess;
					mess << "Bracket mismatch: Expected '" << bracket->closer() << "'; got '" << closer() << '\'';
					throw Exception(mess.str());
				}
			}
			else
			{
				parser.push_to_expression(tmp);
			}
		}
		
		std::ostringstream mess;
		mess << "Bracket mismatch: Unmatched '" << closer() << '\'';
		throw Exception(mess.str());
	}
}

