#include "../parsers/infix.h"
#include "comma.h"

namespace RPN
{
	void CommaNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		(void)(token); //Unused
		
		while(parser.hasStack())
		{
			if(parser.top().node->type() == Node::BRACKET)
			{
				return;
			}
			else
			{
				parser.shunt();
			}
		}
	}
	
	Node::Type CommaNode::infixPresents() const
	{
		return Node::OPERATOR;
	}
	
	Node::Type CommaNode::infixSucceeds() const
	{
		return Node::VALUE;
	}
	
	Node::Type CommaNode::type() const
	{
		//TODO: Is this correct?  Should there be a COMMA type?
		return Node::OPERATOR;
	}
}

