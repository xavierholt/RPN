#include "helper.h"

void test_values()
{
	RPN::Context cxt;
	
	//Constant node (boring)
	cxt.insert("c", new RPN::ConstantNode(42));
	insist_equal(evaluate("c", cxt), 42.0);
	
	//Variable node
	double x;
	cxt.insert("x", new RPN::VariableNode(&x));
	
	x = 17;
	RPN::Expression var("x", cxt);
	insist_equal(var.evaluate(), 17.0);
	
	x = 23;
	insist_equal(var.evaluate(), 23.0);
	
	//Expression node
	cxt.insert("e", new RPN::ExpressionNode(&var));
	insist_equal(evaluate("e", cxt), 23.0);
	
	//Argument node
	RPN::Evaluator eval;
	
	//One argument...
	cxt.insert("arg11", new RPN::ArgumentNode(1, 1));
	RPN::Expression arg1("arg11", cxt, 1);
	
	eval.push(12);
	insist_equal(arg1.evaluate(eval), 12.0);
	insist_equal(arg1.evaluate(7.5), 7.5);
	insist_zero(eval.count());
	
	//Two arguments...
	cxt.insert("arg12", new RPN::ArgumentNode(-2));
	cxt.insert("arg22", new RPN::ArgumentNode(-1));
	RPN::Expression arg2("arg12 + arg22", cxt, 2);
	
	eval.push(13);
	eval.push(14);
	insist_equal(arg2.evaluate(eval), 27.0);
	insist_equal(arg2.evaluate(7.5, 8.5), 16.0);
	insist_zero(eval.count());
	
	//Three arguments...
	cxt.insert("arg13", new RPN::ArgumentNode(1, 3));
	cxt.insert("arg23", new RPN::ArgumentNode(-2));
	cxt.insert("arg33", new RPN::ArgumentNode(3, 3));
	RPN::Expression arg3("arg13 + arg23 + arg33", cxt, 3);
	
	eval.push(101);
	eval.push(202);
	eval.push(303);
	insist_equal(arg3.evaluate(eval), 606.0);
	insist_equal(arg3.evaluate(1, 2, 3), 6.0);
	insist_zero(eval.count());
}
