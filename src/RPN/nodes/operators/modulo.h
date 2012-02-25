#ifndef RPN_NODES_OPERATORS_MODULO_H
#define RPN_NODES_OPERATORS_MODULO_H

#include "../operator.h"

namespace RPN
{
	class ModuloNode : public OperatorNode
	{
	public:
		ModuloNode();
		
		virtual double evaluate(Evaluator& evaluator) const;
	};
}

#endif

