#ifndef RPN_EXPRESSION_H
#define RPN_EXPRESSION_H

#ifndef RPN_LIBHEADER
	#include <string>
	#include <vector>
#endif

#include "context.h"
#include "evaluator.h"

namespace RPN
{
	class Node;
	
	class Expression 
	{
	public:
		enum Format
		{
			INFIX,
			POSTFIX
		};
		
	protected:
		std::vector<const Node*> mStack;
		mutable double           mResult;
		int                      mMaxAvailable;
		mutable bool             mIsCached;
		mutable bool             mIsVolatile;
		
	public:
		Expression();
		Expression(const std::string& string, const Context& context = Context::ROOT, Format format = INFIX);
		~Expression();
		
		Evaluator* buildEvaluator() const;
		bool       cache() const;
		void       clear();
		double     evaluate() const;
		double     evaluate(Evaluator& evaluator) const;
		void       parse(const std::string& string, const Context& context = Context::ROOT, Format format = INFIX);
		
		Expression& operator <<(const Node* node);
		
		friend class Parser;
	};
}

#endif

