#pragma once
//**************************************
// cAstNode.h
//
// pure virtual base class for all AST nodes
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Feb 13, 2017
//

#include <string>
#include <vector>
using std::string;
using std::vector;

class cAstNode
{
    public:
        typedef vector<cAstNode*>::iterator iterator;

        cAstNode() {}

        void AddChild(cAstNode *child)
        {
            m_children.push_back(child);
        }

        iterator FirstChild()
        {
            return m_children.begin();
        }

        iterator LastChild()
        {
            return m_children.end();
        }

        bool HasChildren()      { return !m_children.empty(); }

        int NumChildren()       { return (int)m_children.size(); }
        cAstNode* GetChild(int child)
        {
            if (child >= (int)m_children.size()) return nullptr;
            return m_children[child];
        }

        // return a string representation of the node
        string ToString() 
        {
            string result("");

            result += "<" + NodeType();
            result += AttributesToString();

            if (HasChildren())
            {
                result += ">";
                iterator it;
                for (it=FirstChild(); it != LastChild(); it++)
                {
                    if ( (*it) != nullptr) result += (*it)->ToString();
                }
            }

            if (HasChildren()) 
                result += "</" + NodeType() + ">\n";
            else
                result += "/>";

            return result;
        }

        virtual string AttributesToString()   { return string(""); }
        virtual string NodeType() = 0; //      { return "AST"; }

    protected:
        vector<cAstNode *> m_children;     // list of statements

};

