#pragma once
//**************************************
// cStructDeclNode
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

class cStructDeclNode : public cDeclNode
{
public:
	cStructDeclNode(string name, cDeclsNode* decls) : cDeclNode()
	{
		cSymbol* temp = g_SymbolTable.FindLocal(name);
		if (temp == nullptr)
		{
			temp = new cSymbol(name, true); 
			g_SymbolTable.Insert(temp);
		}
		
		AddChild(decls);
		AddChild(temp);
	}

	virtual string NodeType() { return string("struct_decl"); }
	virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
