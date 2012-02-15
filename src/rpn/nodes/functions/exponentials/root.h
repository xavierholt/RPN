#ifndef RPN_NODES_FUNCTIONS_EXPONENTIALS_ROOT_H
#define RPN_NODES_FUNCTIONS_EXPONENTIALS_ROOT_H

#include "../../function.h"

namespace RPN
{
	class RootNode : public FunctionNode
	{
	public:
		RootNode();
		
		virtual double evaluate(Evaluator& translator) const;
	};
}

#endif

