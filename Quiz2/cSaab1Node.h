#pragma once
//**************************************
// cSaab1Node.h
//
// AST node for Saab's

#include "cSaabNode.h"
#include "cSymbol.h"

class cSaab1Node : public cSaabNode
{
    public:
        // params are the decls and statements contained in the block
        cSaab1Node(cSymbol* id1, cSymbol* id2)
            : cSaabNode()
        {
            AddChild(id1);
            AddChild(id2);
        }

        virtual string NodeType() { return string("saab1"); }
};
