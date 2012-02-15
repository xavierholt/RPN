#ifndef RPN_NODES_FUNCTIONS_EXPONENTIALS_DECADICLOGARITHM_H
#define RPN_NODES_FUNCTIONS_EXPONENTIALS_DECADICLOGARITHM_H

#include "../../function.h"

namespace RPN
{
	class DecadicLogarithmNode : public FunctionNode
	{
	public:
		DecadicLogarithmNode();
		
		virtual double evaluate(Evaluator& translator) const;
	};
}

#endif

