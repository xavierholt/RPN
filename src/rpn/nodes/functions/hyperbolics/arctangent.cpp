#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arctangent.h"

namespace RPN
{
	HyperbolicArcTangentNode::HyperbolicArcTangentNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicArcTangentNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return log((1 + arg) / (1 - arg)) / 2;
	}
}

