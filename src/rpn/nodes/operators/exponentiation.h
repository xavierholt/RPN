#ifndef RPN_NODES_OPERATORS_EXPONENTIATION_H
#define RPN_NODES_OPERATORS_EXPONENTIATION_H

#include "../operator.h"

namespace RPN
{
	class ExponentiationNode : public OperatorNode
	{
	public:
		ExponentiationNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
		virtual bool   isRightAssociative() const;
		virtual int    precedence() const;
	};
}

#endif

