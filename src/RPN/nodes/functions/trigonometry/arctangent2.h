#ifndef RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCTANGENT2_H
#define RPN_NODES_FUNCTIONS_TRIGONOMETRY_ARCTANGENT2_H

#include "../../function.h"

namespace RPN
{
	class ArcTangent2Node : public FunctionNode
	{
	public:
		ArcTangent2Node();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

