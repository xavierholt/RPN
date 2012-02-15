#ifndef RPN_NODES_FUNCTIONS_EXPONENTIALS_BINARYLOGARITHM_H
#define RPN_NODES_FUNCTIONS_EXPONENTIALS_BINARYLOGARITHM_H

#include "../../function.h"

namespace RPN
{
	class BinaryLogarithmNode : public FunctionNode
	{
	public:
		BinaryLogarithmNode();
		
		virtual double evaluate(Evaluator& translator) const;
	};
}

#endif

