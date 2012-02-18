#include "../parsers/infix.h"
#include "value.h"

namespace RPN
{
	int ValueNode::arguments() const
	{
		return 0;
	}
	
	void ValueNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		parser.push_to_expression(token);
	}
	
	Node::Type ValueNode::infixPresents() const
	{
		return Node::VALUE;
	}
	
	Node::Type ValueNode::infixSucceeds() const
	{
		return Node::OPERATOR;
	}
	
	Node::Type ValueNode::type() const
	{
		return Node::VALUE;
	}
}

