#pragma once
//**************************************
// cCarNode.h
//
// Defines AST node for Car
//
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Feb. 13, 2017
//

#include "cAstNode.h"
#include "cBlobNode.h"
#include "cExprNode.h"
#include "cFactNode.h"

class cCarNode : public cBlobNode
{
    public:
        cCarNode(cFactNode *fact, cExprNode* expr)
            : cBlobNode()
        {
            AddChild(fact);
            AddChild(expr);
        }

        virtual string NodeType() { return string("car"); }
};
