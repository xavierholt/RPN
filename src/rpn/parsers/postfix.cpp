#include "postfix.h"

namespace RPN
{
	PostfixParser::PostfixParser(const std::string& string, const Context& context): Parser(context)
	{
		parse(string);
	}
	
	void PostfixParser::parse(const std::string& string)
	{
		reset();
		std::string::const_iterator itr = string.begin();
		std::string::const_iterator end = string.end();
		
		Parser::Token token;
		while((token = next(itr, end)).node != NULL)
		{
			push_to_expression(token);
		}
		
		checkResult();
	}
}

