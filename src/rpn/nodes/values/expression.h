#ifndef RPN_NODES_VALUES_EXPRESSION_H
#define RPN_NODES_VALUES_EXPRESSION_H

#include "../value.h"

namespace RPN
{
	class Expression;
	
	class ExpressionNode : public ValueNode
	{
	protected:
		const Expression* mExpression;
		
	public:
		ExpressionNode(const Expression* expression);
		
		virtual double evaluate(Evaluator& evaluator) const;
		virtual bool   isVolatile() const;
	};
}

#endif

