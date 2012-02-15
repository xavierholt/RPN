#include "exception.h"
#include "node.h"

namespace RPN
{
	int Node::arguments() const
	{
		throw Exception("This node was never meant to be translated!");
		return -1;
	}
	
	void Node::dereference() const
	{
		if(--mReferenceCount <= 0)
		{
			delete this;
		}
	}
	
	double Node::evaluate(Evaluator& evaluator) const
	{
		(void)(evaluator); //Unused
		throw Exception("This node was never meant to be evaluated!");
		return 0.0;
	}
	
	bool Node::isBracket() const
	{
		return false;
	}
	
	bool Node::isFunction() const
	{
		return false;
	}
	
	bool Node::isOperator() const
	{
		return false;
	}
	
	void Node::reference() const
	{
		++mReferenceCount;
	}
}
