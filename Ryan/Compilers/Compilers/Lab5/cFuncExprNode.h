#pragma once
//**************************************
// cFuncExprNode.h
//
// Defines AST node for function calls
//
// Inherits from cExprNode so that functions can be used in expressions
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2016
//
//Modified: Ryan Williams, Feb 20 2016
//

#include "cAstNode.h"
#include "cStmtsNode.h"
#include "cParamListNode.h"
#include "cExprNode.h"
#include "cFuncDeclNode.h"
#include "cDeclNode.h"

extern void SemanticError(string error);

class cFuncExprNode : public cExprNode
{
    public:
        // params are the symbol for the func decl, and the params
        cFuncExprNode(cSymbol *name, cParamListNode *params)
            : cExprNode()
        {
			m_decl = name->GetDecl();
            bool diff_flag = false;
        
            if(name->GetDecl()->IsFunc())
            {
            	cFuncDeclNode* temp = dynamic_cast<cFuncDeclNode* >(name->GetDecl());
            	
            	
            	//Is there a better way for this???
                 if( ((temp->GetParams() != nullptr) && (params == nullptr)) || 
                 ((temp->GetParams() == nullptr) && (params != nullptr)) || 
                 (temp->GetParams()->NumChildren() != params->NumChildren()) )
                 {
                     SemanticError(name->GetName() + " redeclared with a different number of parameters");
                 }
		
 		    else if(temp->GetParams() != nullptr && params != nullptr)
 		    {
 		     for(int i = 0; i < params->NumChildren() && !diff_flag; i++)
 		     {
 		        cExprNode* new_child = dynamic_cast<cExprNode* >(params->GetChild(i));
 		        cDeclNode* m_child = dynamic_cast<cDeclNode* >(temp->GetParams()->GetChild(i));
 		     
 		     	if(new_child->GetType() != m_child->GetType())
 		     	{
 		     	    diff_flag = true;
 		     	}
 		     }
 		     if (diff_flag)
 		     {
 		       	SemanticError(name->GetName() + " called with a incompatible argument");
 		     }
			}
            }
            
            else
            {
            	SemanticError(name->GetName() + " is not a function");
            }
            
            AddChild(name);
            AddChild(params);
        }

        virtual string NodeType() { return string("funcCall"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        virtual cDeclNode* GetType(){return m_decl->GetType();}
    private:
    	cDeclNode* m_decl;
};
