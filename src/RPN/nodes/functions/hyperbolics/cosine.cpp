#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "cosine.h"

namespace RPN
{
	HyperbolicCosineNode::HyperbolicCosineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicCosineNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		double ex = exp(arg);
		return (ex * ex + 1) / (2 * ex);
	}
}

