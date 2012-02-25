#include "context.h"
#include "node.h"

namespace RPN
{
	typedef std::map<std::string, const Node*>::iterator CItr;
	typedef std::map<std::string, const Node*>::const_iterator CCItr;
	
	Context* Context::ROOT = 0;
	
	Context::Context(const Context* parent): mParent(parent)
	{
		//Nothing else to do...
	}
	
	Context::~Context()
	{
		CItr end = mHash.end();
		for(CItr i = mHash.begin(); i != end; ++i)
		{
			(*i).second->dereference();
		}
	}
	
	void Context::insert(std::string string, const Node* node)
	{
		remove(string);
		node->reference();
		mHash[string] = node;
	}
	
	const Node* Context::lookup(std::string string) const
	{
		CCItr ref = mHash.find(string);
		if(ref == mHash.end())
		{
			if(mParent)
			{
				return mParent->lookup(string);
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return (*ref).second;
		}
	}
	
	bool Context::remove(std::string string)
	{
		CItr ref = mHash.find(string);
		if(ref != mHash.end())
		{
			(*ref).second->dereference();
			mHash.erase(ref);
			return true;
		}
		return false;
	}
}
