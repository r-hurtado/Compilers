#include "cDeclNode.h"

class cStructDeclNode : public cDeclNode
{
    public:
    	cStructDeclNode(cDeclsNode* declar, cSymbol* name ):cDeclNode()
    	{
    		if (g_SymbolTable.Find(name->GetName()) == nullptr)
    		{
    			name = new cSymbol(name->GetName());
    		}
    		g_SymbolTable.Insert(name);
    		
    		AddChild(declar);
    		AddChild(name);
    	}
    	virtual void Visit(cVisitor * visitor){visitor->Visit(this);}
    	virtual string NodeType(){return string("struct_decl");}

};
