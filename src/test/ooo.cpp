#include "helper.h"

void test_ooo()
{
	//Addition
	insist_equal(evaluate("1 + 2 - 3"), 0.0);
	insist_equal(evaluate("1 - 2 + 3"), 2.0);

	insist_equal(evaluate("1 + 2 * 3"), 7.0);
	insist_equal(evaluate("1 * 2 + 3"), 5.0);

	insist_equal(evaluate("1 + 2 / 3"), 1.0 + 2.0/3);
	insist_equal(evaluate("1 / 2 + 3"), 3.5);

	insist_equal(evaluate("1 + 2 % 3"), 3.0);
	insist_equal(evaluate("1 % 2 + 3"), 4.0);

	insist_equal(evaluate("1 + -3"), -2.0);
	insist_equal(evaluate("-1 + 3"), 2.0);

	insist_equal(evaluate("1 + 2 ^ 3"), 9.0);
	insist_equal(evaluate("1 ^ 2 + 3"), 4.0);

	insist_equal(evaluate("1 + 3!"), 7.0);
	insist_equal(evaluate("1! + 3"), 4.0);

	//Subtraction
	insist_equal(evaluate("1 - 2 * 3"), -5.0);
	insist_equal(evaluate("1 * 2 - 3"), -1.0);

	insist_equal(evaluate("1 - 2 / 3"), 1.0/3);
	insist_equal(evaluate("1 / 2 - 3"), -2.5);

	insist_equal(evaluate("1 - 2 % 3"), -1.0);
	insist_equal(evaluate("1 % 2 - 3"), -2.0);

	insist_equal(evaluate("1 - -3"), 4.0);
	insist_equal(evaluate("-1 - 3"), -4.0);

	insist_equal(evaluate("1 - 2 ^ 3"), -7.0);
	insist_equal(evaluate("1 ^ 2 - 3"), -2.0);

	insist_equal(evaluate("1 - 3!"), -5.0);
	insist_equal(evaluate("1! - 3"), -2.0);

	//Multiplication
	insist_equal(evaluate("1 * 2 / 3"), 2.0/3);
	insist_equal(evaluate("1 / 2 * 3"), 1.5);

	insist_equal(evaluate("1 * 2 % 3"), 2.0);
	insist_equal(evaluate("1 % 2 * 3"), 3.0);

	insist_equal(evaluate("-1 * -3"), 3.0);
	insist_equal(evaluate("-1 * 3"), -3.0);
	insist_equal(evaluate("1 * -3"), -3.0);

	insist_equal(evaluate("1 * 2 ^ 3"), 8.0);
	insist_equal(evaluate("1 ^ 2 * 3"), 3.0);

	insist_equal(evaluate("2 * 3!"), 12.0);
	insist_equal(evaluate("2! * 3"), 6.0);

	//Division
	insist_equal(evaluate("1 / 2 % 3"), 0.5);
	insist_equal(evaluate("1 % 2 / 3"), 1.0/3);

	insist_equal(evaluate("-1 / -3"), 1.0/3);
	insist_equal(evaluate("-1 / 3"), -1.0/3);
	insist_equal(evaluate("1 / -3"), -1.0/3);

	insist_equal(evaluate("1 / 2 ^ 3"), 1.0/8);
	insist_equal(evaluate("1 ^ 2 / 3"), 1.0/3);

	insist_equal(evaluate("2 / 3!"), 1.0/3);
	insist_equal(evaluate("2! / 3"), 2.0/3);

	//Modulo
	insist_equal(evaluate("-1 % -3"), -1.0);
	insist_equal(evaluate("-1 % 3"), -1.0);
	insist_equal(evaluate("1 % -3"), 1.0);
	insist_equal(evaluate("1 % 3"), 1.0);

	insist_equal(evaluate("4 % 3 ^ 2"), 4.0);
	insist_equal(evaluate("4 ^ 3 % 2"), 0.0);

	insist_equal(evaluate("3 % 2!"), 1.0);
	insist_zero(evaluate("3! % 2"));

	//Negation...
	insist_equal(evaluate("-3 ^ 2"), -9.0);
	insist_equal(evaluate("3 ^ -2"), 1.0/9);

	insist_equal(evaluate("-3!"), -6.0);

	//Exponentiation
	insist_equal(evaluate("3 ^ 3!"), 729.0);
	insist_equal(evaluate("3! ^ 3"), 216.0);
}

