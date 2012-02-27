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
#include "exception.h"
#include "node.h"

namespace RPN
{
	int Node::arguments() const
	{
		throw Exception("This node was never meant to be translated!");
		return -1;
	}
	
	double Node::evaluate(Evaluator& evaluator) const
	{
		(void)(evaluator); //Unused
		throw Exception("This node was never meant to be evaluated!");
		return 0.0;
	}
}
