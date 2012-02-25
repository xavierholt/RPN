#include "multiplication.h"

namespace RPN
{
	MultiplicationNode::MultiplicationNode(): OperatorNode(OperatorNode::MULTIPLICATION)
	{
		//Nothing else to do...
	}
	
	double MultiplicationNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.pop();
		double arg1 = evaluator.pop();
		return (arg1 * arg2);
	}
}

