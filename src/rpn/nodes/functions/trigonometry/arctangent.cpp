#include <cmath>
#include "arctangent.h"
#include "../../../evaluator.h"

namespace RPN
{
	ArcTangentNode::ArcTangentNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double ArcTangentNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return atan(arg);
	}
}

