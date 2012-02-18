#ifndef RPN_NODES_BRACKET_H
#define RPN_NODES_BRACKET_H

#include "../node.h"

namespace RPN
{
	class BracketNode : public Node
	{
	protected:
		char mCloser;
		char mOpener;
		
	public:
		BracketNode(char opener, char closer);
		
		char closer() const;
		char opener() const;
		bool isClosedBy(const BracketNode* other) const;
		Type type() const;
	};
}

#endif

