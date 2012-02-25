#include "../../expression.h"
#include "expression.h"

namespace RPN
{
	ExpressionNode::ExpressionNode(const Expression* expression): mExpression(expression)
	{
		//Nothing else to do...
	}
	
	double ExpressionNode::evaluate(Evaluator& evaluator) const
	{
		return mExpression->evaluate(evaluator);
	}
	
	bool ExpressionNode::isVolatile() const
	{
		return true;
	}
}

