#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arccosecant.h"

namespace RPN
{
	ArcCosecantNode::ArcCosecantNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double ArcCosecantNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return asin(1.0 / arg);
	}
}

