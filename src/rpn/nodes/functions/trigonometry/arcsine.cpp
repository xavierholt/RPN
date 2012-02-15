#include <cmath>
#include "arcsine.h"
#include "../../../evaluator.h"

namespace RPN
{
	ArcSineNode::ArcSineNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double ArcSineNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return asin(arg);
	}
}

