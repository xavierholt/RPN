#ifndef RPN_EXCEPTION_H
#define RPN_EXCEPTION_H

#include <stdexcept>

namespace RPN
{
	class Exception : public std::runtime_error
	{
	public:
		Exception(const std::string& message);
	};
}

#endif

