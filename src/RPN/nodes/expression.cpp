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
#include "../expression.h"
#include "expression.h"

namespace RPN
{
/**
 * Constructor.
 * @param expression The expression to store.
 */
	ExpressionNode::ExpressionNode(const Expression* expression): Node(), mExpression(expression)
	{
		//Nothing else to do...
	}
	
/**
 * @copydoc Node::arguments()
 *
 * This function returns the number of arguments expected by the referenced
 * expression.
 */
	int ExpressionNode::arguments() const
	{
		return mExpression->arguments();
	}
	
/**
 * Evaluates the stored expression returns the result.
 * @param evaluator The current evaluation.
 * @return The result.
 */
	double ExpressionNode::evaluate(Evaluator& evaluator) const
	{
		return mExpression->evaluate(evaluator);
	}
	
/**
 * @copydoc Node::flags()
 */
	Node::Flags ExpressionNode::flags() const
	{
		if(mExpression->arguments() == 0)
		{
			return Node::Flags(Node::VALUE | Node::VOLATILE | Node::SUCCEEDS_OP | Node::ALLFIX);
		}
		else
		{
			return Node::Flags(Node::FUNCTION| Node::VOLATILE | Node::SUCCEEDS_OP | Node::PRESENTS_OP | Node::ALLFIX);
		}
	}
	
/**
 * @copydoc Node::infixParse()
 *
 * If this expression doesn't expect any arguments, treat it like a value and
 * push it straight to the expression stack.  Otherwise, treat it like a
 * function and push it to the shunt stack.
 */
	void ExpressionNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		if(mExpression->arguments() == 0)
		{
			parser.push_to_expression(token);
		}
		else
		{
			parser.push_to_stack(token);
		}
	}
}

