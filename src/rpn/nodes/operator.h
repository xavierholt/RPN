#ifndef RPN_NODES_OPERATOR_H
#define RPN_NODES_OPERATOR_H

#include "../node.h"

namespace RPN
{
	class Translator;
	
	class OperatorNode : public Node
	{
	public:
		enum Precedence
		{
			ADDITION = 100,
			SUBTRACTION = ADDITION,
			
			MULTIPLICATION = 200,
			DIVISION = MULTIPLICATION,
			MODULO = MULTIPLICATION,
			
			NEGATION = 300,
			
			EXPONENTIATION = 400,
			
			FACTORIAL = 500
		};
		
	public:
		virtual int  arguments() const;
		virtual bool isRightAssociative() const;
		virtual bool isOperator() const;
		virtual int  precedence() const = 0;
		virtual void translate(Translator& translator) const;
	};
}

#endif

