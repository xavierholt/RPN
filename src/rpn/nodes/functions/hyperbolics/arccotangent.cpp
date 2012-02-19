#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arccotangent.h"

namespace RPN
{
	HyperbolicArcCotangentNode::HyperbolicArcCotangentNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicArcCotangentNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		double inv = 1.0 / arg;
		return log((1 + inv) / (1 - inv)) / 2;
	}
}

