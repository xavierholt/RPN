#include <cmath>
#include "arccosine.h"
#include "../../../evaluator.h"

namespace RPN
{
	ArcCosineNode::ArcCosineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double ArcCosineNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return acos(arg);
	}
}

