#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCSINE_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCSINE_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicArcSineNode : public FunctionNode
	{
	public:
		HyperbolicArcSineNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

