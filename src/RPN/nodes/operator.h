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
#ifndef RPN_NODES_OPERATOR_H
#define RPN_NODES_OPERATOR_H

#include "../node.h"

namespace RPN
{
/**
 * Base class for operator nodes.
 *
 * 
 */
	class OperatorNode : public Node
	{
	public:
/**
 * Operator precedence (addition < multiplication < exponentiation).
 */
		enum Precedence
		{
			ADDITION = 100,            ///< Addition
			SUBTRACTION = ADDITION,    ///< Subtraction
			
			MULTIPLICATION = 200,      ///< Multiplication
			DIVISION = MULTIPLICATION, ///< Division
			MODULO = MULTIPLICATION,   ///< Modulo
			
			NEGATION = 300,            ///< Negation
			
			EXPONENTIATION = 400,      ///< Exponentiation
			
			FACTORIAL = 500            ///< Factorial
		};
		
	public:
		int mPrecedence;          ///< The precedence of this operator in order of operations (addition < multiplication < exponentiation).
		bool mIsRightAssociative; ///< Whether or not this is a right-associative operator.
		bool mIsBinary;           ///< Whether or not this is a binary operator.
		
	public:
		OperatorNode(int precedence, bool right = false, bool binary = true);
		
		virtual int   arguments() const;
		virtual Flags flags() const;
		virtual void  infixParse(InfixParser& parser, Parser::Token& token) const;
		
		bool isLeftAssociative() const;
		bool isRightAssociative() const;
		int  precedence() const;
	};
}

#endif

