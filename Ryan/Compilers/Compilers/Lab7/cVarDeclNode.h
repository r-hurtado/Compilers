#pragma once
//**************************************
// cVarDeclNode.h
//
// Defines AST node for a variable declaration
//
// Inherits from cDeclNode so variables can be added to lists of decls
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 29, 2015
//

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"

class cVarDeclNode : public cDeclNode
{
    public:
        // params are the symbol for the type and the name
        cVarDeclNode(cSymbol *type_id, cSymbol *var_id) : cDeclNode()
        {
            AddChild(type_id);

            // Check to see if the symbol is not in the inner most scope.
            // A later lab will cause an error if it IS.
            cSymbol* m_var = g_SymbolTable.FindLocal(var_id->GetName());
            if (m_var == NULL)
            {
                m_var = var_id;

                // If the symbol exists in an outer scope, we need to create
                // a new one instead of reusing the outer scope's symbol.
                if (g_SymbolTable.Find(var_id->GetName()) != nullptr)
                {
                    m_var = new cSymbol(var_id->GetName());
                }

                // Insert into the global symbol table
                g_SymbolTable.Insert(m_var);
                //m_var->SetDecl(type_id->GetDecl());
                m_var->SetDecl(this);

                AddChild(m_var);
            }
            else
            {
                string error("");

                error += "Symbol " + m_var->GetName();
                error += " already defined in current scope";
                SemanticError(error);
            }
        }

        virtual bool IsVar() { return true; }

        // return the name of the variable
        virtual string GetName() 
        { 
            cSymbol* name = dynamic_cast<cSymbol*>(m_children.back());
            return name->GetName(); 
        }

        // return the symbol for the type
        virtual cDeclNode* GetType() 
        { 
            cSymbol* type_id = dynamic_cast<cSymbol*>(m_children.front());
            return type_id->GetDecl(); 
        }

        // return a string representation of the node
        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
