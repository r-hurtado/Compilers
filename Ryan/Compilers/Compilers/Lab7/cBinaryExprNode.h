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
// Date: Nov. 29, 2015
//

#include "cAstNode.h"
#include "cOpNode.h"
#include "cExprNode.h"

class cBinaryExprNode : public cExprNode
{
    public:
        // params are the left and right expressions and the operation.
        // The operation is a char: '+', '-', etc.
        cBinaryExprNode(cExprNode *left, int op, cExprNode *right)
            : cExprNode()
        {
            AddChild(left);
            AddChild(new cOpNode(op));
            AddChild(right);
        }

        // return the type of the expression
        cDeclNode* GetType()
        {
            cExprNode *left = dynamic_cast<cExprNode *>(m_children.front());
            cExprNode *right= dynamic_cast<cExprNode *>(m_children.back());
            if (left->GetType() == right->GetType())
                return left->GetType();
            else if (left->GetType()->IsFloat())
                return left->GetType();
            else if (right->GetType()->IsFloat())
                return right->GetType();
            else if (left->GetType()->GetSize() >=
                     right->GetType()->GetSize())
                return left->GetType();
            else
                return right->GetType();
        }

        virtual string NodeType() { return string("expr"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        cExprNode * GetLeft()
        {
            // gets the left operator
            cExprNode * temp = (cExprNode *) GetChild(0);
            return temp;
        }
        cOpNode * GetOp()
        {
           //get operator
           cOpNode * temp =  (cOpNode *) GetChild(1);
           return temp;
        }
        cExprNode * GetRight()
        {
           //get right operator 
           cExprNode * temp = (cExprNode *) GetChild(2);
           return temp;
        }
        virtual bool isFunc() {return false;}
};
