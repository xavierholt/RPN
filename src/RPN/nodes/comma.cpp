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
#include "../parsers/infix.h"
#include "comma.h"

namespace RPN
{
	void CommaNode::infixParse(InfixParser& parser, Parser::Token& token) const
	{
		(void)(token); //Unused
		
		while(parser.hasStack())
		{
			if(parser.top().node->type() == Node::BRACKET)
			{
				return;
			}
			else
			{
				parser.shunt();
			}
		}
	}
	
	Node::Type CommaNode::infixPresents() const
	{
		return Node::OPERATOR;
	}
	
	Node::Type CommaNode::infixSucceeds() const
	{
		return Node::VALUE;
	}
	
	Node::Type CommaNode::type() const
	{
		//TODO: Is this correct?  Should there be a COMMA type?
		return Node::OPERATOR;
	}
}

