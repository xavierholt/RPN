#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCCOTANGENT2_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCCOTANGENT2_H

#include "../../function.h"

namespace RPN
{
	class ArcCotangent2Node : public FunctionNode
	{
	public:
		ArcCotangent2Node();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

