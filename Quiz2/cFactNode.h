#pragma once
//**************************************
// cFactNode.h
//

#include "cAstNode.h"
#include "cExprNode.h"

class cFactNode : public cExprNode
{
    public:
        cFactNode(cExprNode* expr)
            : cExprNode()
        {
            AddChild(expr);
        }

        virtual string NodeType() { return string("fact"); }
};
