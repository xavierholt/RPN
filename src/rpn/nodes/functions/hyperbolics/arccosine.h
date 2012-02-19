#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCCOSINE_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCCOSINE_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicArcCosineNode : public FunctionNode
	{
	public:
		HyperbolicArcCosineNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

