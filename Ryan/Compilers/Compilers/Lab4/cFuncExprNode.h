#include "cExprNode.h"
#include "cParamListNode.h"

class cFuncExprNode : public cExprNode
{
    public:
    	cFuncExprNode(cSymbol* name):cExprNode()
    	{
    		AddChild(name);
    	}
    	void AddPrams(cParamListNode * list)
    	{
    		AddChild(list);
    	}
	virtual string NodeType(){return string("funcCall");}
	virtual void Visit(cVisitor * visitor){visitor->Visit(this);}

}; 
