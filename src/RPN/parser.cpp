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
	#include <cstdlib>
	#include <sstream>
#endif

#include "context.h"
#include "exception.h"
#include "expression.h"
#include "nodes/values/constant.h"
#include "parser.h"

namespace RPN
{
	typedef std::vector<const Node*>::iterator EItr;
	typedef std::vector<const Node*>::const_iterator ECItr;
	
	Parser::Token::Token(): name(""), node(NULL)
	{
		//Nothing else to do...
	}
	
	Parser::Token::Token(const std::string& name, const Node* node): name(name), node(node)
	{
		//Nothing else to do...
	}
	
	Parser::Token& Parser::Token::operator =(const Parser::Token& other)
	{
		name = other.name;
		node = other.node;
		return *this;
	}
	
	Parser::Parser(const Context& context): mContext(&context)
	{
		//Nothing else to do...
	}
	
	void Parser::checkResult()
	{
		if(mAvailable != 1)
		{
			std::ostringstream mess;
			//TODO: Clarify this error message:
			mess << "Invalid expression: Expected 1 result; got " << mAvailable;
			throw Exception(mess.str());
		}
	}
	
	Parser::Token Parser::next(std::string::const_iterator& itr, std::string::const_iterator& end)
	{
		//Skip any whitespace...
		while(cInitial[(int) *itr] & BLANK)
		{
			++itr;
		}
		
		//Make sure it's not the end of the string...
		if(itr == end)
		{
			return Parser::Token();
		}
		
		//What token type starts like this?
		char type = cInitial[(int) *itr];
		
		//Make sure it's a valid token starter...
		if(!type)
		{
			std::ostringstream mess("Unprocessable character: '");
			mess << *itr << "' (" << (int) *itr << ")";
			throw Exception(mess.str());
		}
		
		//Read the rest of the token...
		Parser::Token token;
		do
		{
			token.name.push_back(*itr);
			if(++itr == end)
			{
				break;
			}
		}
		while(cSubsequent[(int) *itr] & type);
		
		//Look it up (or make it)...
		switch(type)
		{
		case NUMBER:
			token.node = new ConstantNode(strtod(token.name.c_str(), NULL));
			break;
		default:
			token.node = mContext->lookup(token.name);
			if(token.node == NULL)
			{
				std::ostringstream mess;
				mess << "Unrecognized name: \"" << token.name << '"';
				throw Exception(mess.str());
			}
		}
		
		return token;
	}
	
	void Parser::parse(const std::string& string)
	{
		parseInternal(string);
	}
	
	void Parser::parse(const std::string& string, const Context& context)
	{
		mContext = &context;
		parseInternal(string);
	}
	
	void Parser::push_to_expression(Parser::Token& token)
	{
		int args = token.node->arguments();
		if(mAvailable < args)
		{
			std::ostringstream mess;
			mess << "Too few arguments to \"" << token.name << "\": expected " << args << "; got " << mAvailable;
			throw Exception(mess.str());
		}
		
		mAvailable -= (args - 1);
		if(mAvailable > mMaxAvailable)
		{
			mMaxAvailable = mAvailable;
		}
		
		mExpression.push_back(token.node);
	}
	
	void Parser::reset()
	{
		mAvailable = 0;
		mMaxAvailable = 0;
		mExpression.clear();
	}
	
	void Parser::store(Expression& expression)
	{
		expression.clear();
		
		EItr end = mExpression.end();
		for(EItr i = mExpression.begin(); i != end; ++i)
		{
			expression << *i;
		}
		
		expression.mMaxAvailable = mMaxAvailable;
	}
}
