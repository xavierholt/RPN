#include "subtraction.h"

namespace RPN
{
	SubtractionNode::SubtractionNode(): OperatorNode(OperatorNode::SUBTRACTION)
	{
		//Nothing else to do...
	}
	
	double SubtractionNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.pop();
		double arg1 = evaluator.pop();
		return (arg1 - arg2);
	}
}

