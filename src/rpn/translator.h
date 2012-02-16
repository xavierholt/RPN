#ifndef RPN_TRANSLATOR_H
#define RPN_TRANSLATOR_H

#ifndef RPN_LIBHEADER
	#include <string>
	#include <vector>
#endif

namespace RPN
{
	class Context;
	class Expression;
	class Node;
	
	class Translator
	{
	public:
		enum TokenType
		{
			BLANK       = 0x01,
			PARENTHESIS = 0x02,
			NUMBER      = 0x04,
			IDENTIFIER  = 0x08,
			OPERATOR    = 0x10
		};
		
	public:
		const static unsigned char cInitial[256];
		const static unsigned char cSubsequent[256];
		
	protected:
		int mAvailable;
		int mMaxAvailable;
		
		const Context&                 mContext;
		Expression&                    mExpression;
		std::string::const_iterator    mIterator;
		std::vector<const Node*>       mStack;
		const std::string&             mString;
		std::string                    mToken;
		
	public:
		Translator(const Context& context, Expression& expression, const std::string& string);
		
		bool        hasStack() const;
		const Node* next();
		const Node* pop();
		void        push_to_expression(const Node* node);
		void        push_to_stack(const Node* node);
		void        shunt();
		const Node* top();
		void        translate();
	};
}

#endif

