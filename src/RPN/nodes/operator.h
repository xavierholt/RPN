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
	class Translator;
	
	class OperatorNode : public Node
	{
	public:
		enum Associativity
		{
			LEFT,
			RIGHT
		};
		
		enum Precedence
		{
			ADDITION = 100,
			SUBTRACTION = ADDITION,
			
			MULTIPLICATION = 200,
			DIVISION = MULTIPLICATION,
			MODULO = MULTIPLICATION,
			
			NEGATION = 300,
			
			EXPONENTIATION = 400,
			
			FACTORIAL = 500
		};
		
	public:
		int mArguments;
		int mAssociativity;
		int mPrecedence;
		
	public:
		OperatorNode(int precedence, Associativity associativity = LEFT, int arguments = 2);
		
		int  arguments() const;
		int  associativity() const;
		void infixParse(InfixParser& parser, Parser::Token& token) const;
		Type infixPresents() const;
		Type infixSucceeds() const;
		bool isLeftAssociative() const;
		bool isRightAssociative() const;
		int  precedence() const;
		Type type() const;
	};
}

#endif

