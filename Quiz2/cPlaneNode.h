#pragma once
//**************************************
// cPlaneNode.h
//
// Defines AST node for Plane
//
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Feb. 13, 2017
//

#include "cBlobNode.h"
#include "cSaabNode.h"

class cPlaneNode : public cBlobNode
{
    public:
        cPlaneNode(cSaabNode *grunk)
            : cBlobNode()
        {
            AddChild(grunk);
        }

        virtual string NodeType() { return string("plane"); }
};
