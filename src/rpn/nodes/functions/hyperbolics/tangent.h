#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_TANGENT_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_TANGENT_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicTangentNode : public FunctionNode
	{
	public:
		HyperbolicTangentNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

