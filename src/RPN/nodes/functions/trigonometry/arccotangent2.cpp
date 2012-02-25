#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arccotangent2.h"

namespace RPN
{
	ArcCotangent2Node::ArcCotangent2Node(): FunctionNode(2)
	{
		//Nothing else to do...
	}
	
	double ArcCotangent2Node::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg2 = evaluator.pop();
		double arg1 = evaluator.pop();
		return atan2(arg2, arg1);
	}
}

