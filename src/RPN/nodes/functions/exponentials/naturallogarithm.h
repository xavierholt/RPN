#ifndef RPN_NODES_FUNCTIONS_EXPONENTIALS_NATURALLOGARITHM_H
#define RPN_NODES_FUNCTIONS_EXPONENTIALS_NATURALLOGARITHM_H

#include "../../function.h"

namespace RPN
{
	class NaturalLogarithmNode : public FunctionNode
	{
	public:
		NaturalLogarithmNode();
		
		virtual double evaluate(Evaluator& translator) const;
	};
}

#endif

