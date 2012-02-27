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
	class Node
	{
	public:
		enum Flags
		{
			BRACKET     = 0x0001,
			FUNCTION    = 0x0002,
			OPERATOR    = 0x0004,
			VALUE       = 0x0008,
			
			VOLATILE    = 0x0010,
			
			SUCCEEDS_OP = 0x0100,
			PRESENTS_OP = 0x0200,
			
			INFIX       = 0x1000,
			POSTFIX     = 0x2000,
			PREFIX      = 0x4000,
			ALLFIX      = INFIX | POSTFIX | PREFIX
		};
		
	protected:
		mutable int mReferenceCount;
		
	public:
		virtual int    arguments() const;
		virtual double evaluate(Evaluator& evaluator) const;
		virtual void   infixParse(InfixParser& parser, Parser::Token& token) const = 0;
		virtual Flags  flags() const = 0;
		
		inline void dereference() const     {if(--mReferenceCount <= 0) delete this;}
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

