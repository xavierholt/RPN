#ifndef RPN_NODES_BRACKETS_RIGHT_H
#define RPN_NODES_BRACKETS_RIGHT_H

#include "../bracket.h"

namespace RPN
{
	class RightBracketNode : public BracketNode
	{
	public:
		RightBracketNode(char opener, char closer);
		
		virtual void translate(Translator& translator) const;
	};
}

#endif

