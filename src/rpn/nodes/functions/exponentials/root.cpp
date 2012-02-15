#include <cmath>
#include "root.h"
#include "../../../evaluator.h"

namespace RPN
{
	RootNode::RootNode(): FunctionNode(2)
	{
		//Nothing else to do...
	}
	
	double RootNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.back();
		evaluator.pop_back();
		double arg1 = evaluator.back();
		evaluator.pop_back();
		return pow(arg1, 1.0 / arg2);
	}
}

