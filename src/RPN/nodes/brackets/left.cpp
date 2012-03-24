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
#include "left.h"
#include "../../parsers/infix.h"

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
	LeftBracketNode::LeftBracketNode(char opener, char closer): BracketNode(opener, closer)
	{
		//Nothing else to do...
	}
	
/**
 * Gets a description of this node.
 * @return An or'd combination of node descriptions.
 */
	Node::Flags LeftBracketNode::flags() const
	{
		return Node::Flags(Node::BRACKET | Node::PRESENTS_OP | Node::SUCCEEDS_OP | Node::INFIX);
	}
	
/**
 * Parses this node out of an infix expression.
 * @param parser The parser.
 * @param token The token representing this node.
 *
 * Parsing a left bracket is simple - push it straight to the "shunt" stack.
 */
	void LeftBracketNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		parser.push_to_stack(token);
	}
}

