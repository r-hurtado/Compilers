#pragma once
//**************************************
// cSymbol.h
//
// Defines class used to represent symbols.
// Later labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2015
//

#include <string>

using std::string;

#include "cAstNode.h"

class cSymbol : public cAstNode
{
    public:
        // param is name of symbol
        cSymbol(string name, bool type = false) : cAstNode()
        {
            m_id = ++nextId;        // get next available ID
            m_name = name;
			m_type = type;
        }

        // return name of symbol
        string GetName() { return m_name; }
		
		bool isType() { return m_type; }

        virtual string AttributesToString()
        {
            string result(" id=\"");
            result += std::to_string(m_id);
            result += "\" name=\"" + m_name + "\"";
            return result;
        }
        virtual string NodeType() { return string("sym"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
    protected:
        static long long nextId;        // Next avail symbol ID
        long long m_id;                 // Unique ID for this symbol
        string m_name;                  // name of symbol
		bool m_type;					// Whether symbol is a type
};
