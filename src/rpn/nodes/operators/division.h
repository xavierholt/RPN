#ifndef RPN_NODES_OPERATORS_DIVISION_H
#define RPN_NODES_OPERATORS_DIVISION_H

#include "../operator.h"

namespace RPN
{
	class DivisionNode : public OperatorNode
	{
	public:
		DivisionNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
		virtual int    precedence() const;
	};
}

#endif

