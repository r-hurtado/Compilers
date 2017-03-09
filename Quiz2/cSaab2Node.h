#pragma once
//**************************************
// cSaab2Node.h
//
// AST node for Saab1's
// 
#include "cSaabNode.h"
#include "cSymbol.h"
#include "cIntExprNode.h"

class cSaab2Node : public cSaabNode
{
    public:
        cSaab2Node(cSymbol* id1, cSymbol* id2, int size)
            : cSaabNode()
        {
            AddChild(id1);
            AddChild(id2);
            AddChild( new cIntExprNode(size));
        }

        virtual string NodeType() { return string("saab2"); }
};
