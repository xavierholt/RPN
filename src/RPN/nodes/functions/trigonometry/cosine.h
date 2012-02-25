#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_COSINE_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_COSINE_H

#include "../../function.h"

namespace RPN
{
	class CosineNode : public FunctionNode
	{
	public:
		CosineNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

