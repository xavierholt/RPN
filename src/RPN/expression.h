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
#ifndef RPN_EXPRESSION_H
#define RPN_EXPRESSION_H

#ifndef RPN_LIBHEADER
	#include <string>
	#include <vector>
#endif

#include "context.h"
#include "evaluator.h"

namespace RPN
{
	class Node;
	
/**
 * Holds an expression and evaluates it.
 * The most important class in RPN.  Everything you do with the library
 * revolves around creating and evaluating expressions.
 *
 * Create an expression with the convenience constructor, or with the default
 * constructor, followed by a call to parse().  Replace the contents of the
 * expression with subsequent calls to parse().  Get the result of evaluating
 * the expression with whichever version of evaluate() fits your needs.
 *
 * Expressions can be nested within other expressions through the use of the
 * ExpressionNode.
 */
	class Expression 
	{
	public:
/**
 * The format ("fixity") of an expression.
 * Used to select the correct parser.
 */
		enum Format
		{
			INFIX,  ///< Infix (3 + 4).
			POSTFIX ///< Postfix (3 4 +).
		};
		
	protected:
		std::vector<const Node*> mStack;        ///< Holds the nodes that make up this expression.
		mutable double           mResult;       ///< Caches the result of evaluating a constant expression.
		int                      mArguments;    ///< The number of arguments this expression expects.
		int                      mMaxAvailable; ///< The (approximate) maximum number of values on the value stack during evaluation.
		mutable bool             mIsCached;     ///< Whether or not this expression is constant, and has had its result calculated already.
		mutable bool             mIsVolatile;   ///< Whether or not this expression can change between evaluations.
		
	public:
		Expression();
		Expression(const std::string& string, const Context& context = Context::ROOT, int arguments = 0, Format format = INFIX);
		~Expression();
		
		int    arguments() const;
		void   clear();
		double evaluate() const;
		double evaluate(double arg1) const;
		double evaluate(double arg1, double arg2) const;
		double evaluate(double arg1, double arg2, double arg3) const;
		double evaluate(Evaluator& evaluator) const;
		void   parse(const std::string& string, const Context& context = Context::ROOT, int arguments = 0, Format format = INFIX);
		
		Expression& operator <<(const Node* node);
		
		friend class Parser;
	};
}

#endif

