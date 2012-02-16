#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "squareroot.h"

namespace RPN
{
	SquareRootNode::SquareRootNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double SquareRootNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return sqrt(arg);
	}
}

