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
	
/**
 * A dictionary of node names and the nodes they map to.
 * Contexts are arranged in a tree structure.  If a given name is not found in
 * a context, it is searched for in that context's parent, and so on until the
 * top of the tree is reached.
 */
	class Context
	{
	public:
		static const Context ROOT;
	
	protected:
		ContextMap     mHash;   ///< The name-to-node mapping of this context.
		const Context* mParent; ///< The parent of this context.
		
	public:
		Context(const Context* parent = &ROOT);
		Context(const ContextMap& map, const Context* parent = &ROOT);
		~Context();
		
		void        insert(const std::string& name, const Node* node);
		const Node* lookup(const std::string& name) const;
		bool        remove(const std::string& name);
	};
}

#endif

