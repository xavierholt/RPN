#include "addition.h"

namespace RPN
{
	AdditionNode::AdditionNode(): OperatorNode()
	{
		//Nothing else to do...
	}
	
	double AdditionNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.back();
		evaluator.pop_back();
		double arg1 = evaluator.back();
		evaluator.pop_back();
		return (arg1 + arg2);
	}
	
	int AdditionNode::precedence() const
	{
		return OperatorNode::ADDITION;
	}
}

