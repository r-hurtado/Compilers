#pragma once
//**************************************
// cBlockNode.h
//
// Defines AST node for a block of code (stuff inside {})
//
// Since blocks can take the place of statements, this class inherits from 
// cStmtNode
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 28, 2015
//

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cStmtsNode.h"
#include "cDeclsNode.h"

class cBlockNode : public cStmtNode
{
    public:
        // params are the decls and statements contained in the block
        cBlockNode(cDeclsNode *decls, cStmtsNode *statements)
            : cStmtNode()
        {
            _Size = 0;
            AddChild(decls);
            AddChild(statements);
        }

        // return the XML name of the node
        virtual string NodeType() { return string("block"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        virtual string AttributesToString()
        {
        	if(_Size)
        	    return string(" size=\"" + std::to_string(_Size) + '\"');
        	else
        	    return "";
        } 
        
        int get_Size(){return _Size;}
        void setSize(int size){ _Size = size;}
        
   protected:
   	int _Size;
};
