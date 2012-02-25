#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCCOTANGENT_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCCOTANGENT_H

#include "../../function.h"

namespace RPN
{
	class ArcCotangentNode : public FunctionNode
	{
	public:
		ArcCotangentNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

