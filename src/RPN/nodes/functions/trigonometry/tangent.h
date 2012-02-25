#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_TANGENT_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_TANGENT_H

#include "../../function.h"

namespace RPN
{
	class TangentNode : public FunctionNode
	{
	public:
		TangentNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

