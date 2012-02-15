#ifndef RPN_EXPRESSION_H
#define RPN_EXPRESSION_H

#include <string>
#include <vector>
#include "evaluator.h"

namespace RPN
{
	class Context;
	class Node;
	
	class Expression 
	{
	public:
		enum SourceFormat
		{
			INFIX,
			RPN
		};
		
	protected:
		int mMaxAvailable;
		std::vector<const Node*> mStack;
		
	public:
		Expression(int size);
		Expression(const Context& context, const std::string& string, SourceFormat format = INFIX);
		~Expression();
		
		Evaluator* buildEvaluator() const;
		double     evaluate() const;
		double     evaluate(Evaluator& evaluator) const;
		
		Expression& operator <<(const Node* node);
		
		friend class Translator;
	};
}

#endif

