#ifndef RPN_NODES_VALUE_H
#define RPN_NODES_VALUE_H

#include "../node.h"

namespace RPN
{
	class ValueNode : public Node
	{
	public:
		virtual int  arguments() const;
		virtual void infixParse(InfixParser& parser, Parser::Token& token) const;
		virtual Type infixPresents() const;
		virtual Type infixSucceeds() const;
		virtual Type type() const;
	};
}

#endif

