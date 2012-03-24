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
#include "function.h"
#include "../parsers/infix.h"

namespace RPN
{
/**
 * Constructor.
 * @param args The number of arguments expected by this function.
 */
	FunctionNode::FunctionNode(int args): Node(), mArguments(args)
	{
		//Nothing else to do...
	}
	
/**
 * @copydoc RPN::Node::arguments()
 *
 * This function returns the argument count that was passed to the constructor.
 */
	int FunctionNode::arguments() const
	{
		return mArguments;
	}
	
/**
 * @copydoc RPN::Node::flags()
 */
	Node::Flags FunctionNode::flags() const
	{
		return Node::Flags(Node::FUNCTION| Node::SUCCEEDS_OP | Node::PRESENTS_OP | Node::ALLFIX);
	}
	
/**
 * @copydoc RPN::Node::infixParse()
 *
 * Pushes this node directly onto the shunt stack.
 */
	void FunctionNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		parser.push_to_stack(token);
	}
}

