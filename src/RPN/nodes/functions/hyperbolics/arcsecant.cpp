#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arcsecant.h"

namespace RPN
{
	HyperbolicArcSecantNode::HyperbolicArcSecantNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicArcSecantNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		double inv = 1.0 / arg;
		return log(inv + sqrt((inv - 1) * (inv + 1)));
	}
}

