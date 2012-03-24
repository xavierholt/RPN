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
#include "context.h"
#include "core.h"
#include "nodes/all.h"

#include <iostream>

namespace RPN
{
/**
 * Helper for initialize_root_context().
 * @param map The std::map to insert \p node into.
 * @param string The name by which \p node will be referenced.
 * @param node The node to insert.
 *
 * Adds a reference counter to \p node and inserts it into the given
 * context.
 * @see initialize_root_context()
 */
	inline void initialize_node(ContextMap& map, const std::string& string, const Node* node)
	{
		node->reference();
		map[string] = node;
	}
	
/**
 * Initializes the default root context (RPN::Context::ROOT).
 * This function will be called automatically when RPN is loaded - there is no
 * need to call it yourself.
 */
	ContextMap initialize_root_context()
	{
		ContextMap map;
		
		initialize_node(map, ",", new CommaNode());
		
		initialize_node(map, "(", new LeftBracketNode('(', ')'));
		initialize_node(map, ")", new RightBracketNode('(', ')'));
		initialize_node(map, "[", new LeftBracketNode('[', ']'));
		initialize_node(map, "]", new RightBracketNode('[', ']'));
		initialize_node(map, "{", new LeftBracketNode('{', '}'));
		initialize_node(map, "}", new RightBracketNode('{', '}'));
		
		initialize_node(map, "+", new AdditionNode());
		initialize_node(map, "-", new SubtractionNode());
		initialize_node(map, "*", new MultiplicationNode());
		initialize_node(map, "/", new DivisionNode());
		initialize_node(map, "%", new ModuloNode());
		initialize_node(map, "~", new NegationNode());
		initialize_node(map, "^", new ExponentiationNode());
		initialize_node(map, "!", new FactorialNode());
		
		initialize_node(map, "abs", new AbsoluteValueNode());
		initialize_node(map, "max", new MaximumNode());
		initialize_node(map, "min", new MinimumNode());
		
		initialize_node(map, "pow", new PowerNode());
		initialize_node(map, "exp", new ExponentialNode());
		initialize_node(map, "root", new RootNode());
		initialize_node(map, "sqrt", new SquareRootNode());
		
		initialize_node(map, "ln", new NaturalLogarithmNode());
		initialize_node(map, "log", new LogarithmNode());
		initialize_node(map, "log2", new BinaryLogarithmNode());
		initialize_node(map, "log10", new DecadicLogarithmNode());
		
		initialize_node(map, "sin", new SineNode());
		initialize_node(map, "cos", new CosineNode());
		initialize_node(map, "tan", new TangentNode());
		initialize_node(map, "csc", new CosecantNode());
		initialize_node(map, "sec", new SecantNode());
		initialize_node(map, "cot", new CotangentNode());
		
		initialize_node(map, "asin", new ArcSineNode());
		initialize_node(map, "acos", new ArcCosineNode());
		initialize_node(map, "atan", new ArcTangentNode());
		initialize_node(map, "acsc", new ArcCosecantNode());
		initialize_node(map, "asec", new ArcSecantNode());
		initialize_node(map, "acot", new ArcCotangentNode());
		
		initialize_node(map, "atan2", new ArcTangent2Node());
		initialize_node(map, "acot2", new ArcCotangent2Node());
		
		initialize_node(map, "pi", new ConstantNode(RPN::Constants::PI));
		initialize_node(map, "e", new ConstantNode(RPN::Constants::E));
		
		initialize_node(map, "sinh", new HyperbolicSineNode());
		initialize_node(map, "cosh", new HyperbolicCosineNode());
		initialize_node(map, "tanh", new HyperbolicTangentNode());
		initialize_node(map, "csch", new HyperbolicCosecantNode());
		initialize_node(map, "sech", new HyperbolicSecantNode());
		initialize_node(map, "coth", new HyperbolicCotangentNode());
		
		initialize_node(map, "asinh", new HyperbolicArcSineNode());
		initialize_node(map, "acosh", new HyperbolicArcCosineNode());
		initialize_node(map, "atanh", new HyperbolicArcTangentNode());
		initialize_node(map, "acsch", new HyperbolicArcCosecantNode());
		initialize_node(map, "asech", new HyperbolicArcSecantNode());
		initialize_node(map, "acoth", new HyperbolicArcCotangentNode());
		
		return map;
	}
	
/**
 * The default root context.
 * This context is pre-populated with a fairly extensive list of functions and
 * operators (and a handful of constants), allowing RPN to be used "out-of-the-
 * box" for basic evaluation.
 */
	const Context Context::ROOT(initialize_root_context(), NULL);
	
/**
 * Constructor.
 * @param parent The parent context of this context.  Defaults to RPN::Context::ROOT.
 */
	Context::Context(const Context* parent): mParent(parent)
	{
		//Nothing else to do...
	}
	
/**
 * Convenience constructor.
 * @param map A std::map of std::string s to RPN::Node s.
 * @param parent The parent context of this context.  Defaults to RPN::Context::ROOT.
 *
 * Allows a context to be created from a std::map.
 */
	Context::Context(const ContextMap& map, const Context* parent): mHash(map), mParent(parent)
	{
		//Nothing else to do...
	}
	
/**
 * Destructor.
 * Dereferences all the nodes in this context.
 */
	Context::~Context()
	{
		for(ContextMap::const_iterator i = mHash.begin(); i != mHash.end(); ++i)
		{
			(*i).second->dereference();
		}
	}
	
/**
 * Adds a node to this context.
 * @param name The name by which this node will be referenced.
 * @param node The node to insert.
 *
 * A reference counter will be added to \p node . If there is already a node
 * listed under \p name in this context, it will be dereferenced and removed.
 */
	void Context::insert(const std::string& name, const Node* node)
	{
		remove(name);
		node->reference();
		mHash[name] = node;
	}
	
/**
 * Looks up a node by name.
 * @param name The name of the node.
 * @return A pointer to the node, or NULL if it could not be found in this context.
 */
	const Node* Context::lookup(const std::string& name) const
	{
		ContextMap::const_iterator ref = mHash.find(name);
		if(ref == mHash.end())
		{
			if(mParent)
			{
				return mParent->lookup(name);
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
	
/**
 * Removes a node from this context.
 * @param name The name of the node.
 * @return True if a node going by \p name was found; false otherwise.
 *
 * If a node is found, it is dereferenced before being removed.
 */
	bool Context::remove(const std::string& name)
	{
		ContextMap::iterator ref = mHash.find(name);
		if(ref != mHash.end())
		{
			(*ref).second->dereference();
			mHash.erase(ref);
			return true;
		}
		return false;
	}
}

