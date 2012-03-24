#include "helper.h"

void test_expressions()
{
	RPN::Context cxt;
	cxt.insert("a", new RPN::ArgumentNode(1, 3));
	cxt.insert("b", new RPN::ArgumentNode(2, 3));
	cxt.insert("c", new RPN::ArgumentNode(3, 3));
	
	RPN::Expression fixed("13 + sin(0)", cxt);
	insist_equal(fixed.evaluate(), 13.0);
	
	RPN::Expression functor("a + b * c", cxt, 3);
	insist_equal(functor.evaluate(1, 2, 3), 7.0);
	
	cxt.insert("e", new RPN::ExpressionNode(&fixed));
	cxt.insert("f", new RPN::ExpressionNode(&functor));
	
	const RPN::Node* node = cxt.lookup("e");
	insist_equal(node->isValue(), 1);
	insist_zero(node->arguments());
	
	node = cxt.lookup("f");
	insist_equal(node->isFunction(), 1);
	insist_equal(node->arguments(), 3);
	
	RPN::Expression expr1("2 * e + 5", cxt);
	insist_equal(expr1.evaluate(), 31.0);
	
	RPN::Expression expr2("f(1, 2, 3)", cxt);
	insist_equal(expr2.evaluate(), 7.0);
	
	RPN::Expression expr3("2 * f(3, e, 2) + 5", cxt);
	insist_equal(expr3.evaluate(), 63.0);
}
