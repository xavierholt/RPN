#include "function.h"
#include "../translator.h"

namespace RPN
{
	FunctionNode::FunctionNode(int args): mArguments(args)
	{
		//Nothing else to do...
	}
	
	int FunctionNode::arguments() const
	{
		return mArguments;
	}
	
	void FunctionNode::translate(RPN::Translator& translator) const
	{
		translator.push_to_stack(this);
	}
}

