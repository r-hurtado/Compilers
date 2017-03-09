#pragma once
//**************************************
// cAssignNode.h
//
// Defines AST node for assignment statments
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2016
//
//Modified: Ryan Williams, Feb 20, 2016
//

#include "cExprNode.h"
#include "cVarExprNode.h"

extern void SemanticError(std::string error);

class cAssignNode : public cStmtNode
{
    public:
        // params are the lval and the expression
        cAssignNode(cVarExprNode *lval, cExprNode *expr)
            : cStmtNode()
        {
        //      if(lval->GetType()->GetSize() < expr->GetType()->GetSize())

        	if(!lval->Castable(expr))
        	{
        	    SemanticError("Cannot assign " + expr->GetType()->GetTypeName() + " to "
        	    + lval->GetType()->GetTypeName());
        	}
        
           	AddChild(lval);
            	AddChild(expr);
        
        }

        virtual string NodeType() { return string("assign"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
