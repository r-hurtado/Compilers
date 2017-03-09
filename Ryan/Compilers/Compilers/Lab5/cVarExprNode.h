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
//Modified: Ryan Williams, Feb 21 2016
//

#include "cSymbol.h"
#include "cAstNode.h"
#include "cExprNode.h"
#include "cSymbolTable.h"
#include "cStructDeclNode.h"
#include <string>

extern void SemanticError(string error);

class cVarExprNode : public cExprNode
{
    public:
        // param is the symbol for the variable
        cVarExprNode(cSymbol *name): cExprNode()
        {
            cSymbol* temp = g_SymbolTable.Find(name->GetName());
            
            if(temp == nullptr)
            {
            	SemanticError("Symbol " + name->GetName() + " not defined" );
            }
            else if (temp->GetDecl()->IsFunc())
            {
                SemanticError(temp->GetName() + " is not a lavl");
            }
            AddChild(name);
        }

        
        void AddElement(cSymbol *name)
        {
            cSymbol* start = dynamic_cast<cSymbol*>(GetChild(NumChildren() - 1));
            
            if(start->GetDecl()->GetType()->IsStruct())
            {
                cStructDeclNode* temp_struct = dynamic_cast<cStructDeclNode *>(start->GetDecl()->GetType());
                cSymbol* temp = temp_struct->GetField(name->GetName());
				
                if(temp == nullptr)
                    SemanticError(name->GetName() + " is not a field of " + GetName());
                else
                {
                    //delete start;
                    AddChild(temp);
                }
            }
            else
                SemanticError(GetName() + " is not a struct");
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
        string GetName()
        {
            
            string temp = "";

            for(int i = 0; i < NumChildren() - 1; ++i)
			{
                temp += dynamic_cast<cSymbol* >(GetChild(i))->GetName() + ".";
			}
			
            temp += dynamic_cast<cSymbol* >(GetChild(NumChildren() - 1))->GetName();

            return temp;
        }
		
	virtual cDeclNode * GetType() 
        {
            cSymbol* temp = dynamic_cast<cSymbol* >(GetChild(NumChildren() - 1));
            return temp->GetDecl()->GetType();
        }
};
