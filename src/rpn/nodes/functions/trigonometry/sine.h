#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_SINE_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_SINE_H

#include "../../function.h"

namespace RPN
{
	class SineNode : public FunctionNode
	{
	public:
		SineNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

