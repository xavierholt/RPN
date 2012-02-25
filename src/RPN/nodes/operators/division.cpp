#include "division.h"

namespace RPN
{
	DivisionNode::DivisionNode(): OperatorNode(OperatorNode::DIVISION)
	{
		//Nothing else to do...
	}
	
	double DivisionNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.pop();
		double arg1 = evaluator.pop();
		return (arg1 / arg2);
	}
}

