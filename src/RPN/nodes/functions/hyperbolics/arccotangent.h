#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCCOTANGENT_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_ARCCOTANGENT_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicArcCotangentNode : public FunctionNode
	{
	public:
		HyperbolicArcCotangentNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

