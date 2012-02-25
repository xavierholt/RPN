#ifndef RPN_NODE_H
#define RPN_NODE_H

#include "evaluator.h"
#include "parsers/all.h"

namespace RPN
{
	class Node
	{
	public:
		enum Type
		{
			BRACKET  = 0x01,
			FUNCTION = 0x02,
			OPERATOR = 0x04,
			VALUE    = 0x08
		};
		
	protected:
		mutable int mReferenceCount;
		
	public:
		virtual int    arguments() const;
		virtual void   dereference() const;
		virtual double evaluate(Evaluator& evaluator) const;
		virtual void   infixParse(InfixParser& parser, Parser::Token& token) const = 0;
		virtual Type   infixPresents() const = 0;
		virtual Type   infixSucceeds() const = 0;
		virtual bool   isVolatile() const;
		virtual void   reference() const;
		virtual Type   type() const = 0;
	};
}

#endif

