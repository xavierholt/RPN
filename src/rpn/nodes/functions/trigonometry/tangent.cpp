#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "tangent.h"

namespace RPN
{
	TangentNode::TangentNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double TangentNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return tan(arg);
	}
}

