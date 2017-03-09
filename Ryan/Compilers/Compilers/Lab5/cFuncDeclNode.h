#pragma once
//**************************************
// cFuncDeclNode.h
//
// Defines AST node for a function declaration
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
#include "cDeclsNode.h"
#include "cDeclNode.h"

extern void SemanticError(string error);

class cFuncDeclNode : public cDeclNode
{
    public:
        // params are the return type and name of function
        cFuncDeclNode(cSymbol *type, cSymbol *ident)
            : cDeclNode(),  m_name(ident), m_type(type), m_param_l(nullptr), m_overloads(nullptr), m_isDefinition(false)
        {
            cSymbol* temp =  g_SymbolTable.FindLocal(ident->GetName());
            
            if(temp == nullptr)
            {
               if (g_SymbolTable.Find(ident->GetName()))
               {
                  ident = new cSymbol(ident->GetName());
               }
               ident->SetDecl(this);
               g_SymbolTable.Insert(ident);
      
            }
            else
            {
                if(temp->GetDecl()->IsFunc())
            	{
            	    cFuncDeclNode* new_func = dynamic_cast<cFuncDeclNode* >(temp->GetDecl());
            	    m_overloads = new_func;
            	    
            	    if (!new_func->IsDefined())
            	    {
            	        ident->SetDecl(this);
            	    }
            	    else if (new_func->GetType() != GetType())
            	    {
               	        SemanticError(ident->GetName() + " previously defined with different return type");
            	    }
            	
            	}
            	else
            	{
            	    SemanticError(ident->GetName() + " previously defined as other then a function");
            	}
            
            }
            
            AddChild(type);
            AddChild(ident);
            //m_isDefinition = false;

            g_SymbolTable.Insert(ident);
        }

        // Add formal params to the declaration
        void AddParams(cParamsNode* params)
        {
            bool diff_flag = false;
            
            if( (m_overloads->GetParams() != nullptr) && (params != nullptr) && m_overloads )
            {
            	//Is there a better way for this???
                 if( ((m_overloads->GetParams() != nullptr) && (params == nullptr)) || 
                 ((m_overloads->GetParams() == nullptr) && (params != nullptr)) || 
                 (m_overloads->GetParams()->NumChildren() != params->NumChildren()) )
                 {
                     SemanticError(m_name->GetName() + " redeclared with a different number of parameters");
                 }
 		 else
 		 {
 		     for(int i = 0; i < params->NumChildren() && !diff_flag; i++)
 		     {
 		        cDeclNode* new_child = dynamic_cast<cDeclNode* >(params->GetChild(i));
 		        cDeclNode* m_child = dynamic_cast<cDeclNode* >(m_overloads->GetParams()->GetChild(i));
 		     
 		     	if(new_child->GetType() != m_child->GetType())
 		     	{
 		     	    diff_flag = true;
 		     	}
 		     }
 		     if (diff_flag)
 		     {
 		       	SemanticError(m_name->GetName() + " previously defined with different parameters");
 		     }
 		 }
            }
        
            AddChild(params);
            m_param_l = params;
        }

        // Add declarations to the declaration.
        // Doing so means this is a definition, not just a declaration
        // BUT, we will wait for AddStmts to mark it as a definition
        // because our grammar requires all functions to have statements.
        void AddDecls(cDeclsNode *decls)
        {
            AddChild(decls);
        }

        // Add statements to the declaration.
        // Doing so means that this is a definition, not just a declaration
        // We will set the flag marking this as a definition.
        void AddStmts(cStmtsNode *stmts)
        {
            // need to check that the function is not defined already
            cFuncDeclNode* temp = dynamic_cast<cFuncDeclNode* >(m_name->GetDecl());
            
            if(!temp->IsDefined() && stmts)
            {
                m_isDefinition = true;
            }
            else if(temp->IsDefined() && stmts)
	    {
	        SemanticError(m_name->GetName() + "already has a definition");
	    }
            AddChild(stmts);
        }
        
        //checks
        virtual bool IsFunc() {return true;}
        bool IsDefined(){return m_isDefinition;}
        

        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        //getters
        virtual cDeclNode* GetType(){return m_type->GetDecl();}
        virtual string GetTypeName(){return m_name->GetName();}
        cParamsNode* GetParams(){return m_param_l;}
    protected:
        cSymbol* m_name;
        cSymbol* m_type;
        cParamsNode* m_param_l;
        cFuncDeclNode* m_overloads;
        bool m_isDefinition;

};
