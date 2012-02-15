#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCTANGENT_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCTANGENT_H

#include "../../function.h"

namespace RPN
{
	class ArcTangentNode : public FunctionNode
	{
	public:
		ArcTangentNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

