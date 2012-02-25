#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arctangent2.h"

namespace RPN
{
	ArcTangent2Node::ArcTangent2Node(): FunctionNode(2)
	{
		//Nothing else to do...
	}
	
	double ArcTangent2Node::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg2 = evaluator.pop();
		double arg1 = evaluator.pop();
		return atan2(arg1, arg2);
	}
}

