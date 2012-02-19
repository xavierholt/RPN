#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arccosine.h"

namespace RPN
{
	HyperbolicArcCosineNode::HyperbolicArcCosineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicArcCosineNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return log(arg + sqrt((arg + 1) * (arg - 1)));
	}
}

