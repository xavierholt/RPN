#include <cmath>
#include "helper.h"

void test_trig()
{
	double x;
	double y;
	
	RPN::Context cxt;
	cxt.insert("x", new RPN::VariableNode(&x));
	cxt.insert("y", new RPN::VariableNode(&y));
	
	RPN::Expression xsin("sin x", cxt);
	RPN::Expression xcos("cos x", cxt);
	RPN::Expression xtan("tan x", cxt);
	
	RPN::Expression xsec("sec x", cxt);
	RPN::Expression xcsc("csc x", cxt);
	RPN::Expression xcot("cot x", cxt);
	
	RPN::Expression xasin("asin x", cxt);
	RPN::Expression xacos("acos x", cxt);
	RPN::Expression xatan("atan x", cxt);
	
	RPN::Expression xasec("asec x", cxt);
	RPN::Expression xacsc("acsc x", cxt);
	RPN::Expression xacot("acot x", cxt);
	
	RPN::Expression xatan2("atan2(x, y)", cxt);
	RPN::Expression xacot2("acot2(x, y)", cxt);
	
	for(x = -RPN::Constants::PI; x < RPN::Constants::PI; x += 0.097)
	{
		insist_equal(xsin.evaluate(), sin(x));
		insist_equal(xcos.evaluate(), cos(x));
		insist_equal(xtan.evaluate(), tan(x));
		
		insist_equal(xsec.evaluate(), 1.0/cos(x));
		insist_equal(xcsc.evaluate(), 1.0/sin(x));
		insist_equal(xcot.evaluate(), 1.0/tan(x));
	}
	
	for(x = -1; x < 1; x += 0.043)
	{
		insist_equal(xasin.evaluate(), asin(x));
		insist_equal(xacos.evaluate(), acos(x));
		insist_equal(xatan.evaluate(), atan(x));
		
		insist_equal(xasec.evaluate(), acos(1.0/x));
		insist_equal(xacsc.evaluate(), asin(1.0/x));
		insist_equal(xacot.evaluate(), atan(1.0/x));
	}
	
	for(x = -1; x < 1; x+= 0.069)
	{
		for(y = -1; y < 1; y += 0.73)
		{
			insist_equal(xatan2.evaluate(), atan2(x, y));
			insist_equal(xacot2.evaluate(), atan2(y, x));
		}
	}
}
