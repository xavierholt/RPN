#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_COSECANT_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_COSECANT_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicCosecantNode : public FunctionNode
	{
	public:
		HyperbolicCosecantNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

