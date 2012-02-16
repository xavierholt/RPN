#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCSECANT_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCSECANT_H

#include "../../function.h"

namespace RPN
{
	class ArcSecantNode : public FunctionNode
	{
	public:
		ArcSecantNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

