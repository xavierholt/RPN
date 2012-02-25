#ifndef RPN_NODES_FUNCTIONS_EXPONENTIALS_LOGARITHM_H
#define RPN_NODES_FUNCTIONS_EXPONENTIALS_LOGARITHM_H

#include "../../function.h"

namespace RPN
{
	class LogarithmNode : public FunctionNode
	{
	public:
		LogarithmNode();
		
		virtual double evaluate(Evaluator& translator) const;
	};
}

#endif

