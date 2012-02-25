#include <iostream>
#include "../RPN/libheader.h"

int main()
{
	double ans = 0;
	std::string input;
	
	RPN::initialize();
	
	RPN::Context context;
	RPN::Expression expression;
	context.insert("ans", new RPN::VariableNode(&ans));
	
	while(std::cin.good())
	{
		std::cout << "\nrpn> ";
		getline(std::cin, input);
		
		if(!std::cin.good() || input == "exit")
		{
			break;
		}
		else
		{
			std::cout << "     ";
			
			try
			{
				expression.parse(input.c_str(), context);
				ans = expression.evaluate();
				std::cout << ans;
			}
			catch(RPN::Exception e)
			{
				std::cout << "Error: " << e.what();
			}
		}
	}
	
	std::cout << " Bye!\n\n";
	return 0;
}

