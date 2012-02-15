#include "../translator.h"
#include "value.h"

namespace RPN
{
	int ValueNode::arguments() const
	{
		return 0;
	}
	
	void ValueNode::translate(Translator& translator) const
	{
		translator.push_to_expression(this);
	}
}

