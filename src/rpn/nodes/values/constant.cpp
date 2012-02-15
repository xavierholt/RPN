#include "constant.h"

namespace RPN
{
	ConstantNode::ConstantNode(double value): mValue(value)
	{
		//Nothing else to do...
	}
	
	double ConstantNode::evaluate(Evaluator& evaluator) const
	{
		(void)(evaluator); //Unused
		return mValue;
	}
	
	double ConstantNode::value() const
	{
		return mValue;
	}
}

