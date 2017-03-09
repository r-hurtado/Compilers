#pragma once
//**************************************
// cSaabNode.h
//
// Defines AST node for a Saab
//
// This is a virtual base class because the cAstNode::NodeType() funciton 
// is not defined.

#include "cAstNode.h"

class cSaabNode : public cAstNode
{
    public:
        // params are the decls and statements contained in the block
        cSaabNode()
            : cAstNode()
        { }

};
