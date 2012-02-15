#include <cmath>
#include "naturallogarithm.h"
#include "../../../evaluator.h"

namespace RPN
{
	NaturalLogarithmNode::NaturalLogarithmNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double NaturalLogarithmNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return log(arg);
	}
}

