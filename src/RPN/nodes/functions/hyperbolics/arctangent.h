#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCTANGENT_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCTANGENT_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicArcTangentNode : public FunctionNode
	{
	public:
		HyperbolicArcTangentNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

