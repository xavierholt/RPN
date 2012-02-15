#include <cmath>
#include "exponentiation.h"

namespace RPN
{
	ExponentiationNode::ExponentiationNode(): OperatorNode()
	{
		//Nothing else to do...
	}
	
	bool ExponentiationNode::isRightAssociative() const
	{
		return true;
	}
	
	double ExponentiationNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.back();
		evaluator.pop_back();
		double arg1 = evaluator.back();
		evaluator.pop_back();
		return pow(arg1, arg2);
	}
	
	int ExponentiationNode::precedence() const
	{
		return OperatorNode::EXPONENTIATION;
	}
}

