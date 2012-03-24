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
#ifndef RPN_NODES_VALUES_VARIABLE_H
#define RPN_NODES_VALUES_VARIABLE_H

#include "../value.h"

namespace RPN
{
/**
 * Stores a pointer to a value so it can be changed programatically between evaluations.
 */
	class VariableNode : public ValueNode
	{
	protected:
		const double* mVariable; ///< A reference to a variable.
		
	public:
		VariableNode(const double* variable);
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

