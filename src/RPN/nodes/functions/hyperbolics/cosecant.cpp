#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "cosecant.h"

namespace RPN
{
	HyperbolicCosecantNode::HyperbolicCosecantNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double HyperbolicCosecantNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		double ex = exp(arg);
		return (2 * ex) / (ex * ex - 1);
	}
}

