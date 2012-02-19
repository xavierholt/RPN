#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCCOSECANT_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCCOSECANT_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicArcCosecantNode : public FunctionNode
	{
	public:
		HyperbolicArcCosecantNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

