#include "division.h"

namespace RPN
{
	DivisionNode::DivisionNode(): OperatorNode()
	{
		//Nothing else to do...
	}
	
	double DivisionNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.back();
		evaluator.pop_back();
		double arg1 = evaluator.back();
		evaluator.pop_back();
		return (arg1 / arg2);
	}
	
	int DivisionNode::precedence() const
	{
		return OperatorNode::DIVISION;
	}
}

