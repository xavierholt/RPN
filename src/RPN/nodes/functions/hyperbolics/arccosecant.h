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
#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCCOSECANT_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCCOSECANT_H

#include "../../function.h"

namespace RPN
{
/**
 * A node for calculating hyperbolic arc cosecants.
 */
	class HyperbolicArcCosecantNode : public FunctionNode
	{
	public:
		HyperbolicArcCosecantNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

