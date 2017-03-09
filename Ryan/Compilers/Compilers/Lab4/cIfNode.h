#include "cStmtNode.h"

class cIfNode : public cStmtNode
{
    public:
    	cIfNode(cExprNode * exp, cStmtsNode * if_state, cStmtsNode * else_state):cStmtNode()
    	{
    	    AddChild(exp);
    	    AddChild(if_state);
    	    AddChild(else_state);
    	
    	}
    	cIfNode(cExprNode * exp, cStmtsNode * if_state):cStmtNode()
    	{
    	    AddChild(exp);
    	    AddChild(if_state);
    	    
    	
    	}
    	virtual string NodeType(){return string("if");}
    	virtual void Visit(cVisitor* visitor){visitor->Visit(this);}


};
