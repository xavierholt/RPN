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
	#include <iostream>
	#include <sstream>
#endif

#include "operator.h"
#include "../exception.h"
#include "../parsers/infix.h"

namespace RPN
{
/**
 * Constructor.
 * @param precedence The precedence of this operator.
 * @param right Whether or not this is a right-associative operator.  Defaults to false.
 * @param binary Whether or not this is a binary operator (requiring two operands).  Defaults to true.
 */
	OperatorNode::OperatorNode(int precedence, bool right, bool binary):
		Node(),
		mPrecedence(precedence),
		mIsRightAssociative(right),
		mIsBinary(binary)
	{
		//Nothing else to do...
	}
	
/**
 * Gets the number of arguments consumed by this operator.
 * @return The number of arguments.
 */
	int OperatorNode::arguments() const
	{
		return mIsBinary + 1;
	}
	
/**
 * Gets the description of this node.
 * @return An or'd combination of node flags.
 */
	Node::Flags OperatorNode::flags() const
	{
		unsigned int ret = Node::OPERATOR | Node::ALLFIX;
		
		if(!mIsBinary)
		{
			if(isRightAssociative())
			{
				ret |= Node::PRESENTS_OP | Node::SUCCEEDS_OP;
			}
		}
		else
		{
			ret |= Node::PRESENTS_OP;
		}
		
		return Node::Flags(ret);
	}
	
/**
 * Parses this node out of an infix expression.
 * @param parser The parser.
 * @param token The token representing this node.
 *
 * If this operator is \em not a unary right-associative operator:  While there
 * is an operator node of higher precedence (or a left-associative operator
 * node of equal precedence) on top of the shunt stack, pop it off and push it
 * onto the expression stack.
 *
 * Push this operator onto the shunt stack.
 */
	void OperatorNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		if(mIsBinary || isLeftAssociative())
		{
			int comp = precedence() + isRightAssociative();
	
			while(parser.hasStack())
			{
				const Node* node = parser.top().node;
				if(node->isOperator() && ((const OperatorNode*)node)->precedence() >= comp)
				{
				//	std::cout << "Shunting: '" << parser.top().name << "' (" << ((const OperatorNode*)node)->precedence() << ") > '" << token.name << "' (" << comp << ")\n";
					parser.shunt();
				}
				else
				{
					break;
				}
			}
		}
		
		parser.push_to_stack(token);
	}
	
/**
 * Checks if this operator is left-associative.
 * @return True if this operator is left-associative; false otherwise.
 */
	bool OperatorNode::isLeftAssociative() const
	{
		return (!mIsRightAssociative);
	}
	
/**
 * Checks if this operator is right-associative.
 * @return True if this operator is right-associative; false otherwise.
 */
	bool OperatorNode::isRightAssociative() const
	{
		return (mIsRightAssociative);
	}
	
/**
 * Gets the precedence of this operator.
 * @return The precedence.
 */
	int OperatorNode::precedence() const
	{
		return mPrecedence;
	}
}

