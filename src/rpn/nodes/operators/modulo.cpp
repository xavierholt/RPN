#include <cmath>
#include "modulo.h"

namespace RPN
{
	ModuloNode::ModuloNode(): OperatorNode(OperatorNode::MODULO)
	{
		//Nothing else to do...
	}
	
	double ModuloNode::evaluate(Evaluator& evaluator) const
	{
		double arg2 = evaluator.pop();
		double arg1 = evaluator.pop();
		return fmod(arg1, arg2);
	}
}

