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
// Date: Jan. 18, 2016
//

#include "cAstNode.h"
#include "cDeclsNode.h"
#include "cStmtNode.h"
#include "cStmtsNode.h"
static int count = 0;
class cBlockNode : public cStmtNode
{
    public:
        // params are the decls and statements contained in the block
        cBlockNode(cDeclsNode *decls, cStmtsNode *statements)
            : cStmtNode()
        {
			size = 0;
            AddChild(decls);
            AddChild(statements);
        }

        virtual string NodeType() { return string("block"); }
		virtual string AttributesToString()
        {
			if(count++ == 0)
			{
			
			//Round up to nearest word if needed
				if(size % 4 != 0)
					size += 4 - (size % 4);
			}
        	if(size)
        	    return string(" size=\"" + std::to_string(size) + '\"');
        	else
        	    return "";
        } 
		
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
		
		int getSize(){return size;}
        void setSize(int s){ size = s;}
		
	protected:
		int size;
};
