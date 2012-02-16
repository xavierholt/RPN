#include "expression.h"
#include "evaluator.h"
#include "node.h"
#include "translator.h"

namespace RPN
{
	Expression::Expression()
	{
		//Nothing to do...
	}
	
	Expression::Expression(const std::string& string, const RPN::Context& context, Format format)
	{
		parse(string, context, format);
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
	
	void Expression::parse(const std::string& string, const Context& context, Format format)
	{
		(void)(format); //Unused (for now)...
		//TODO: Add the RPN parser / format switch...
		mStack.clear();
		Translator translator(context, *this, string);
		translator.translate();
	}
	
	Expression& Expression::operator <<(const Node* node)
	{
		node->reference();
		mStack.push_back(node);
		return *this;
	}
}

