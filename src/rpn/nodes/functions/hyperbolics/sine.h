#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_SINE_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_SINE_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicSineNode : public FunctionNode
	{
	public:
		HyperbolicSineNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

