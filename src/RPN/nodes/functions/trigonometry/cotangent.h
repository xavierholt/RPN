#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_COTANGENT_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_COTANGENT_H

#include "../../function.h"

namespace RPN
{
	class CotangentNode : public FunctionNode
	{
	public:
		CotangentNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

