#pragma once
//**************************************
// cVarExprNode
//
// Defines base class for all declarations.
// Future labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2015
//

#include "cExprNode.h"

class cVarExprNode : public cExprNode
{
    public:
        cVarExprNode(cSymbol *name) : cExprNode()
        {
			AddChild(name);
        }
		
		// Add a statement to the list
        void Insert( cAstNode *sym)
        {
            AddChild(sym);
        }
		
		// Add a statement to the list
        void Insert(cExprNode *expr)
        {
            AddChild(expr);
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
