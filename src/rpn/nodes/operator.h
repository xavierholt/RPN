#ifndef RPN_NODES_OPERATOR_H
#define RPN_NODES_OPERATOR_H

#include "../node.h"

namespace RPN
{
	class Translator;
	
	class OperatorNode : public Node
	{
	public:
		enum Associativity
		{
			LEFT,
			RIGHT
		};
		
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
		int mArguments;
		int mAssociativity;
		int mPrecedence;
		
	public:
		OperatorNode(int precedence, Associativity associativity = LEFT, int arguments = 2);
		
		virtual int  arguments() const;
		virtual int  associativity() const;
		virtual bool isOperator() const;
		virtual bool isRightAssociative() const;
		virtual int  precedence() const;
		virtual void translate(Translator& translator) const;
	};
}

#endif

