#ifndef RPN_NODES_FUNCTIONS_HYPERBOLICS_COTANGENT_H
#define RPN_NODES_FUNCTIONS_HYPERBOLICS_COTANGENT_H

#include "../../function.h"

namespace RPN
{
	class HyperbolicCotangentNode : public FunctionNode
	{
	public:
		HyperbolicCotangentNode();
		
		double evaluate(Evaluator& evaluator) const;
	};
}

#endif

