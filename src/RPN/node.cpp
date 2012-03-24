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
/**
 * Constructor.
 * Sets the reference count to zero.
 */
	Node::Node(): mReferenceCount(0)
	{
		//Nothing else to do...
	}
	
/**
 * Gets the number of arguments this node expects.
 * @return The expected number of arguments.
 */
	int Node::arguments() const
	{
		throw Exception("This node was never meant to be translated!");
		return -1;
	}
	
/**
 * Evaluates this node in the context of the given evaluation.
 * @param evaluator The current evaluation.
 * @return The result of evaluating this node.
 */
	double Node::evaluate(Evaluator& evaluator) const
	{
		(void)(evaluator); //Unused
		throw Exception("This node was never meant to be evaluated!");
		return 0.0;
	}
	
/**
 * @fn Node::infixParse()
 * Parses this node out of an infix expression.
 * @param parser The parser.
 * @param token The token representing this node.
 */

/**
 * @fn Node::flags()
 * Gets the description of this node.
 * @return An or'd combination of node flags.
 */

}
