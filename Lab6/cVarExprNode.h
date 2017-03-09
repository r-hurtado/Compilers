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
// Date: Jan. 18, 2016
//

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
            AddChild(name);
        }

        // called for the fields in struct refs
        void AddElement(cSymbol *name)
        {
            AddChild(name);
        }

        void AddElement(cExprNode *index)
        {
            AddChild(index);
        }

        cSymbol* GetName() 
        {
            return static_cast<cSymbol*>(GetChild(0));
        }

        // return a string representation of the name of the var
        virtual string GetTextName()
        {
            string name("");
            cSymbol* sym;

            sym = GetName();

            name += sym->GetName();

            for (int ii=0; ii<NumItems(); ii++)
            {
                if (ItemIsIndex(ii))
                {
                    name += "[]";
                }
                else
                {
                    sym = GetElement(ii);
                    name += "." + sym->GetName();
                }
            }

            return name;
        }

        // return the type of the VarExpr. This includes dereferencing arrays
        virtual cDeclNode *GetType() 
        { 
            cDeclNode* decl = GetName()->GetDecl();
            if (decl == nullptr) return nullptr;

            cDeclNode* type = decl->GetType();

            if (type->IsArray())
            {
                return type->GetType(NumItems());
            }
            else
            {
                return type; 
            }
        }

        int NumItems() { return NumChildren() - 1; }

        bool ItemIsIndex(int index)
        {
            // if the dynamic cast fails, this item must be a cSymbol* for
            // a struct member
            return dynamic_cast<cExprNode*>(GetChild(index + 1)) != nullptr;
        }

        cSymbol* GetElement(int index)
        {
             return (cSymbol*)GetChild(index + 1);
        }

        cExprNode* GetIndex(int index)
        {
             return (cExprNode*)GetChild(index + 1);
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        int getSize(){return Size;}
        int getOffset(){return Offset;}
        
        void setSize(int size){Size=size;}
        void setOffset(int offset){Offset=offset;}
        
        virtual string AttributesToString()
        {
			cDeclNode* temp = GetName()->GetDecl()->GetType();
			if(GetName()->GetDecl() != nullptr)
			{
				if(temp->IsArray())
				{	
					if(temp->GetBaseType()->IsArray() > 0)
						return string(" size=\"" + std::to_string(temp->Sizeof()) + "\" offset=\"" + std::to_string(Offset) + "\" rowsizes=\"" + std::to_string(temp->Sizeof() / (temp->GetBaseType()->Sizeof())) + " " + std::to_string(Size) + '\"');
					else
						return string(" size=\"" + std::to_string(temp->Sizeof()) + "\" offset=\"" + std::to_string(Offset) + "\" rowsizes=\"" + std::to_string(Size) + '\"');
				}
				else
            /*if(Size)*/ return string(" size=\"" + std::to_string(Size) + "\" offset=\"" + std::to_string(Offset) + '\"');
            //else return "";
			}
			return "";
        }
        
   protected:
   	int Size;
   	int Offset;
};
