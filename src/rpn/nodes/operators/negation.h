#ifndef RPN_NODES_OPERATORS_NEGATION_H
#define RPN_NODES_OPERATORS_NEGATION_H

#include "../operator.h"

namespace RPN
{
	class NegationNode : public OperatorNode
	{
	public:
		NegationNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

