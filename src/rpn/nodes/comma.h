#ifndef RPN_NODES_COMMA_H
#define RPN_NODES_COMMA_H

#include "../node.h"

namespace RPN
{
	class CommaNode : public Node
	{
	public:
		virtual void infixParse(InfixParser& parser, Parser::Token& token) const;
		virtual Type infixPresents() const;
		virtual Type infixSucceeds() const;
		virtual Type type() const;
	};
}

#endif

