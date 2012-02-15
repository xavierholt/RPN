#include <cmath>
#include "sine.h"
#include "../../../evaluator.h"

namespace RPN
{
	SineNode::SineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double SineNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return sin(arg);
	}
}

