#include <cmath>
#include "power.h"
#include "../../../evaluator.h"

namespace RPN
{
	PowerNode::PowerNode(): FunctionNode(2)
	{
		//Nothing else to do...
	}
	
	double PowerNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.back();
		evaluator.pop_back();
		double arg1 = evaluator.back();
		evaluator.pop_back();
		return pow(arg1, arg2);
	}
}

