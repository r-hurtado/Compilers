#include "cComputeSize.h"
#include "lex.h"
#include "astnodes.h"
#include "cParamsNode.h"

void cComputeSize::VisitAllNodes(cAstNode * node)
{
	VisitAllChildren(node);
}


int cComputeSize::Align(int c_offset)
{
 return ((4 - (c_offset % 4)) % 4);
}

void cComputeSize::Visit(cBlockNode * start)
{
	int t_offset = m_offset;
	int t_high = m_highwater;
	m_highwater = 0;
	
	VisitAllChildren(start);
	
	start->setSize(m_highwater - t_offset);
	
	if(m_highwater < t_high)
	    m_highwater = t_high;
	    
	m_offset =  t_offset;
}

void cComputeSize::Visit(cVarDeclNode * start)
{
	int temp_s = 0;
	int temp_o = 0;
	
	if(start->GetType()->IsStruct())
	{
	    temp_s = start->GetType()->get_size();
	}
	else
	{
	    temp_s = start->GetType()->Sizeof();
	}
	
	start->set_size(temp_s);
	
	if(temp_s >= 4)
	{
	    temp_o = m_offset + Align(m_offset); 
	    start->set_offset(temp_o);
	    m_offset = temp_s + temp_o;
	    
	}
	else
	{
	    start->set_offset(m_offset);
	    m_offset += temp_s;
	}
	
	if(m_highwater < m_offset)
		m_highwater = m_offset;
	
}



void cComputeSize::Visit(cDeclNode * start)
{
        int temp_o = m_offset;
	
	VisitAllChildren(start);
	
	start->set_size(m_offset - temp_o);
	
}

void cComputeSize::Visit(cDeclsNode * start)
{
	int temp_o = m_offset;
	
	/*if(start->NodeType() == "args")
	{
	     VisitParams(start);
	     dynamic_cast<cParamsNode*> (start)->Set_Size(m_offset - temp_o);
	}*/
//	else
//	{
	     VisitAllChildren(start);
             start->setSize(m_offset - temp_o);
//	}

}


void cComputeSize::Visit(cStructDeclNode * start)
{
	int temp_o = m_offset;
	m_offset = 0;
	
	VisitAllChildren(start);
	
	start->set_size(m_offset);
	
	m_offset = temp_o;
}


void cComputeSize::Visit(cFuncDeclNode * start)
{
	int temp_h = m_highwater;
	int temp_o = m_offset;
	
	m_offset = 0;
	m_highwater = 0;
	
	VisitAllChildren(start);
	
	start->set_size(m_highwater + Align(m_highwater));
	
	m_offset = temp_o;
	m_highwater = temp_h;
}


void cComputeSize::Visit(cParamsNode * start)
{
	int temp_o = m_offset;
	
	cAstNode::iterator iter = start->FirstChild();
	
	while(iter != start->LastChild())
	{
	   if((*iter) != nullptr)
	   	(*iter)->Visit(this);
	   	
	   m_offset = m_offset + Align(m_offset);
	   iter++;
	}
	
	start->Set_Size(m_offset - temp_o);
}


// made this because of a error where args were being 
//recognized as decals instead of params and the 
// reference to params.h was not working 

//FIXED IT
void cComputeSize::VisitParams(cDeclsNode * start)
{
	
	cAstNode::iterator iter = start->FirstChild();
	
	while(iter != start->LastChild())
	{
	   if((*iter) != nullptr)
	   	(*iter)->Visit(this);
	   	
	   m_offset = m_offset + Align(m_offset);
	   
	   iter++;
	}
	
	
}


void cComputeSize::Visit(cVarExprNode * start)
{
	int temp_o = m_offset;
	
	m_offset = 0;
	
	VisitAllNodes(start);
	
	start->set_Offset(m_offset);
	
	start->set_Size(start->GetDecl()->get_size());
	
	m_offset = temp_o;

}

void cComputeSize::Visit(cSymbol * sym)
{
    m_offset += sym->GetDecl()->get_offset();
}
