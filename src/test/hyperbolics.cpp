#include <cmath>
#include "helper.h"

void test_hyps()
{
	double x;
	double y;
	
	RPN::Context cxt;
	cxt.insert("x", new RPN::VariableNode(&x));
	cxt.insert("y", new RPN::VariableNode(&y));
	
	RPN::Expression xsin("sinh x", cxt);
	RPN::Expression xcos("cosh x", cxt);
	RPN::Expression xtan("tanh x", cxt);
	
	RPN::Expression xsec("sech x", cxt);
	RPN::Expression xcsc("csch x", cxt);
	RPN::Expression xcot("coth x", cxt);
	
	RPN::Expression xasin("asinh x", cxt);
	RPN::Expression xacos("acosh x", cxt);
	RPN::Expression xatan("atanh x", cxt);
	
	RPN::Expression xasec("asech x", cxt);
	RPN::Expression xacsc("acsch x", cxt);
	RPN::Expression xacot("acoth x", cxt);
	
//	RPN::Expression xatan2("atanh2(x, y)", cxt);
//	RPN::Expression xacot2("acoth2(x, y)", cxt);
	
	for(x = -RPN::Constants::PI; x < RPN::Constants::PI; x += 0.097)
	{
		insist_equal(xsin.evaluate(), sinh(x));
		insist_equal(xcos.evaluate(), cosh(x));
		insist_equal(xtan.evaluate(), tanh(x));
		
		insist_equal(xsec.evaluate(), 1.0/cosh(x));
		insist_equal(xcsc.evaluate(), 1.0/sinh(x));
		insist_equal(xcot.evaluate(), 1.0/tanh(x));
	}
	
	for(x = -1; x < 1; x += 0.043)
	{
		insist_equal(xasin.evaluate(), asinh(x));
		insist_equal(xacos.evaluate(), acosh(x));
		insist_equal(xatan.evaluate(), atanh(x));
		
		insist_equal(xasec.evaluate(), acosh(1.0/x));
		insist_equal(xacsc.evaluate(), asinh(1.0/x));
		insist_equal(xacot.evaluate(), atanh(1.0/x));
	}
	
/*	for(x = -1; x < 1; x+= 0.069)
	{
		for(y = -1; y < 1; y += 0.73)
		{
			insist_equal(xatan2.evaluate(), atan2(x, y));
			insist_equal(xacot2.evaluate(), atan2(y, x));
		}
	}*/
}
