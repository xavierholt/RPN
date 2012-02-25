#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCCOSINE_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCCOSINE_H

#include "../../function.h"

namespace RPN
{
	class ArcCosineNode : public FunctionNode
	{
	public:
		ArcCosineNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

