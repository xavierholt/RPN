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
#ifndef RPN_LIBHEADER
	#include <sstream>
#endif

#include "exception.h"
#include "expression.h"
#include "evaluator.h"
#include "node.h"
#include "parsers/all.h"

namespace RPN
{
/**
 * Default constructor.
 * This constructor doesn't actually do anything; use it if you want to create
 * an Expression, but don't have anything to fill it with yet.  Call parse()
 * once you do to load something into the Expression and get it ready to
 * evaluate().
 */
	Expression::Expression()
	{
		//Nothing to do...
	}
	
/**
 * Convenience constructor.
 * @param string A string to parse into the newly created expression.
 * @param context The Context in which to do the parsing.
 * @param arguments The number of arguments expected by this expression (defaults to zero).
 * @param format The "fixity" of the input string (defaults to INFIX).
 *
 * This constructor creates an Expression and parses a string into it in one
 * function call.  As long as parsing was successful, you can evaluate() the
 * Expression immediately after using this constructor.
 */
	Expression::Expression(const std::string& string, const RPN::Context& context, int arguments, Format format)
	{
		parse(string, context, arguments, format);
	}
	
/**
 * Destructor.
 * Dereferences all the Nodes used in this expression.
 */
	Expression::~Expression()
	{
		clear();
	}
	
/**
 * Gets the number or arguments this expression expects.
 * @return The number of expected arguments.
 */
	int Expression::arguments() const
	{
		return mArguments;
	}
	
/**
 * Clears this expression.
 * Dereferences and removes all Nodes, and resets caching information.
 *
 * You probably won't have any need to call this function yourself; it's used
 * internally to prepare an expression for a new parsing.
 */
	void Expression::clear()
	{
		for(std::vector<const Node*>::const_iterator i = mStack.begin(); i != mStack.end(); ++i)
		{
			(*i)->dereference();
		}
		
		mStack.clear();
		mIsCached = false;
		mIsVolatile = false;
	}
	
/**
 * Evaluates this expression.
 * @return The result of evaluation.
 *
 * A convenience wrapper around the evaluate function that does all the work.
 * Creates an empty Evaluator internally, uses it, and discards it.
 *
 * [evaluate disclaimer]
 * Programs that perform lots of evaluations may want to create an Evaluator
 * per thread and pass that to evaluate(Evaluator&).  This avoids the memory
 * management overhead involved in creating and destroying std::vectors.
 * [evaluate disclaimer]
 */
	double Expression::evaluate() const
	{
		if(mIsCached)
		{
			return mResult;
		}
		
		Evaluator evaluator;
		return evaluate(evaluator);
	}
	
/**
 * Evaluates this expression.
 * @param arg1 An argument, to be passed to this expression.
 * @return The result of evaluation.
 *
 * A convenience wrapper around the evaluate function that does all the work.
 * Creates an Evaluator internally, pushes on any arguments, uses it, and
 * discards it.
 *
 * @snippet expression.cpp evaluate disclaimer
 */
	double Expression::evaluate(double arg1) const
	{
		Evaluator evaluator;
		evaluator.push(arg1);
		return evaluate(evaluator);
	}
	
/**
 * Evaluates this expression.
 * @param arg1 An argument, to be passed to this expression.
 * @param arg2 Another argument to be passed to this expression.
 * @return The result of evaluation.
 *
 * A convenience wrapper around the evaluate function that does all the work.
 * Creates an Evaluator internally, pushes on any arguments, uses it, and
 * discards it.
 *
 * @snippet expression.cpp evaluate disclaimer
 */
	double Expression::evaluate(double arg1, double arg2) const
	{
		Evaluator evaluator;
		evaluator.push(arg1);
		evaluator.push(arg2);
		return evaluate(evaluator);
	}
	
	double Expression::evaluate(double arg1, double arg2, double arg3) const
	{
		Evaluator evaluator;
		evaluator.push(arg1);
		evaluator.push(arg2);
		evaluator.push(arg3);
		return evaluate(evaluator);
	}
	
	double Expression::evaluate(Evaluator& evaluator) const
	{
		if(mStack.size() < 1)
		{
			throw Exception("Attempted to evaluate an uninitialized expression.");
			return 0.0;
		}
		
		if(mIsCached)
		{
			return mResult;
		}
		
		evaluator.bind();
		evaluator.reserve(mMaxAvailable);
		
		for(std::vector<const Node*>::const_iterator i = mStack.begin(); i != mStack.end(); ++i)
		{
			evaluator.push((*i)->evaluate(evaluator));
		}
		
		double ret = evaluator.pop();
		evaluator.release();
		
		if(!mIsVolatile)
		{
			mResult = ret;
			mIsCached = true;
		}
		
		for(int i = mArguments; i > 0; --i)
		{
			evaluator.pop();
		}
		
		return ret;
	}
	
	void Expression::parse(const std::string& string, const Context& context, int arguments, Format format)
	{
		//NOTE:  This has to be an if/else block - g++ complains about "jump to
		//       case label crosses initialization of Blah" if we use a switch.
		if(format == INFIX)
		{
			InfixParser parser(string, context);
			parser.store(*this);
		}
		else if(format == POSTFIX)
		{
			PostfixParser parser(string, context);
			parser.store(*this);
		}
		else
		{
			std::ostringstream mess;
			mess << "Unknown format: " << format;
			throw Exception(mess.str());
		}
		
		mArguments = arguments;
	}
	
	Expression& Expression::operator <<(const Node* node)
	{
		node->reference();
		mStack.push_back(node);
		mIsVolatile |= node->isVolatile();
		return *this;
	}
}

