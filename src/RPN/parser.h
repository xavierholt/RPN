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

#include "context.h"

namespace RPN
{
	class Expression;
	class Node;
	
/**
 * The base class from which all parsers inherit.
 * Reimplementations of this class must implement the parseInternal() function,
 * which does the actual parsing. If they use any extra class members to help
 * with parsing, they should reimplement the clear() function as well to make
 * sure that all necessary data is cleared before restarting parsing.
 *
 * @note This class is not reentrant.  If you want to parse multiple
 * expressions simultaneously, use multiple parsers.
 */
	class Parser
	{
	public:
/**
 * A token, as parsed from an input expression string.
 * This class is used for temporary storage during parsing.  It stores both the
 * RPN::Node and the input string that yielded it, allowing for more lucid
 * error reporting.
 */
		class Token
		{
		public:
			std::string name; ///< The name of this token, as it appeared in the input.
			const Node* node; ///< The RPN::Node associated with that name in the current context.
			
		public:
			Token();
			Token(const std::string& name, const Node* node);
			Token& operator =(const Token& other);
		};
		
	public:
/**
 * Token type flags.
 * Or'd combinations of these flags are stored in the static arrays cInitial[]
 * and cSubsequent[] to help parse input expressions into tokens.
 */
		enum TokenType
		{
			BLANK       = 0x01, ///< This token is whitespace.  Ignore it.
			BRACKET     = 0x02, ///< This token is an opening or closing bracket.
			NUMBER      = 0x04, ///< This token is a numeric constant.
			IDENTIFIER  = 0x08, ///< This token is the name of a function or variable.
			OPERATOR    = 0x10  ///< This token is an operator (or a comma).
		};
		
	public:
		const static unsigned char cInitial[256];    ///< An or'd combination of TokenType flags. The valid characters for starting each token type.
		const static unsigned char cSubsequent[256]; ///< An or'd combination of TokenType flags. The valid characters for continuing each token type.
		
	protected:
		int                         mAvailable;    ///< The number of values that would be present on the stack at this point as the expression is evaluated.
		int                         mMaxAvailable; ///< The maximum number of values that accumulate on the stack during evaluation.
		const Context*              mContext;      ///< The current context.
		std::vector<const Node*>    mExpression;   ///< Storage space for the expression being parsed.
		std::string                 mInputString;  ///< The input string.
		std::string::const_iterator mIterator;     ///< An iterator to the current point of tokenization.
		std::string::const_iterator mEndIterator;  ///< The "end" iterator for the input string.
		
	protected:
		virtual void clear();
		
/**
 * Performs the actual parsing.
 * This function is a pure virtual hook - all reimplementations of RPN::Parser
 * must implement this function.  When this function returns, an expression
 * must be sitting on the expression stack (\p mExpression), ready for storage
 * into an RPN::Expression.  If any parsing errors occur, this function should
 * throw an RPN::Exception.
 */
		virtual void parseInternal() = 0;
		
	public:
		Parser(const Context& context = Context::ROOT);
		
		void  checkResult();
		Token next();
		void  parse(const std::string& string);
		void  parse(const std::string& string, const Context& context);
		void  push_to_expression(Token& token);
		void  store(Expression& expression);
	};
}

#endif

