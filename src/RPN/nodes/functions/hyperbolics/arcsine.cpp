#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arcsine.h"

namespace RPN
{
	HyperbolicArcSineNode::HyperbolicArcSineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicArcSineNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return log(arg + sqrt(arg * arg + 1));
	}
}

