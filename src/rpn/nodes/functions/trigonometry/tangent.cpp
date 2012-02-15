#include <cmath>
#include "tangent.h"
#include "../../../evaluator.h"

namespace RPN
{
	TangentNode::TangentNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double TangentNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return tan(arg);
	}
}

