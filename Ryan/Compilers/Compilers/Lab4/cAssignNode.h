#pragma once

#include "cStmtNode.h"
//#include "cVarExprNode.h"
//#include "cExprNode.h"

class cAssignNode : public cStmtNode
{
    public:
    	cAssignNode(cVarExprNode* val_exp, cExprNode* exp ): cStmtNode()
    	{
    		AddChild(val_exp);
    		AddChild(exp);
    	}

   virtual void Visit(cVisitor * visitor){visitor->Visit(this);}
   virtual string NodeType(){return string("assign");}

};

