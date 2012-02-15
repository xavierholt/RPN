#include <cmath>
#include "logarithm.h"
#include "../../../evaluator.h"

namespace RPN
{
	LogarithmNode::LogarithmNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double LogarithmNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.back();
		evaluator.pop_back();
		double arg1 = evaluator.back();
		evaluator.pop_back();
		return log(arg1) / log(arg2);
	}
}

