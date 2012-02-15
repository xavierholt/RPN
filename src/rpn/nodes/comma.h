#ifndef RPN_NODES_COMMA_H
#define RPN_NODES_COMMA_H

#include "../node.h"

namespace RPN
{
	class CommaNode : public Node
	{
	public:
		virtual void translate(Translator& translator) const;
	};
}

#endif

