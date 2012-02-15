#include <cmath>
#include "exponential.h"

namespace RPN
{
	ExponentialNode::ExponentialNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double ExponentialNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return exp(arg);
	}
}

