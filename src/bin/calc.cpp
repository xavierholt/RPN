/******************************************************************************
   Copyright 2012 Kevin Burk
   
   This file is part of RPN.
  
   RPN is free software: you can redistribute it and/or modify it under the
   terms of the GNU General Public License as published by the Free Software
   Foundation, either version 3 of the License, or (at your option) any later
   version.
  
   RPN is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
   details.
  
   You should have received a copy of the GNU General Public License along
   with RPN.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/
#include <iostream>
#include "../RPN/libheader.h"

int main()
{
	double ans = 0;
	std::string input;
	
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
			catch(RPN::Exception& e)
			{
				std::cout << e.what();
			}
		}
	}
	
	std::cout << " Bye!\n\n";
	return 0;
}

