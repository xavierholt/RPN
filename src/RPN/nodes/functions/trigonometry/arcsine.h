#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCSINE_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCSINE_H

#include "../../function.h"

namespace RPN
{
	class ArcSineNode : public FunctionNode
	{
	public:
		ArcSineNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

