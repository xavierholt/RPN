#ifndef RPN_LIBHEADER
	#include <sstream>
#endif

#include "../../exception.h"
#include "../../parsers/infix.h"
#include "right.h"

namespace RPN
{
	RightBracketNode::RightBracketNode(char opener, char closer): BracketNode(opener, closer)
	{
		//Nothing else to do...
	}
	
	void RightBracketNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		(void)(token); //Unused
		
		while(parser.hasStack())
		{
			Parser::Token tmp = parser.pop();
			const Node* node = tmp.node;
			
			if(node->type() == Node::BRACKET)
			{
				const BracketNode* bracket = (BracketNode*) node;
				
				if(bracket->isClosedBy(this))
				{
					if(parser.hasStack() && parser.top().node->type() == Node::FUNCTION)
					{
						parser.shunt();
					}
					return;
				}
				else
				{
					std::ostringstream mess;
					mess << "Bracket mismatch: Expected '" << bracket->closer() << "'; got '" << closer() << '\'';
					throw Exception(mess.str());
				}
			}
			else
			{
				parser.push_to_expression(tmp);
			}
		}
		
		std::ostringstream mess;
		mess << "Bracket mismatch: Unmatched '" << closer() << '\'';
		throw Exception(mess.str());
	}
	
	Node::Type RightBracketNode::infixPresents() const
	{
		return Node::VALUE;
	}
	
	Node::Type RightBracketNode::infixSucceeds() const
	{
		return Node::VALUE;
	}
}

