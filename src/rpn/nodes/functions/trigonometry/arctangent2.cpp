#include <cmath>
#include "arctangent2.h"
#include "../../../evaluator.h"

namespace RPN
{
	ArcTangent2Node::ArcTangent2Node(): FunctionNode(2)
	{
		//Nothing else to do...
	}
	
	double ArcTangent2Node::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg2 = evaluator.back();
		evaluator.pop_back();
		double arg1 = evaluator.back();
		evaluator.pop_back();
		return atan2(arg1, arg2);
	}
}

