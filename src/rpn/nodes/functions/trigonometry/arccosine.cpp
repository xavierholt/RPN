#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arccosine.h"

namespace RPN
{
	ArcCosineNode::ArcCosineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double ArcCosineNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return acos(arg);
	}
}

