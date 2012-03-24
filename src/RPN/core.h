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
#ifndef RPN_CORE_H
#define RPN_CORE_H

#ifndef RPN_LIBHEADER
	#include <string>
#endif

/**
 * The main namespace.
 * Your source for everything RPN.
 */
namespace RPN
{
/**
 * A sub-namespace to keep constant names from cluttering the code.
 * This may be removed in future versions.
 */
	namespace Constants
	{
/**
 * Pi.
 * @see https://en.wikipedia.org/wiki/Pi
 */
		const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
		
/**
 * Euler's Number.
 * @see https://en.wikipedia.org/wiki/E_%28mathematical_constant%29
 */
		const double E  = 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274;
	}
	
	bool isValidName(const std::string& name);
}

#endif

