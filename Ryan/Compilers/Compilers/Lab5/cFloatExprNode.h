#pragma once
//**************************************
// cFloatExprNode.h
//
// Defines AST node for a float constant (literal)
// Inherits from cExprNode so float constants can be used in any expression.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2016
//
//Modified: Ryan Williams, Feb 20 2016
//
//

#include "cAstNode.h"
#include "cExprNode.h"
#include "cDeclNode.h"

class cFloatExprNode : public cExprNode
{
    public:
        // param is the value of the constant (literal)
        cFloatExprNode(double value)
        {
            m_value = value;
        }

        virtual string AttributesToString() 
        {
            return " value=\"" + std::to_string(m_value) + "\"";
        }
        virtual string NodeType() { return string("float"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        virtual cDeclNode* GetType(){return (g_SymbolTable.Find( "float" )->GetDecl());}
        
    protected:
        double m_value;     // value of the constant (literal)
};
