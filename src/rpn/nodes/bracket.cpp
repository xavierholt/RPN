#include "bracket.h"

namespace RPN
{
	BracketNode::BracketNode(char opener, char closer): mCloser(closer), mOpener(opener)
	{
		//Nothing else to do...
	}
	
	char BracketNode::closer() const
	{
		return mCloser;
	}
	
	char BracketNode::opener() const
	{
		return mOpener;
	}
	
	bool BracketNode::isClosedBy(const BracketNode* other) const
	{
		return (other->mCloser == mCloser);
	}
	
	bool BracketNode::isBracket() const
	{
		return true;
	}
}

