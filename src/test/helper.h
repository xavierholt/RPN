#ifndef RPN_TEST_HELPER_H
#define RPN_TEST_HELPER_H

#include "../RPN/libheader.h"

#define insist_equal(a, b) insist_equal_internal(a, b, __FILE__, __LINE__)
#define insist_zero(a) insist_zero_internal(a, __FILE__, __LINE__)

extern int TEST_RESULT;

double evaluate(const char* string, const RPN::Context& cxt = RPN::Context::ROOT);

void insist_equal_internal(int a, int b, const char* file, int line);
void insist_equal_internal(double a, double b, const char* file, int line);
void insist_zero_internal(double a, const char* file, int line);

typedef void (*Functor)(void);
void test(const char* name, Functor functor);

#endif

