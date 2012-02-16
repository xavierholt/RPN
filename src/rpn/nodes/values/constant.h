#ifndef RPN_NODES_VALUES_CONSTANT_H
#define RPN_NODES_VALUES_CONSTANT_H

#include "../value.h"

namespace RPN
{
	class ConstantNode : public ValueNode
	{
	protected:
		double mValue;
		
	public:
		ConstantNode(double value);
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

