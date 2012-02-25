#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "tangent.h"

namespace RPN
{
	HyperbolicTangentNode::HyperbolicTangentNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicTangentNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		double ex = exp(2 * arg);
		return (ex - 1) / (ex + 1);
	}
}

