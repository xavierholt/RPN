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
#include "bracket.h"

namespace RPN
{
/**
 * Constructor.
 */
	BracketNode::BracketNode(char opener, char closer): Node(), mCloser(closer), mOpener(opener)
	{
		//Nothing else to do...
	}
	
/**
 * Gets the closing bracket character for this bracket type.
 * @return The right bracket character.
 */
	char BracketNode::closer() const
	{
		return mCloser;
	}
	
/**
 * Gets the opening bracket character for this bracket type.
 * @return The left bracket character.
 */
	char BracketNode::opener() const
	{
		return mOpener;
	}
	
/**
 * Checks if another bracket node has the same closing character as this one.
 * @param other A pointer to the node to compare this node against.
 * @return True if the closing characters match; false otherwise.
 */
	bool BracketNode::isClosedBy(const BracketNode* other) const
	{
		return (other->mCloser == mCloser);
	}
}

