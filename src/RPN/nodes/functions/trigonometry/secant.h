#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_SECANT_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_SECANT_H

#include "../../function.h"

namespace RPN
{
	class SecantNode : public FunctionNode
	{
	public:
		SecantNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

