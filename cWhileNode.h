#pragma once
//**************************************
// cWhileNode.h
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

class cWhileNode : public cStmtNode
{
    public:
        cWhileNode(cExprNode *expr, cStmtNode *stmt) : cStmtNode()
        {
            AddChild(expr);
			AddChild(stmt);
        }

        virtual string NodeType() { return string("while"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
