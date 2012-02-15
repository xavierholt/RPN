#include <iostream>
#include "rpn/rpn.h"

int main(int argc, char* argv[])
{
	(void)(argc); //Unused
	(void)(argv); //Unused
	
	double ans = 0;
	std::string input;
	
	RPN::initialize();
	
	RPN::Context context;
	RPN::Expression* expression = NULL;
	context.insert("ans", new RPN::VariableNode(&ans));
	
	std::cout << "rpn> ";
	
	while(true)
	{
		getline(std::cin, input);
		
		if(input == "exit")
		{
			std::cout << "Bye!\n\n";
			return 0;
		}
		else
		{
			std::cout << "     ";
			
			try
			{
				if(expression)
				{
					delete expression;
					expression = NULL;
				}
				
				expression = new RPN::Expression(context, input.c_str());
				ans = expression->evaluate();
				std::cout << ans;
			}
			catch(RPN::Exception e)
			{
				std::cout << "Error: " << e.what();
			}
			
			std::cout << "\nrpn> ";
		}
	}
}

