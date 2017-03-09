#pragma once

#include "cDeclNode.h"
#include <string>
using std::string;



class cBaseTypeNode : public cDeclNode
{
    public:
    cBaseTypeNode(int size, string name, bool isfloat): m_size(size), m_name(name), m_isFloat(isfloat)
    {
    }
    
    virtual bool IsFloat(){return m_isFloat;}
    virtual int GetSize(){return m_size;}
    
    virtual cDeclNode* GetType(){return this;}
    virtual string GetTypeName(){return m_name;}


    virtual void Visit(cVisitor * visitor) {visitor->Visit(this);}
    virtual string NodeType(){return " ";}
    
    protected:
        int m_size;
        string  m_name;
        bool m_isFloat;

};

