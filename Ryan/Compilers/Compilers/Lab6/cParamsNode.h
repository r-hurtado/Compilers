#pragma once
//**************************************
// cParamsNode.h
//
// Defines a class to represent a list of declarations.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 28, 2015
//

#include "cAstNode.h"
#include "cDeclNode.h"

class cParamsNode : public cDeclsNode
{
    public:
        // param is the first decl in this decls
        cParamsNode(cDeclNode *decl) : cDeclsNode(decl), _size(0)
        {
        }

        // return the XML node name
        virtual string NodeType() { return string("args"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        int Get_Size(){return _size;}
        void Set_Size(int size){_size = size;}
        
        
        virtual string AttributesToString()
        {
            if(_size) return string(" size=\"" + std::to_string(_size) + '\"');
            else return "";
        }
        
        protected:
            int _size;
};
