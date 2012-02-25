#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "cotangent.h"

namespace RPN
{
	CotangentNode::CotangentNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double CotangentNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return 1.0 / tan(arg);
	}
}

