#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "binarylogarithm.h"

namespace RPN
{
	BinaryLogarithmNode::BinaryLogarithmNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double BinaryLogarithmNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return log(arg) / log(2);
	}
}

