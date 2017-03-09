#pragma once
//**************************************
// cExprNode.h
//
// Defines base class for all expressions
//
// This is a pure virtual class because there is no definition for
// cAstNode::ToString()
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2016
//
//Modified: Ryan Williams, Feb 20 2016
//
//

#include "cStmtNode.h"
#include "cDeclNode.h"

class cExprNode : public cStmtNode
{
    public:
        cExprNode() : cStmtNode() {}
        virtual cDeclNode * GetType() = 0;
        
        bool Castable(cExprNode* expr)
        {
            bool can_cast = true;
            // are they structs?
            if (!GetType()->IsStruct() != !expr->GetType()->IsStruct())
            {
                //are they the same type?
           	     can_cast = false;
            }
            else if ( (GetType()->IsStruct() && expr->GetType()->IsStruct()) && (GetType() != expr->GetType()))
	    {
	    	can_cast = false;
	    }
           	   
   	  // else  if (GetType()->IsFloat() !=  expr->GetType()->IsFloat())
          // {
          //      can_cast = false;
          // }
   	   //are both sides are not numbers
   	   else if(  (GetType()->IsNumeric() && expr->GetType()->IsNumeric() && 
   	   (GetType()->GetSize() <  expr->GetType()->GetSize())) ||
   	   (!GetType()->IsNumeric() != !expr->GetType()->IsNumeric()))
	   {
	         can_cast = false;
	   }
           return can_cast;
        }
        
};
