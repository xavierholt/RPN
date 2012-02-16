#include "variable.h"

namespace RPN
{
	VariableNode::VariableNode(const double* variable): mVariable(variable)
	{
		//Nothing else to do...
	}
	
	double VariableNode::evaluate(Evaluator& evaluator) const
	{
		(void)(evaluator); //Unused
		return *mVariable;
	}
}

