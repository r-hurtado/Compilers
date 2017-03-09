#pragma once
//**************************************
// cBlob.h
//
// AST Node for a blob

#include "cAstNode.h"

class cBlobNode : public cAstNode
{
    public:
        cBlobNode() : cAstNode()
        { }

        virtual string NodeType() { return string("blob"); }
};
