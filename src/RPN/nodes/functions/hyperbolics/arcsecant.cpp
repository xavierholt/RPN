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

#include "arcsecant.h"

namespace RPN
{
/**
 * Constructor.
 */
	HyperbolicArcSecantNode::HyperbolicArcSecantNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
/**
 * Pops a value off the stack and returns its hyperbolic arc secant.
 * @param evaluator The current evaluation.
 * @return The hyperbolic arc secant of the popped node.
 */
	double HyperbolicArcSecantNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		double inv = 1.0 / arg;
		return log(inv + sqrt((inv - 1) * (inv + 1)));
	}
}

