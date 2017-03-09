#pragma once
//**************************************
// cDeclNode
//
// Defines base class for all declarations.
// Future labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2016
//
//Modified: Ryan Williams, Feb 20 2016
//
//

#include "cAstNode.h"

class cDeclNode : public cAstNode
{
    public:
        cDeclNode() : cAstNode() {}
        
        virtual bool IsFunc(){return false;}
        virtual bool IsStruct(){return false;}
        virtual bool IsVar(){return false;}
        virtual bool IsFloat(){return false;}
        virtual int GetSize(){return 0;}
        bool IsNumeric(){return (!IsFunc() && !IsStruct() && !IsVar());}
        //these need to be virtual so that the child will be able to override
	virtual cDeclNode* GetType() = 0;
	virtual string GetTypeName() = 0;
};
