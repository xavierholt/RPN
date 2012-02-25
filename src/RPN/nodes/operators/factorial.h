#ifndef RPN_NODES_OPERATORS_FACTORIAL_H
#define RPN_NODES_OPERATORS_FACTORIAL_H

#include "../operator.h"

namespace RPN
{
	class FactorialNode : public OperatorNode
	{
	protected:
		static const double cHelper[9];
		static double gamma(double x);
		
	public:
		FactorialNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

