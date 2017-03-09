#pragma once

#include "cVisitor.h"


class cComputeSize : public cVisitor
{
    public:
    	cComputeSize():cVisitor()
    	{
    	    m_offset = 0;
    	    m_highwater = 0;
    	}
    	
    	virtual void VisitAllNodes(cAstNode* node);
    	int Align(int c_offset);
	virtual void Visit(cBlockNode * node);
	virtual void Visit(cVarDeclNode * node);
	virtual void Visit(cDeclNode * node);
	virtual void Visit(cDeclsNode * node);
	virtual void Visit(cStructDeclNode * node);
	virtual void Visit(cFuncDeclNode * node);
	virtual void Visit(cVarExprNode * node);
	virtual void Visit(cSymbol  * node);
	
	
	
	//Problem with the include for paramsnode, workarround function below it
	virtual void Visit(cParamsNode * node);
	virtual void VisitParams(cDeclsNode * node);



    protected:
    	int m_offset;
	int m_highwater;

}; 
