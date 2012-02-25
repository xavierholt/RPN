#ifndef RPN_CONTEXT_H
#define RPN_CONTEXT_H

#ifndef RPN_LIBHEADER
	#include <map>
	#include <string>
#endif

namespace RPN
{
	class Node;
	
	class Context
	{
	public:
		static Context* ROOT;
		
	protected:
		std::map<std::string, const Node*> mHash;
		const Context* mParent;
		
	public:
		Context(const Context* parent = ROOT);
		~Context();
		
		void        insert(std::string str, const Node* node);
		const Node* lookup(std::string) const;
		bool        remove(std::string);
	};
}

#endif

