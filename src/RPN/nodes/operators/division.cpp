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
#include "division.h"

namespace RPN
{
/**
 * Constructor.
 */
	DivisionNode::DivisionNode(): OperatorNode(OperatorNode::DIVISION)
	{
		//Nothing else to do...
	}
	
/**
 * Pops two values off the stack and returns the first divided by the second.
 * @param evaluator The current evaluation.
 * @return The first popped value divided by the second.
 */
	double DivisionNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.pop();
		double arg1 = evaluator.pop();
		return (arg1 / arg2);
	}
}

