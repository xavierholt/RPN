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
#include "argument.h"

namespace RPN
{
/**
 * Constructor.
 * @param offset The index of the argument as a negative number.
 *
 * The rightmost argument is always at index -1; the next-rightmost is at index
 * -2, and so forth.
 */
	ArgumentNode::ArgumentNode(int offset): ValueNode(), mOffset(offset)
	{
		//Nothing else to do...
	}
	
/**
 * Convenience constructor.
 * @param number The index of the argument as a positive number.
 * @param total The total number of arguments.
 *
 * The leftmost argument is always at index 1 (not 0!); the next-leftmost is at
 * index 2, and so forth.
 *
 * The \p total is required because the argument index is stored internally as
 * a negative number, and the negative index of the arguments depends on their
 * total number.  For example: argument 1 of 1 has the negative index of -1,
 * but argument 1 of 3 has the negative index of -3.
 */
	ArgumentNode::ArgumentNode(int number, int total): ValueNode(), mOffset(number - total - 1)
	{
		//Nothing else to do...
	}
	
/**
 * Retrieves the argument at \p mOffset from the current evaluation.
 * @param evaluator The current evaluation.
 * @return The value of the argument.
 */
	double ArgumentNode::evaluate(Evaluator& evaluator) const
	{
		return evaluator.argument(mOffset);
	}
}

