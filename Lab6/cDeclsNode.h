#pragma once
//**************************************
// cDeclsNode.h
//
// Defines a class to represent a list of declarations.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2016
//

#include "cAstNode.h"
#include "cDeclNode.h"

class cDeclsNode : public cAstNode
{
    public:
        // param is the first decl in this decls
        cDeclsNode(cDeclNode *decl) : cAstNode()
        {
			m_Size = 0;
            AddChild(decl);
        }

        // Add a decl to the list
        void Insert(cDeclNode *decl)
        {
            AddChild(decl);
        }

        // return a particular decl from the list
        cDeclNode* GetDecl(int index)
        {
            return static_cast<cDeclNode*>(GetChild(index));
        }

        virtual string NodeType() { return string("decls"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
		        
        virtual string AttributesToString()
        {	if(m_Size)
        	{
        	    return string(" size= \"" + std::to_string(m_Size) + '\"');
        	}
        	else
        	    return "";
        } 
		
		// return the sum of the sizes of the decls
        virtual int Sizeof()
        {
            int size = 0;

            cAstNode::iterator it;

            for (it = FirstChild(); it != LastChild(); it++)
            {
                size += dynamic_cast<cDeclNode *>(*it)->Sizeof();
            }
            return size;
        }
        
        int getSize(){return m_Size;}
        void setSize(int size){m_Size = size;}
        
   private:
       int m_Size;
};
