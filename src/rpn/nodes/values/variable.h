#ifndef RPN_NODES_VALUES_VARIABLE_H
#define RPN_NODES_VALUES_VARIABLE_H

#include "../value.h"

namespace RPN
{
	class VariableNode : public ValueNode
	{
	protected:
		const double* mVariable;
		
	public:
		VariableNode(const double* variable);
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

