#include "negation.h"

namespace RPN
{
	NegationNode::NegationNode(): OperatorNode(OperatorNode::NEGATION, OperatorNode::RIGHT, 1)
	{
		//Nothing else to do...
	}
	
	double NegationNode::evaluate(Evaluator& evaluator) const
	{
		double arg = evaluator.pop();
		return -arg;
	}
}

