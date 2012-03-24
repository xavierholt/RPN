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
#include "value.h"

namespace RPN
{
/**
 * Constructor.
 */
	ValueNode::ValueNode(): Node()
	{
		//Nothing else to do...
	}
	
/**
 * @copydoc Node::arguments()
 * 
 * Value nodes don't expect any arguments; this function always returns zero.
 */
	int ValueNode::arguments() const
	{
		return 0;
	}
	
/**
 * @copydoc Node::flags()
 */
	Node::Flags ValueNode::flags() const
	{
		return Node::Flags(Node::VALUE | Node::VOLATILE | Node::SUCCEEDS_OP | Node::ALLFIX);
	}
	
/**
 * @copydoc Node::infixParse()
 *
 * Push all values straight to the expression stack.
 */
	void ValueNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		parser.push_to_expression(token);
	}
}

