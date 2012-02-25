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
#ifndef RPN_PARSER_H
#define RPN_PARSER_H

#ifndef RPN_LIBHEADER
	#include <string>
	#include <vector>
#endif

namespace RPN
{
	class Context;
	class Expression;
	class Node;
	
	class Parser
	{
	public:
		class Token
		{
		public:
			std::string name;
			const Node* node;
			
		public:
			Token();
			Token(const std::string& name, const Node* node);
			Token& operator =(const Token& other);
		};
		
	public:
		enum TokenType
		{
			BLANK       = 0x01,
			BRACKET     = 0x02,
			NUMBER      = 0x04,
			IDENTIFIER  = 0x08,
			OPERATOR    = 0x10
		};
		
	public:
		const static unsigned char cInitial[256];
		const static unsigned char cSubsequent[256];
		
	protected:
		int                      mAvailable;
		int                      mMaxAvailable;
		const Context&           mContext;
		std::vector<const Node*> mExpression;
		
	public:
		Parser(const Context& context);
		
		void         checkResult();
		Token        next(std::string::const_iterator& itr, std::string::const_iterator& end);
		virtual void parse(const std::string& string) = 0;
		void         push_to_expression(Token& token);
		void         reset();
		void         store(Expression& expression);
	};
}

#endif

