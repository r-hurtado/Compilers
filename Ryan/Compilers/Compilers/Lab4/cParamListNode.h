#pragma once

#include "cAstNode.h"

class cParamListNode : public cAstNode
{
    public:
    	cParamListNode(cExprNode* exp) : cAstNode()
    	{
    		AddChild(exp);
    	}
    	virtual void Visit(cVisitor * visitor){visitor->Visit(this);}
    	virtual string NodeType(){return string("params");}

};
