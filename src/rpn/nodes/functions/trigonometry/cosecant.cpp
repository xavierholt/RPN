#ifndef RPN_LIBHEADER
	#include <cmath>
#endif

#include "cosecant.h"

namespace RPN
{
	CosecantNode::CosecantNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double CosecantNode::evaluate(RPN::Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return 1.0 / sin(arg);
	}
}

