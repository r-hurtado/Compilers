#pragma once
//**************************************
// cStuffNode.h
//
// Defines and AST node for stuff

#include "cAstNode.h"
#include "cGrunkNode.h"
#include "cGloopsNode.h"
#include "cBlobNode.h"

class cStuffNode : public cBlobNode
{
    public:
        cStuffNode(cGrunkNode* grunk, cGloopsNode* gloop)
            : cBlobNode()
        {
            AddChild(grunk);
            AddChild(gloop);
        }

        virtual string NodeType() { return string("stuff"); }
};
