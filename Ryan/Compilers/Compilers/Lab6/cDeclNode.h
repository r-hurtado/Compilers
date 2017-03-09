#pragma once
//**************************************
// cDeclNode
//
// Defines virtual base class for all declarations.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 28, 2015
//
//Modified: Ryan Williams, Feb 23 2016
//

#include "cAstNode.h"
#include <string>

class cDeclNode : public cAstNode
{
    public:
        cDeclNode(int size = 0) : cAstNode()
       {
       	   _size = size;
       	   _offset = 0;
       }

        // return the decl for the type of the thing this node represents
        virtual cDeclNode *GetType() = 0;

        // return the name of the item that is declared
        virtual string  GetName() = 0;

        // virtual functions to define what kind of decl this is.
        // subclasses should override the appropriate functions.
        virtual bool IsStruct() { return false; }
        virtual bool IsFunc()   { return false; }
        virtual bool IsVar()    { return false; }
        virtual bool IsFloat()  { return false; }
        virtual int  Sizeof()   = 0;

        virtual string NodeType() { return string("decl"); }
        bool IsCompatibleWith(cDeclNode *decl)
        {
            if (IsFunc()) return false;
            if (this == decl) return true;
            if (IsStruct() || decl->IsStruct()) return false;
            if (IsFloat() && ! decl->IsStruct()) return true;
            if (Sizeof() >= decl->Sizeof()) return true;
            return false;
        }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        virtual int get_size(){return _size;}
        virtual int get_offset(){return _offset;}
        
        virtual void set_size(int size){ _size = size;}
        virtual void set_offset(int offset){ _offset = offset;}
        
        virtual string AttributesToString()
        {
        	 if(_size)
        	    return string(" size=\"" + std::to_string(_size) + "\" offset=\"" + std::to_string( _offset) + '\"');
        	 else
        	    return "";
        }
        
   protected:
   	int _size;
   	int _offset;
};
