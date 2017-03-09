#pragma once
//**************************************
// cGloops.h
//
// AST node for Gloops

#include "cAstNode.h"
#include "cBlobNode.h"

class cGloopsNode : public cAstNode
{
    public:
        cGloopsNode(cBlobNode *blob) : cAstNode()
        {
            AddChild(blob);
        }

        // Add the next blob to the list
        void Insert(cBlobNode *blob)
        {
            AddChild(blob);
        }

        virtual string NodeType() { return string("gloops"); }
};
