#pragma once
//**************************************
// cOpNode.h
//
// Class for an operator (e.g. + - etc.)
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Feb. 13, 2017
//

#include "cAstNode.h"

class cOpNode : public cAstNode
{
    public:
        cOpNode(int op) : cAstNode()
        {
            m_op = op;
        }

        virtual string NodeType()       { return "op"; }
        virtual string AttributesToString()   
        { 
            string result(" value='");
            result += (char)m_op;
            result += "'";

            return result;
        }
    protected:
        int m_op;      // the operand
};

