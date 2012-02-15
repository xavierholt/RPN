#include <cmath>
#include "decadiclogarithm.h"
#include "../../../evaluator.h"

namespace RPN
{
	DecadicLogarithmNode::DecadicLogarithmNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double DecadicLogarithmNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return log10(arg);
	}
}

