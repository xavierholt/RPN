#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "sine.h"

namespace RPN
{
	HyperbolicSineNode::HyperbolicSineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicSineNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		double ex = exp(arg);
		return (ex * ex - 1) / (2 * ex);
	}
}

