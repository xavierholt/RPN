#include "left.h"
#include "../../parsers/infix.h"

namespace RPN
{
	LeftBracketNode::LeftBracketNode(char opener, char closer): BracketNode(opener, closer)
	{
		//Nothing else to do...
	}
	
	void LeftBracketNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		parser.push_to_stack(token);
	}
	
	Node::Type LeftBracketNode::infixPresents() const
	{
		return Node::OPERATOR;
	}
	
	Node::Type LeftBracketNode::infixSucceeds() const
	{
		return Node::OPERATOR;
	}
}

