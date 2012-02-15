#include "operator.h"
#include "../translator.h"

namespace RPN
{
	int OperatorNode::arguments() const
	{
		return 2;
	}
	
	bool OperatorNode::isRightAssociative() const
	{
		return false;
	}
	
	bool OperatorNode::isOperator() const
	{
		return true;
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

