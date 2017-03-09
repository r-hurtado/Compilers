#pragma once
//**************************************
// cBinaryExprNode.h
//
// Defines AST node for binary expressions.
// Inherits from cExprNode
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2016
// Edited: Ryan Williams
// Feb 18,2016

#include "cAstNode.h"
#include "cExprNode.h"
#include "cOpNode.h"
#include "cDeclNode.h"

class cBinaryExprNode : public cExprNode
{
    public:
        // params are the left and right expressions and the operation.
        // The operation is a char: '+', '-', etc.
        cBinaryExprNode(cExprNode *left, int op, cExprNode *right)
            : cExprNode()
        {
            m_type = nullptr;
            AddChild(left);
            AddChild(new cOpNode(op));
            AddChild(right);
            
            
            //if the right can be promoted to the left'd type then store the type
            if (left->Castable(right))
            {
            	m_type = left->GetType();
            }
            else
            {
            	m_type = right->GetType();
            }
           
        }

        virtual string NodeType() { return string("expr"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        virtual cDeclNode* GetType(){return m_type;}
        
        protected:
            cDeclNode* m_type;
};
