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
#include "constant.h"

namespace RPN
{
/**
 * Constructor.
 * @param value The constant to store.
 */
	ConstantNode::ConstantNode(double value): ValueNode(), mValue(value)
	{
		//Nothing else to do...
	}
	
/**
 * Gets a description of this node.
 * @return An or'd combination of node descriptors.
 */
	Node::Flags ConstantNode::flags() const
	{
		return Node::Flags(Node::VALUE | Node::SUCCEEDS_OP | Node::ALLFIX);
	}
	
/**
 * Gets the stored constant.
 * @param evaluator The current evaluation (unused).
 * @return The stored constant.
 */
	double ConstantNode::evaluate(Evaluator& evaluator) const
	{
		(void)(evaluator); //Unused
		return mValue;
	}
}

