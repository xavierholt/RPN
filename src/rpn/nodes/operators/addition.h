#ifndef RPN_NODES_OPERATORS_ADDITION_H
#define RPN_NODES_OPERATORS_ADDITION_H

#include "../operator.h"

namespace RPN
{
	class AdditionNode : public OperatorNode
	{
	public:
		AdditionNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
		virtual int    precedence() const;
	};
}

#endif

