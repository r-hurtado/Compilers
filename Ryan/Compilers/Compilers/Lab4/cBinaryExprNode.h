#include "cExprNode.h"
#include "cOpNode.h"

class cBinaryExprNode : public cExprNode
{
    public:
	cBinaryExprNode(cExprNode * expr1, string  op, cExprNode * expr2) : cExprNode()
	{
	    AddChild(expr1);
	    AddChild(new cOpNode(op));
	    AddChild(expr2);
	}
    virtual void Visit(cVisitor *visitor) {visitor->Visit(this);}
    virtual string NodeType() {return string("expr");}
};
