#include "helper.h"

void test_ops();
void test_ooo();
void test_values();
void test_expressions();
void test_trig();
void test_hyps();

int main()
{
	
	test("Value Nodes", &test_values);
	test("Operators", &test_ops);
	test("Expression Nodes", &test_expressions);
	
	test("Order of Operations", &test_ooo);
	
	test("Hyperbolic Functions", &test_hyps);
	test("Trigonometry Functions", &test_trig);
	
	return TEST_RESULT;
}

