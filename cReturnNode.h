#pragma once
//**************************************
// cReturnNode.h
//
// Defines AST node that represents a list of statements
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan 9, 2016
//

#include "cStmtNode.h"
#include "cExprNode.h"

class cReturnNode : public cStmtNode
{
    public:
        cReturnNode(cExprNode *expr) : cStmtNode()
        {
            AddChild(expr);
        }

        virtual string NodeType() { return string("return"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
