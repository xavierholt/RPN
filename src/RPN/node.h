/******************************************************************************
   Copyright 2012 Kevin Burk
   
   This file is part of RPN.
  
   RPN is free software: you can redistribute it and/or modify it under the
   terms of the GNU General Public License as published by the Free Software
   Foundation, either version 3 of the License, or (at your option) any later
   version.
  
   RPN is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
   details.
  
   You should have received a copy of the GNU General Public License along
   with RPN.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/
#ifndef RPN_NODE_H
#define RPN_NODE_H

#include "evaluator.h"
#include "parsers/all.h"

namespace RPN
{
/**
 * An individual conponent of an Expression.
 * A Node is a fundamental unit of on Expression.  Parsers turn strings into
 * arrays of Nodes; Expressions are mainly wrappers around these arrays; when
 * evaluating an Expression, each of its Nodes is evaluated sequentially.
 *
 * Nodes can represent values, functions, and operators.  Value nodes take no
 * arguments, and the result of their evaluation is pushed directly to the
 * value stack. Functions and operators both take arguments (which they pop off
 * the value stack during evaluation), but differ in that operator nodes are
 * subject to the rules of precedence and associativity when being parsed from
 * infix expressions.
 *
 * While nodes are critical to the operation of RPN, you will probably never
 * need to call any Node member functions yourself.  Use their constructors
 * when putting them into Contexts, and everything else will be handled
 * internally; you only need to deal with the much higher-level Expressions.
 *
 * @note Nodes are reference counted.  The reference counter is adjusted by
 * insertion and removal from Contexts and Expressions (but not from Parsers).
 * This allows Expressions to keep working even after the Contexts that created
 * them have been destroyed.  <i>This behaviour may change in future versions.</i>
 */
	class Node
	{
	public:
		enum Flags
		{
			BRACKET     = 0x0001,                  ///< This is a bracket node.
			FUNCTION    = 0x0002,                  ///< This is a function node.
			OPERATOR    = 0x0004,                  ///< This is an operator node, and subject to order of operations.
			VALUE       = 0x0008,                  ///< This is a value node - a variable or a constant.
			
			VOLATILE    = 0x0010,                  ///< The value of this node may change between evaluations.
			
			SUCCEEDS_OP = 0x0100,                  ///< This node expects to follow an operator.
			PRESENTS_OP = 0x0200,                  ///< This node presents an operator to the node that follows it.
			
			INFIX       = 0x1000,                  ///< This node can be a part of an infix expression.
			POSTFIX     = 0x2000,                  ///< This node can be a part of a postfix expression.
			PREFIX      = 0x4000,                  ///< This node can be a part of a prefix expression.
			ALLFIX      = INFIX | POSTFIX | PREFIX ///< This node can be a part of any style of expression.
		};
		
	protected:
		mutable int mReferenceCount; ///< The number of Contexts and Expressions referring to this node.
		
	public:
		Node();
		
		virtual int    arguments() const;
		virtual double evaluate(Evaluator& evaluator) const;
		virtual void   infixParse(InfixParser& parser, Parser::Token& token) const = 0;
		virtual Flags  flags() const = 0;
		
		inline void dereference() const     {if(--mReferenceCount == 0) delete this;}
		inline bool isBracket() const       {return flags() & BRACKET;}
		inline bool isFunction() const      {return flags() & FUNCTION;}
		inline bool isInfix() const         {return flags() & INFIX;}
		inline bool isOperator() const      {return flags() & OPERATOR;}
		inline bool isPostfix() const       {return flags() & POSTFIX;}
		inline bool isPrefix() const        {return flags() & PREFIX;}
		inline bool isValue() const         {return flags() & VALUE;}
		inline bool isVolatile() const      {return flags() & VOLATILE;}
		inline void reference() const       {++mReferenceCount;}
		inline bool succeeds(Flags f) const {return (~(flags() ^ (f >> 1))) & SUCCEEDS_OP;}
	};
}

#endif

