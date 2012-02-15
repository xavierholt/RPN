#include "expression.h"
#include "evaluator.h"
#include "node.h"
#include "translator.h"

namespace RPN
{
	Expression::Expression(const RPN::Context& context, const std::string& string, SourceFormat format)
	{
		//TODO: Add the RPN parser / format switch...
		Translator translator(context, *this, string);
		translator.translate();
	}
	
	Expression::~Expression()
	{
		auto end = mStack.end();
		for(auto i = mStack.begin(); i < end; ++i)
		{
			(*i)->dereference();
		}
	}
	
	Evaluator* Expression::buildEvaluator() const
	{
		Evaluator* ret = new Evaluator();
		ret->reserve(mMaxAvailable);
		return ret;
	}
	
	double Expression::evaluate() const
	{
		Evaluator evaluator;
		evaluator.reserve(mMaxAvailable);
		return evaluate(evaluator);
	}
	
	double Expression::evaluate(Evaluator& evaluator) const
	{
		auto end = mStack.end();
		for(auto i = mStack.begin(); i < end; ++i)
		{
			evaluator.push_back((*i)->evaluate(evaluator));
		}
		
		return evaluator.back();
	}
	
	Expression& Expression::operator <<(const Node* node)
	{
		node->reference();
		mStack.push_back(node);
		return *this;
	}
}

