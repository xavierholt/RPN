#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCCOSECANT_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCCOSECANT_H

#include "../../function.h"

namespace RPN
{
	class ArcCosecantNode : public FunctionNode
	{
	public:
		ArcCosecantNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

