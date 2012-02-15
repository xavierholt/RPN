#ifndef RPN_NODES_VALUE_H
#define RPN_NODES_VALUE_H

#include "../node.h"

namespace RPN
{
	class ValueNode : public Node
	{
	public:
		virtual int    arguments() const;
		virtual void   translate(Translator& translator) const;
		virtual double value() const = 0;
	};
}

#endif

