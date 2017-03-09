#pragma once
//**************************************
// cStructDeclNode.h
//
// Defines AST node for a struct declaration
//
// Inherits from cDeclNode because this is a type of declaration
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
#include "cDeclsNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"

class cStructDeclNode : public cDeclNode
{
    public:
        // params are: 
        //     the symbol table for the declarations that make up this struct
        //     the declarations that make up this struct
        //     the cSymbol for the name of the struct
        cStructDeclNode(cSymbolTable::symbolTable_t *symTbl, cDeclsNode *decls, cSymbol *struct_id): cDeclNode()
        {
            m_name = struct_id->GetName();
            cSymbol * name;
            AddChild(decls);
            m_symTbl = symTbl;
                
            name = g_SymbolTable.FindLocal(struct_id->GetName());
            
            if (name == nullptr)
            {
                name = struct_id;
                if(g_SymbolTable.Find(struct_id->GetName()) != nullptr)
                {
                	name = new cSymbol(struct_id->GetName());
                }
                name->SetDecl(this);
                g_SymbolTable.Insert(name);
            }
            struct_id->SetDecl(this);
	    AddChild(name);
            
        }
        
        cSymbol* GetField(string name)
        {
            return g_SymbolTable.FindInTable(m_symTbl, name);
        }

        virtual string NodeType() { return string("struct_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        virtual cDeclNode* GetType(){return this;}
        virtual string GetTypeName(){return m_name;}
        virtual bool IsStruct(){return true;}
        virtual bool IsVar(){return true;}
        
    protected:
        cSymbolTable::symbolTable_t *m_symTbl; 
        string m_name;

};
