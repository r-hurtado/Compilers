#pragma once
//**************************************
// cOtherNode.h
//
// Defines and AST node for Other

#include "cAstNode.h"
#include "cSaabNode.h"
#include "cGloopsNode.h"
#include "cBlobNode.h"

class cOtherNode : public cBlobNode
{
    public:
        cOtherNode(cSaabNode* saab, cGloopsNode* gloop)
            : cBlobNode()
        {
            AddChild(saab);
            AddChild(gloop);
        }

        virtual string NodeType() { return string("other"); }
};
