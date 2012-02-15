#ifndef RPN_NODES_OPERATORS_MULTIPLICATION_H
#define RPN_NODES_OPERATORS_MULTIPLICATION_H

#include "../operator.h"

namespace RPN
{
	class MultiplicationNode : public OperatorNode
	{
	public:
		MultiplicationNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
		virtual int    precedence() const;
	};
}

#endif

