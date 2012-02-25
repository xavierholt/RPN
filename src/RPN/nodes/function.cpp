#include "function.h"
#include "../parsers/infix.h"

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
	
	void FunctionNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		parser.push_to_stack(token);
	}
	
	Node::Type FunctionNode::infixPresents() const
	{
		return Node::OPERATOR;
	}
	
	Node::Type FunctionNode::infixSucceeds() const
	{
		return Node::OPERATOR;
	}
	
	Node::Type FunctionNode::type() const
	{
		return Node::FUNCTION;
	}
}

