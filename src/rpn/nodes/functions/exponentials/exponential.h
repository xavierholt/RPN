#ifndef RPN_NODES_FUNCTIONS_EXPONENTIALS_EXPONENTIAL_H
#define RPN_NODES_FUNCTIONS_EXPONENTIALS_EXPONENTIAL_H

#include "../../function.h"

namespace RPN
{
	class ExponentialNode : public FunctionNode
	{
	public:
		ExponentialNode();
		
		virtual double evaluate(Evaluator& translator) const;
	};
}

#endif

