#include "subtraction.h"

namespace RPN
{
	SubtractionNode::SubtractionNode(): OperatorNode()
	{
		//Nothing else to do...
	}
	
	double SubtractionNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.back();
		evaluator.pop_back();
		double arg1 = evaluator.back();
		evaluator.pop_back();
		return (arg1 - arg2);
	}
	
	int SubtractionNode::precedence() const
	{
		return OperatorNode::SUBTRACTION;
	}
}

