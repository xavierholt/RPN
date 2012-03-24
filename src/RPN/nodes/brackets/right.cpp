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
/**
 * Constructor.
 * @param opener The bracket character that opens this type of bracket.  This
 * character is not used during actual parsing; it is only used when reporting
 * parse errors.
 * @param closer The bracket character that closes this type of bracket.  This
 * character is not used during actual parsing; it is only used when reporting
 * parse errors.
 */
	RightBracketNode::RightBracketNode(char opener, char closer): BracketNode(opener, closer)
	{
		//Nothing else to do...
	}
	
/**
 * Gets a description of this node.
 * @return An or'd combination of node descriptions.
 */
	Node::Flags RightBracketNode::flags() const
	{
		return Node::Flags(Node::BRACKET | Node::INFIX);
	}
	
/**
 * Parses this node out of an infix expression.
 * @param parser The parser.
 * @param token The token representing this node.
 *
 * When a right bracket is encountered, pop tokens off the "shunt" stack until
 * a left bracket is found.  If the bottom of the shunt stack is reached, throw
 * a bracket mismatch error.  If the wrong type of left bracket is found, throw
 * a bracket mismatch error.  If a matching left bracket is found, pop it off
 * the shunt stack.  Then, if there is a function node on top of the shunt
 * stack, pop it off and push it onto the expression stack.
 */
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

