#ifndef RPN_PARSERS_INFIX_H
#define RPN_PARSERS_INFIX_H

#include "../parser.h"

namespace RPN
{
	class InfixParser : public Parser
	{
	protected:
		std::vector<Token> mStack;
		
	public:
		InfixParser(const std::string& string, const Context& context);
		
		bool   hasStack() const;
		Token  pop();
		void   push_to_stack(Token& token);
		void   shunt();
		Token& top();
	};
}

#endif

