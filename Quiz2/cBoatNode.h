#pragma once
//**************************************
// cBoatNode.h
//
// Defines AST node for Boat
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Feb. 13, 2017
//

#include "cBlobNode.h"
#include "cIntExprNode.h"

class cBoatNode : public cBlobNode
{
    public:
        cBoatNode(int size)
            : cBlobNode()
        {
            AddChild( new cIntExprNode(size) );
        }

        virtual string NodeType() { return string("boat"); }
};
