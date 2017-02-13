#pragma once
//**************************************
// cAssignNode.h
//
// Defines AST node for print statements
//
// Inherits from cStmtNode so print statments can go in statement lists, and be
// used anywhere a statement is legal.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2015
//

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"

class cAssignNode : public cStmtNode
{
    public:
        // param is the value to be printed
        cAssignNode(cVarExprNode *var_expr, cExprNode *expr) : cStmtNode()
        {
			AddChild(var_expr);
            AddChild(expr);
        }

        virtual string NodeType() { return string("assign"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
