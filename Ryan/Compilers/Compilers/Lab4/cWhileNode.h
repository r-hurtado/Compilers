#include "cStmtNode.h"

class cWhileNode : public cStmtNode
{
    public:
    	cWhileNode(cExprNode * exp, cStmtNode * while_stat): cStmtNode()
    	{
    	    AddChild(exp);
    	    AddChild(while_stat);
    	}
    	virtual void Visit(cVisitor * visitor){visitor->Visit(this);}
    	virtual string NodeType(){return string("while");}

};
