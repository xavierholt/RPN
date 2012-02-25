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
#ifndef RPN_EXPRESSION_H
#define RPN_EXPRESSION_H

#ifndef RPN_LIBHEADER
	#include <string>
	#include <vector>
#endif

#include "context.h"
#include "evaluator.h"

namespace RPN
{
	class Node;
	
	class Expression 
	{
	public:
		enum Format
		{
			INFIX,
			POSTFIX
		};
		
	protected:
		std::vector<const Node*> mStack;
		mutable double           mResult;
		int                      mMaxAvailable;
		mutable bool             mIsCached;
		mutable bool             mIsVolatile;
		
	public:
		Expression();
		Expression(const std::string& string, const Context& context = Context::ROOT, Format format = INFIX);
		~Expression();
		
		Evaluator* buildEvaluator() const;
		void       clear();
		double     evaluate() const;
		double     evaluate(Evaluator& evaluator) const;
		void       parse(const std::string& string, const Context& context = Context::ROOT, Format format = INFIX);
		
		Expression& operator <<(const Node* node);
		
		friend class Parser;
	};
}

#endif

