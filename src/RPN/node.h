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

