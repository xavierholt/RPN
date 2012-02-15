#ifndef RPN_NODES_FUNCTIONS_EXPONENTIALS_POWER_H
#define RPN_NODES_FUNCTIONS_EXPONENTIALS_POWER_H

#include "../../function.h"

namespace RPN
{
	class PowerNode : public FunctionNode
	{
	public:
		PowerNode();
		
		virtual double evaluate(Evaluator& translator) const;
	};
}

#endif

