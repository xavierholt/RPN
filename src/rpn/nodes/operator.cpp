#include "operator.h"
#include "../translator.h"

namespace RPN
{
	OperatorNode::OperatorNode(int precedence, Associativity associativity, int arguments):
		mArguments(arguments),
		mAssociativity(associativity),
		mPrecedence(precedence)
	{
		//Nothing else to do...
	}
	
	int OperatorNode::arguments() const
	{
		return mArguments;
	}
	
	int OperatorNode::associativity() const
	{
		return mAssociativity;
	}
	
	bool OperatorNode::isRightAssociative() const
	{
		return (mAssociativity != LEFT);
	}
	
	bool OperatorNode::isOperator() const
	{
		return true;
	}
	
	int OperatorNode::precedence() const
	{
		return mPrecedence;
	}
	
	void OperatorNode::translate(Translator& translator) const
	{
		int comp = precedence() - isRightAssociative();
		
		while(translator.hasStack())
		{
			const Node* node = translator.top();
			if(node->isOperator() && ((const OperatorNode*)node)->precedence() >= comp)
			{
				translator.shunt();
			}
			else
			{
				break;
			}
		}
		
		translator.push_to_stack(this);
	}
}

