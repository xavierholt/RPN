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

#include "factorial.h"
#include "../../core.h"

namespace RPN
{
/**
 * Values needed by the gamma() function to compute Lanczos approximations.
 */
	const double FactorialNode::cHelper[9] = {
		0.99999999999980993,
		676.5203681218851,
		-1259.1392167224028,
		771.32342877765313,
		-176.61502916214059,
		12.507343278686905,
		-0.13857109526572012,
		9.9843695780195716e-6,
		1.5056327351493116e-7
	};
	
/**
 * Constructor.
 */
	FactorialNode::FactorialNode(): OperatorNode(OperatorNode::FACTORIAL, false, false)
	{
		//Nothing else to do...
	}
	
/**
 * Pops a value off the stack and returns its factorial.
 * @param evaluator The current evaluation.
 * @return The factorial of the popped node.
 *
 * This node uses the gamma function to extend the factorial function over all
 * the real numbers.
 * @see https://en.wikipedia.org/wiki/Gamma_function
 */
	double FactorialNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return gamma(arg + 1.0);
	}
	
/**
 * Returns the gamma function of the given value.
 * @param z Any real number.
 * @return The gamma function of \p z.
 *
 * This function uses Lanczos approximation to return an easily-computable
 * approximate value.  It is based on the example code from the linked
 * Wikipedia page, which "typically gives 15 correct decimal places."
 * @see https://en.wikipedia.org/wiki/Lanczos_approximation
 */
	double FactorialNode::gamma(double z)
	{
		// Lanczos Approximation of the Gamma Function
		// http://en.wikipedia.org/wiki/Lanczos_approximation
		
		if(z < 0.5)
		{
			return RPN::Constants::PI / (sin(RPN::Constants::PI * z) * gamma(1.0 - z));
		}
		else
		{
			z -= 1.0;
			double x = cHelper[0];
			
			for(int i = 1; i < 9; ++i)
			{
				x += cHelper[i] / (z + i);
			}
			
			double t = z + 7.5;
			return sqrt(2 * RPN::Constants::PI) * pow(t, z + 0.5) * exp(-t) * x;
		}
	}
}

