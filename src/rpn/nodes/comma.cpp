#include "../translator.h"
#include "comma.h"

namespace RPN
{
	void CommaNode::translate(Translator& translator) const
	{
		while(translator.hasStack())
		{
			if(translator.top()->isBracket())
			{
				return;
			}
			else
			{
				translator.shunt();
			}
		}
	}
}

