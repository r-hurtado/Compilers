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
// Date: Jan. 18, 2016
//
//Modified: Ryan Williams, Feb 21 2016
//

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"

extern void SemanticError(std::string error);

class cVarDeclNode : public cDeclNode
{
    public:
        // params are the symbol for the type and the name
        cVarDeclNode(cSymbol *type_id, cSymbol *var_id):m_type(type_id)
        {
        
            if (!g_SymbolTable.FindLocal(var_id->GetName()))
            {
                // If the symbol exists in an outer scope, we need to create
                // a new one instead of reusing the outer scope's symbol.
                if (g_SymbolTable.Find(var_id->GetName()) != nullptr)
                {
                    var_id = new cSymbol(var_id->GetName());
                }
                
                var_id->SetDecl(this);

                // Insert into the global symbol table
                g_SymbolTable.Insert(var_id);
            }
            else
            {
            	SemanticError("Symbol " + var_id->GetName() + " already defined in current scope");
            }
            AddChild(type_id);
            AddChild(var_id);
        }

        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        virtual bool IsVar(){return true;}
        virtual cDeclNode* GetType(){return m_type->GetDecl();}
        virtual string GetTypeName(){return m_type->GetName();}
        
   private:
   	cSymbol* m_type;
};
