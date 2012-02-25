#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "arcsecant.h"

namespace RPN
{
	ArcSecantNode::ArcSecantNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double ArcSecantNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return acos(1.0 / arg);
	}
}

