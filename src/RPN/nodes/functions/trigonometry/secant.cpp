#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "secant.h"

namespace RPN
{
	SecantNode::SecantNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double SecantNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return 1.0 / cos(arg);
	}
}

