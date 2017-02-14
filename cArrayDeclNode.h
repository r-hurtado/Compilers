#pragma once
//**************************************
// cArrayDeclNode
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

class cArrayDeclNode : public cDeclNode
{
public:
	cArrayDeclNode(string name, cSymbol* type, int count) : cDeclNode()
	{
		cSymbol* temp = g_SymbolTable.FindLocal(name);
		if (temp == nullptr)
		{
			temp = new cSymbol(name, true); 
			g_SymbolTable.Insert(temp);
		}
		
		AddChild(type);
		AddChild(temp);
		m_count = count;
	}
	virtual string AttributesToString() 
	{
		return " count=\"" + std::to_string(m_count) + "\"";
	}
	virtual string NodeType() { return string("array_decl"); }
	virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
	
protected:
	int m_count;
};
