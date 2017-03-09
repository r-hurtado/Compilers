#include "cAstNode.h"

class cParamsNode : public cAstNode
{
    public:
    	cParamsNode(cDeclNode* declar) : cAstNode()
    	{
    		AddChild(declar);
    	}
    	virtual void Visit(cVisitor * visitor){visitor->Visit(this);}
    	virtual string NodeType(){return string("args");}

};
