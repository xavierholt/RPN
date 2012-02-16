#ifndef RPN_NODES_OPERATORS_SUBTRACTION_H
#define RPN_NODES_OPERATORS_SUBTRACTION_H

#include "../operator.h"

namespace RPN
{
	class SubtractionNode : public OperatorNode
	{
	public:
		SubtractionNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

