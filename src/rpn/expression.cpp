#include "expression.h"
#include "evaluator.h"
#include "node.h"
#include "parser.h"
#include "parsers/all.h"

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
		clear();
	}
	
	Evaluator* Expression::buildEvaluator() const
	{
		Evaluator* ret = new Evaluator();
		ret->reserve(mMaxAvailable);
		return ret;
	}
	
	void Expression::clear()
	{
		auto end = mStack.end();
		for(auto i = mStack.begin(); i < end; ++i)
		{
			(*i)->dereference();
		}
		
		mStack.clear();
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
		
		clear();
		//TODO: Add the RPN parser / format switch...
		InfixParser parser(string, context);
		parser.store(*this);
	}
	
	Expression& Expression::operator <<(const Node* node)
	{
		node->reference();
		mStack.push_back(node);
		return *this;
	}
}

