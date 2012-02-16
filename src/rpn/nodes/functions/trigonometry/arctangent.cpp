#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arctangent.h"

namespace RPN
{
	ArcTangentNode::ArcTangentNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double ArcTangentNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return atan(arg);
	}
}

