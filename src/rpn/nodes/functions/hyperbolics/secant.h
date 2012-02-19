#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_SECANT_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_SECANT_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicSecantNode : public FunctionNode
	{
	public:
		HyperbolicSecantNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

