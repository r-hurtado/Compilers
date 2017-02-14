#pragma once
//**************************************
// cFuncExprNode
//
// Defines base class for all declarations.
// Future labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2015
//

#include "cExprNode.h"
#include "cParamListNode.h"

class cFuncExprNode : public cExprNode
{
public:
	cFuncExprNode(string name, cParamListNode* params = nullptr) : cExprNode()
	{
		cSymbol* temp = g_SymbolTable.FindLocal(name);
		if (temp == nullptr)
		{
			temp = new cSymbol(name, true); 
			g_SymbolTable.Insert(temp);
		}
		
		AddChild(temp);
		AddChild(params);
	}

	virtual string NodeType() { return string("funcCall"); }
	virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
