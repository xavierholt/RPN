#include <cmath>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <stdexcept>

#include "helper.h"
#include "../RPN/libheader.h"

int TEST_RESULT = 0;

double evaluate(const char* string, const RPN::Context& context)
{
	RPN::Expression expression(string, context);
	return expression.evaluate();
}

void insist_equal_internal(int a, int b, const char* file, int line)
{
	if(a != b)
	{
		++TEST_RESULT;
		std::cout << "Equaltity check failed!\n"
		          << "    " << file << ':' << line << '\n'
		          << "    " << a << " != " << b << '\n';
	}
}

void insist_zero_internal(double a, const char* file, int line)
{
	if(fabs(a) > 0.00000001)
	{
		++TEST_RESULT;
		std::cout << "Equaltity check failed!\n"
		          << "    " << file << ':' << line << '\n'
		          << "    " << a << " != 0\n";
	}
}

void insist_equal_internal(double a, double b, const char* file, int line)
{
	if(b == 0)
	{
		insist_zero_internal(a, file, line);
	}
	else
	{
		if(fabs((a - b) / b) > 0.00000001)
		{
			++TEST_RESULT;
			std::cout << "Equaltity check failed!\n"
				      << "    " << file << ':' << line << '\n'
				      << "    " << a << " != " << b << '\n';
		}
	}
}

void test(const char* name, Functor functor)
{
	int cached = TEST_RESULT;
	
//	try
//	{
		functor();
//	}
//	catch(std::exception& e)
//	{
//		std::cout << "Exception: " << e.what() << '\n';
//		++TEST_RESULT;
//	}
	
	std::cout.setf(std::ios::left);
	std::cout.width(51);
	std::cout << name;
	
	if(cached == TEST_RESULT)
	{
		std::cout << "[PASSED]\n";
	}
	else
	{
		std::cout << "[FAILED]\n";
	}
}
