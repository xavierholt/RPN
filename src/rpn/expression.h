#ifndef RPN_EXPRESSION_H
#define RPN_EXPRESSION_H

#include <string>
#include <vector>
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
			RPN
		};
		
	protected:
		int                      mMaxAvailable;
		std::vector<const Node*> mStack;
		double                   mResult;
		
	public:
		Expression();
		Expression(const std::string& string, const Context& context = Context::ROOT, Format format = INFIX);
		~Expression();
		
		Evaluator* buildEvaluator() const;
		double     evaluate() const;
		double     evaluate(Evaluator& evaluator) const;
		void       parse(const std::string& string, const Context& context = Context::ROOT, Format format = INFIX);
		
		Expression& operator <<(const Node* node);
		
		friend class Translator;
	};
}

#endif

