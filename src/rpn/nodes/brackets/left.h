#ifndef RPN_NODES_BRACKETS_LEFT_H
#define RPN_NODES_BRACKETS_LEFT_H

#include "../bracket.h"

namespace RPN
{
	class LeftBracketNode : public BracketNode
	{
	public:
		LeftBracketNode(char opener, char closer);
		
		virtual void translate(Translator& translator) const;
	};
}

#endif

