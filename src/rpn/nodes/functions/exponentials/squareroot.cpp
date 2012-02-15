#include <cmath>
#include "squareroot.h"
#include "../../../evaluator.h"

namespace RPN
{
	SquareRootNode::SquareRootNode(): FunctionNode(1)
	{
		//Nothing else to do...
	}
	
	double SquareRootNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.back();
		evaluator.pop_back();
		return pow(arg, 0.5);
	}
}

