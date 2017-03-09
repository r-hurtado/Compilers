#pragma once
//**************************************
// cStmtNode.h
//
// Defines abstract class for a single statment
//
// NOTE: all statement types must inherit from this class
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 28, 2015
//

#include "cAstNode.h"

class cStmtNode : public cAstNode
{
    public:
        cStmtNode() : cAstNode() {}
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
