#pragma once
//**************************************
// cFuncDeclNode
//
// Defines base class for all declarations.
// Future labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2015
//

#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cSymbolTable.h"
#include "cParamsNode.h"

class cFuncDeclNode : public cDeclNode
{
public:
	cFuncDeclNode(string name, cSymbol* type) : cDeclNode()
	{
		cSymbol* temp = g_SymbolTable.FindLocal(name);
		if (temp == nullptr)
		{
			temp = new cSymbol(name); 
			g_SymbolTable.Insert(temp);
		}
		
		AddChild(type);
		AddChild(temp);
	}
	
	// Add a decl to the list
	void Insert(cParamsNode *decl)
	{
		AddChild(decl);
	}
	
	// Add a decl to the list
	void Insert(cStmtsNode *stmts, cDeclsNode *decls = nullptr)
	{
		AddChild(decls);
		AddChild(stmts);
	}

	virtual string NodeType() { return string("func"); }
	virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
