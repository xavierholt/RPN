#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_COSINE_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_COSINE_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicCosineNode : public FunctionNode
	{
	public:
		HyperbolicCosineNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

