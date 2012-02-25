#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "secant.h"

namespace RPN
{
	HyperbolicSecantNode::HyperbolicSecantNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicSecantNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		double ex = exp(arg);
		return (2 * ex) / (ex * ex + 1);
	}
}

