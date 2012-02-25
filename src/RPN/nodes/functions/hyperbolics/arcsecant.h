#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCSECANT_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCSECANT_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicArcSecantNode : public FunctionNode
	{
	public:
		HyperbolicArcSecantNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

