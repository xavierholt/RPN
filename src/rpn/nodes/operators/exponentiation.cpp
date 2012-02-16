#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "exponentiation.h"

namespace RPN
{
	ExponentiationNode::ExponentiationNode(): OperatorNode(OperatorNode::EXPONENTIATION, OperatorNode::RIGHT)
	{
		//Nothing else to do...
	}
	
	double ExponentiationNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.pop();
		double arg1 = evaluator.pop();
		return pow(arg1, arg2);
	}
}

