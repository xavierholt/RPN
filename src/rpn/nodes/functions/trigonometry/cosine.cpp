#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "cosine.h"

namespace RPN
{
	CosineNode::CosineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double CosineNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return cos(arg);
	}
}

