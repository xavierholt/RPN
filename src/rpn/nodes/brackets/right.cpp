#ifndef RPN_LIBHEADER
	#include <sstream>
#endif

#include "../../exception.h"
#include "../../translator.h"
#include "right.h"

namespace RPN
{
	RightBracketNode::RightBracketNode(char opener, char closer): BracketNode(opener, closer)
	{
		//Nothing else to do...
	}
	
	void RightBracketNode::translate(Translator& translator) const
	{
		while(translator.hasStack())
		{
			const Node* node = translator.pop();
			if(node->isBracket())
			{
				const BracketNode* bracket = (BracketNode*) node;
				if(bracket->isClosedBy(this))
				{
					if(translator.hasStack() && translator.top()->isFunction())
					{
						translator.shunt();
					}
					return;
				}
				else
				{
					std::stringstream mess;
					mess << "Bracket mismatch: Expected '" << bracket->closer() << "'; got '" << closer() << '\'';
					throw Exception(mess.str());
				}
			}
			else
			{
				translator.push_to_expression(node);
			}
		}
		
		std::stringstream mess;
		mess << "Bracket mismatch: Unmatched '" << closer() << '\'';
		throw Exception(mess.str());
	}
}

