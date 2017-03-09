//#include "cAstNode.h"
#include "cExprNode.h"


class cVarExprNode: public cExprNode
{
    public:
	cVarExprNode(cSymbol * sym ): cExprNode()
	{
	    AddChild(sym);
	}


	
	virtual string  NodeType() {return ("varref");}
	virtual void Visit(cVisitor *visitor) {visitor->Visit(this);}

};

