#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_COSECANT_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_COSECANT_H

#include "../../function.h"

namespace RPN
{
	class CosecantNode : public FunctionNode
	{
	public:
		CosecantNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

