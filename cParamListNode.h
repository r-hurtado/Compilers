#pragma once
//**************************************
// cParamListNode.h
//
// Defines a class to represent a list of declarations.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 7, 2016
//

#include "cAstNode.h"
#include "cExprNode.h"

class cParamListNode : public cAstNode
{
    public:
        // param is the first decl in this decls
        cParamListNode(cExprNode *expr) : cAstNode()
        {
            AddChild(expr);
        }

        // Add a decl to the list
        void Insert(cExprNode *expr)
        {
            AddChild(expr);
        }

        virtual string NodeType() { return string("params"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
