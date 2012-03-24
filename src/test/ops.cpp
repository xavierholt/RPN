#include "helper.h"

void test_ops()
{
	insist_equal(evaluate("1 + 2 + 3"), 6.0);
	insist_equal(evaluate("1 - 2 - 3"), -4.0);
	insist_equal(evaluate("1 * 2 * 3"), 6.0);
	insist_equal(evaluate("1 / 2 / 3"), 1.0/6.0);
	insist_equal(evaluate("3 % 2 % 1"), 0.0);
	insist_equal(evaluate("4 ^ 3 ^ 2"), 262144.0);
	
	insist_equal(evaluate("---3"), -3.0);
	insist_equal(evaluate("3!!"), 720.0);
}
