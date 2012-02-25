#include "addition.h"

namespace RPN
{
	AdditionNode::AdditionNode(): OperatorNode(OperatorNode::ADDITION)
	{
		//Nothing else to do...
	}
	
	double AdditionNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.pop();
		double arg1 = evaluator.pop();
		return (arg1 + arg2);
	}
}

