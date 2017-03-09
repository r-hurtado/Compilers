#pragma once
//**************************************
// cVarExprNode.h
//
// Defines AST node for a variable reference
//
// Inherits from cExprNode so variable refs can be used in expressions`
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 29, 2015
//
//Modified: Ryan Williams, Feb 23 2016
//
//

#include <assert.h>

#include "cSymbol.h"
#include "cAstNode.h"
#include "cExprNode.h"

class cVarExprNode : public cExprNode
{
    public:
        // param is the symbol for the variable
        cVarExprNode(cSymbol *name)
            : cExprNode()
        {
            cSymbol *sym = g_SymbolTable.Find(name->GetName());
            if (sym == nullptr)
            {
                string error("");
                error += "Symbol " + name->GetName() + " not defined";
                SemanticError(error);
            }

            AddChild(name);
        }

        // called for the fields in struct refs
        void AddElement(cSymbol *name)
        {
            cSymbol* sym;
            sym = dynamic_cast<cSymbol*>(m_children.back());

            if (sym->GetDecl()->GetType()->IsStruct())
            {
                cStructDeclNode *decl;
                decl = dynamic_cast<cStructDeclNode *>(sym->GetDecl()->GetType());
                assert(decl != nullptr);

                cSymbol* field = decl->GetField(name->GetName());
                if (field != nullptr)
                {
                    AddChild(field);
                }
                else
                {
                    SemanticError( name->GetName() + " is not a field of " +
                            GetName());
                }
            }
            else
            {
                SemanticError( GetName() + " is not a struct" );
            }
        }

        // return a string representation of the name of the var
        virtual string GetName()
        {
            string name("");
            cSymbol* sym;
            cAstNode::iterator it = FirstChild();

            sym = dynamic_cast<cSymbol*>(*it);

            name += sym->GetName();

            for (it++; it != LastChild(); it++)
            {
                sym = dynamic_cast<cSymbol*>(*it);
                name += "." + sym->GetName();
            }

            return name;
        }
            
        // Return the type of the var
        virtual cDeclNode* GetType()
        {
            cSymbol* sym;

            sym = dynamic_cast<cSymbol*>(m_children.back());

            return sym->GetDecl()->GetType();
        }

        // Return the declaration of the var
        virtual cDeclNode* GetDecl()
        {
            cSymbol* sym;

            sym = dynamic_cast<cSymbol*>(m_children.back());

            return sym->GetDecl();
        }

        // return a string representation of the node
        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        int get_Size(){return Size;}
        int get_Offset(){return Offset;}
        
        void set_Size(int size){Size=size;}
        void set_Offset(int offset){Offset=offset;}
        
        virtual string AttributesToString()
        {
            if(Size) return string(" size=\"" + std::to_string(Size) + "\" offset=\"" + std::to_string(Offset) + '\"');
            else return "";
        }
        
   protected:
   	int Size;
   	int Offset;
};
