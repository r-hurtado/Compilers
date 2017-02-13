#pragma once
//**************************************
// cIfNode.h
//
// Defines AST node that represents a list of statements
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan 9, 2016
//

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cStmtsNode.h"
#include "cExprNode.h"

class cIfNode : public cStmtNode
{
    public:
        cIfNode(cExprNode *expr, cStmtsNode *stmts, cStmtsNode *e_stmts = nullptr) : cStmtNode()
        {
            AddChild(expr);
			AddChild(stmts);
			AddChild(e_stmts);
        }

        virtual string NodeType() { return string("if"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
