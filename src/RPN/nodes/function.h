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
#ifndef RPN_NODES_FUNCTION_H
#define RPN_NODES_FUNCTION_H

#include "../node.h"

namespace RPN
{
/**
 * Base class for all functions.
 *
 * Function nodes differ from operator nodes in the following respects:  They
 * always precede their arguments in infix expressions, they can take any
 * (fixed) number of arguments, and they are not affected by order of
 * operations.
 *
 * Inherit from this class to create any functions you need that didn't come
 * as built-ins.  Pass the number of arguments your function expects to the
 * constructor (no variadic functions - sorry), and reimplement the evaluate()
 * function (defined in Node) to perform the calculations you need.
 */
	class FunctionNode : public Node
	{
	protected:
		int mArguments; ///< The number of arguments to this function.
		
	public:
		FunctionNode(int args);
		
		virtual int   arguments() const;
		virtual Flags flags() const;
		virtual void  infixParse(InfixParser& parser, Parser::Token& token) const;
	};
}

#endif

