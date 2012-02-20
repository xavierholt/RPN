#ifndef RPN_PARSERS_POSTFIX_H
#define RPN_PARSERS_POSTFIX_H

#include "../parser.h"

namespace RPN
{
	class PostfixParser : public Parser
	{
	public:
		PostfixParser(const std::string& string, const Context& context);
		
		void parse(const std::string& string);
	};
}

#endif

