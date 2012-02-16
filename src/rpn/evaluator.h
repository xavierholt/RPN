#ifndef RPN_EVALUATOR_H
#define RPN_EVALUATOR_H

#include <vector>

namespace RPN
{
	class Evaluator : public std::vector<double>
	{
	public:
		double pop()
		{
			double ret = back();
			pop_back();
			return ret;
		}
	};
}

#endif

