#include "cAstNode.h"

class cFuncDeclNode : public cDeclNode
{

    public:
    cFuncDeclNode(cSymbol* type, cSymbol* name):cDeclNode()
    {
        if (g_SymbolTable.Find(name->GetName())==nullptr)
        {
        	name = new cSymbol(name->GetName());
        	g_SymbolTable.Insert(name);
        }
    	AddChild(type);
    	AddChild(name);
    }
    void Insert(cAstNode* node)
    {
    	AddChild(node);
    }
    virtual string NodeType(){return string("func");}
    virtual void Visit(cVisitor* visitor){visitor->Visit(this);}
};
