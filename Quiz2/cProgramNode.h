#pragma once
//**************************************
// cProgramNode.h
//
// Defines AST node for a CST 320 Quiz 2 program
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Feb. 13, 2017
//

#include "cAstNode.h"
#include "cOtherNode.h"

class cProgramNode : public cAstNode
{
    public:
        cProgramNode(cOtherNode *other) : cAstNode()
        {
            AddChild(other);
        }

        virtual string NodeType() { return string("program"); }
};
