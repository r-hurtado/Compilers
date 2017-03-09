#include "cStmtNode.h"

class cReturnNode : public cStmtNode
{
    public:
    	cReturnNode(cExprNode * exp) : cStmtNode()
    	{
    	    AddChild(exp);
    	}
    	
    	virtual void Visit(cVisitor * visitor){visitor->Visit(this);}
    	virtual string NodeType(){return string("return");}

};
