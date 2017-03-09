#include "cDeclNode.h"

class cVarDeclNode : public cDeclNode
{
    public:
	cVarDeclNode(cSymbol * type, cSymbol * name): cDeclNode()
	{
		AddChild(g_SymbolTable.Find(type->GetName()));
		
		if (g_SymbolTable.FindLocal(name->GetName()) == nullptr)
		{
		     name =  new cSymbol(name->GetName());
		     g_SymbolTable.Insert(name);
		     //AddChild(name);
		}
		AddChild(name);
	}
	

	virtual string NodeType() {return "var_decl";}
	virtual void Visit(cVisitor * visitor){visitor->Visit(this);}
};
