#pragma once
//**************************************
// cVarDeclNode
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
#include "cSymbolTable.h"

class cVarDeclNode : public cDeclNode
{
public:
	cVarDeclNode(cSymbol *type, string name) : cDeclNode()
	{
		AddChild(type);
		
		cSymbol* temp = g_SymbolTable.FindLocal(name);
		if (temp == nullptr)
		{
			temp = new cSymbol(name); 
			g_SymbolTable.Insert(temp);
		}
		AddChild(temp);
	}

	virtual string NodeType() { return string("var_decl"); }
	virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
