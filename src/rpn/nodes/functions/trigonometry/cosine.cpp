#include <cmath>
#include "cosine.h"
#include "../../../evaluator.h"

namespace RPN
{
	CosineNode::CosineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double CosineNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return cos(arg);
	}
}

