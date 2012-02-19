#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "cotangent.h"

namespace RPN
{
	HyperbolicCotangentNode::HyperbolicCotangentNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicCotangentNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		double ex = exp(2 * arg);
		return (ex + 1) / (ex - 1);
	}
}

