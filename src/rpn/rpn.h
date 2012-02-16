#ifndef RPN_H
#define RPN_H

#include "context.h"
#include "evaluator.h"
#include "exception.h"
#include "expression.h"
#include "nodes/inheritable.h"
#include "translator.h"

namespace RPN
{
	namespace Constants
	{
		const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
		const double E  = 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274;
	}
	
	void initialize();
}

#endif

