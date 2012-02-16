#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "naturallogarithm.h"

namespace RPN
{
	NaturalLogarithmNode::NaturalLogarithmNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double NaturalLogarithmNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return log(arg);
	}
}

