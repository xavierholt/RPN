#include "left.h"
#include "../../translator.h"

namespace RPN
{
	LeftBracketNode::LeftBracketNode(char opener, char closer): BracketNode(opener, closer)
	{
		//Nothing else to do...
	}
	
	void LeftBracketNode::translate(Translator& translator) const
	{
		translator.push_to_stack(this);
	}
}

