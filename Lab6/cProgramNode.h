#pragma once
//**************************************
// cProgramNode.h
//
// Defines AST node for a lang program
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2016
//

#include "cAstNode.h"
#include "cBlockNode.h"

class cProgramNode : public cAstNode
{
    public:
        // param is the block that makes up the program
        cProgramNode(cBlockNode *block) : cAstNode()
        {
            AddChild(block);
        }

        virtual string NodeType() { return string("program"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
		
		// return the block from the list
        cBlockNode* getBlock()
        {
            return static_cast<cBlockNode*>(GetChild(0));
        }
};
