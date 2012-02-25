#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arccotangent.h"

namespace RPN
{
	ArcCotangentNode::ArcCotangentNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double ArcCotangentNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return atan(1.0 / arg);
	}
}

