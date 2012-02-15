#ifndef RPN_NODES_FUNCTIONS_EXPONENTIALS_SQUAREROOT_H
#define RPN_NODES_FUNCTIONS_EXPONENTIALS_SQUAREROOT_H

#include "../../function.h"

namespace RPN
{
	class SquareRootNode : public FunctionNode
	{
	public:
		SquareRootNode();
		
		virtual double evaluate(Evaluator& translator) const;
	};
}

#endif

