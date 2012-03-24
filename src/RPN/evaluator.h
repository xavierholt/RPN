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
#ifndef RPN_EVALUATOR_H
#define RPN_EVALUATOR_H

#ifndef RPN_LIBHEADER
	#include <vector>
#endif

namespace RPN
{
/**
 * Contains data needed for the evaluation of an RPN::Expression.
 * This class is a thin wrapper around two stacks: A value stack, where numbers
 * are stored as they are evaluated, and a binding stack, which stores pointers
 * to the top of the stack as of when each expression or sub-expression began
 * evaluating.  This serves as a "base pointer," allowing the current
 * expression access to its original arguments regardless of the height of the
 * current size of the stack.
 */
	class Evaluator
	{
	protected:
		std::vector<double> mStack;    ///< The value stack.
		std::vector<int>    mBindings; ///< The binding stack.
		
	public:
		double argument(int index)
		{
			return mStack[mBindings.back() + index];
		}
		
/**
 * Adds a new binding to the binding stack.
 * This function is called just before an expression begins evaluating.
 * @see release()
 */
		void bind()
		{
			mBindings.push_back(mStack.size());
		}
		
/**
 * Gets the number of values on the value stack.
 * @return The number of values.
 */
		int count() const
		{
			return mStack.size();
		}
		
/**
 * Pops a value off the value stack and returns it.
 * @return The popped value.
 * @see push()
 */
		double pop()
		{
			double ret = mStack.back();
			mStack.pop_back();
			return ret;
		}
		
/**
 * Pushes a value onto the value stack.
 * @param value the value to be pushed.
 * @see pop()
 */
		void push(double value)
		{
			mStack.push_back(value);
		}
		
/**
 * Pops the current binding off the binding stack.
 * This function is called whenever an expression finishes evaluating.
 * @see bind()
 */
		void release()
		{
			mBindings.pop_back();
		}
		
/**
 * Reserves additional space on top of the value stack.
 * @param count The number of values to reserve space for.
 * The reserved space is in addition to any space taken up by values already on
 * the value stack.
 */
		void reserve(int count)
		{
			mStack.reserve(mStack.size() + count);
		}
	};
}

#endif

