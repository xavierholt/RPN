#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arccosecant.h"

namespace RPN
{
	HyperbolicArcCosecantNode::HyperbolicArcCosecantNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicArcCosecantNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		double inv = 1.0 / arg;
		return log(inv + sqrt(inv * inv + 1));
	}
}

