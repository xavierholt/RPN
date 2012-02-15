#include <cmath>
#include "modulo.h"

namespace RPN
{
	ModuloNode::ModuloNode(): OperatorNode()
	{
		//Nothing else to do...
	}
	
	double ModuloNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.back();
		evaluator.pop_back();
		double arg1 = evaluator.back();
		evaluator.pop_back();
		return fmod(arg1, arg2);
	}
	
	int ModuloNode::precedence() const
	{
		return OperatorNode::MODULO;
	}
}

