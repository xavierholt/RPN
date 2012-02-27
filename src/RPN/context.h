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
#ifndef RPN_CONTEXT_H
#define RPN_CONTEXT_H

#ifndef RPN_LIBHEADER
	#include <map>
	#include <string>
#endif

namespace RPN
{
	class Node;
	
	typedef std::map<const std::string, const Node*> ContextMap;
	
	class Context
	{
	public:
		static const Context ROOT;
	
	protected:
		ContextMap     mHash;
		const Context* mParent;
		
	public:
		Context(const Context* parent = &ROOT);
		Context(const ContextMap& map, const Context* parent = &ROOT);
		~Context();
		
		void        insert(const std::string& str, const Node* node);
		const Node* lookup(const std::string&) const;
		bool        remove(const std::string&);
	};
}

#endif

