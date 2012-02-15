#ifndef RPN_NODE_H
#define RPN_NODE_H

#include "evaluator.h"

namespace RPN
{
	class Translator;
	
	class Node
	{
	protected:
		mutable int mReferenceCount;
		
	public:
		virtual int    arguments() const;
		virtual void   dereference() const;
		virtual double evaluate(Evaluator& evaluator) const;
		virtual bool   isBracket() const;
		virtual bool   isFunction() const;
		virtual bool   isOperator() const;
		virtual void   reference() const;
		virtual void   translate(Translator& translator) const = 0;
	};
}

#endif

