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
	#include <cmath>
#endif

#include "arctangent2.h"

namespace RPN
{
/**
 * Constructor.
 */
	ArcTangent2Node::ArcTangent2Node(): FunctionNode(2)
	{
		//Nothing else to do...
	}
	
/**
 * Pops two values off the stack and returns their arc tangent.
 * @param evaluator The current evaluation.
 * @return The arc tangent of the popped values.
 */
	double ArcTangent2Node::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg2 = evaluator.pop();
		double arg1 = evaluator.pop();
		return atan2(arg1, arg2);
	}
}

