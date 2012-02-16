#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "sine.h"

namespace RPN
{
	SineNode::SineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double SineNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return sin(arg);
	}
}

