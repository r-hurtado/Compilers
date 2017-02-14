#pragma once
//**************************************
// cParamsNode.h
//
// Defines a class to represent a list of declarations.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 7, 2016
//

#include "cAstNode.h"
#include "cDeclNode.h"

class cParamsNode : public cAstNode
{
    public:
        // param is the first decl in this decls
        cParamsNode(cDeclNode *decl) : cAstNode()
        {
            AddChild(decl);
        }

        // Add a decl to the list
        void Insert(cDeclNode *decl)
        {
            AddChild(decl);
        }

        virtual string NodeType() { return string("args"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
