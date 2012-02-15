#include "exception.h"

namespace RPN
{
	Exception::Exception(const std::string& message): std::runtime_error(message)
	{
		//Nothing else to do...
	}
}

