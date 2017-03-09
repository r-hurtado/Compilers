#include <iostream>
#include "cVisitor.h"
#include <string>
using std::to_string;
#include "emit.h"
#include "astnodes.h"



class cCodeGen: public cVisitor
{
    public:
        cCodeGen(string filename):cVisitor()
        {
            InitOutput(filename.c_str());
            EmitString("Stack_Pointer += 4");
            EmitEnd();
        }
        
        ~cCodeGen()
        {
            EmitString("Stack_Pointer -= 4");
            EmitEnd();
            FinalizeOutput();
        }
        
        void EmitEnd()
        {
        	EmitString(";\n");
        }
        
        bool Check_Float(cExprNode * node)
        {
            return node->GetType()->GetSize() == 8 ? true : false;
        }
        
        bool Check_Func(cDeclNode * node)
        {
            return node->GetType()->IsFunc();
        }
        virtual  void VisitAllNodes(cAstNode * node)
        {
            node->Visit(this);
        }
        
        virtual void Visit(cProgramNode* node)
        {
        	EmitString("Stack_Pointer += " + to_string(node->GetBlock()->GetSize()));
        	EmitEnd();
        	
        	VisitAllNodes(node);
        }
        /*virtual void Visit(cBlockNode * node)
        {	
        	if (node->GetSize())
        	{
        		EmitString("Stack_Pointer += " + to_string(node->GetSize()));
       			EmitEnd();
        	}
        	
        	VisitAllNodes(node);
        	
        	if(node->GetSize())
        	{
        		EmitString("Stack_Pointer -= " + to_string(node->GetSize()));
        		EmitEnd();
        	}
        }*/
        virtual void Visit(cIntExprNode* node)
        {
            EmitInt(node->GetValue());
        }
        
        virtual void Visit(cFloatExprNode* node)
        {
            EmitFloat(node->GetValue());
        }
        
        
        virtual void Visit(cPrintNode* node)
        {
            if(Check_Float(node->GetExpr()))
            {
            	EmitString("Temp_F = ");
            	node->GetExpr()->Visit(this);
            	EmitEnd();
            	EmitPrintTemp_F();
            }
            else
            {
                EmitString("Temp = ");
                node->GetExpr()->Visit(this);
            	EmitEnd();
            	EmitPrintTemp();
            }
        }
        
        virtual void Visit(cAssignNode* node)
        {
        	if( node->GetRight()->isFunc())
        	{ 
        		node->GetRight()->Visit(this);
        		node->GetLeft()->Visit(this);
        		
        		if(!Check_Float( node->GetRight()))
        		{
        			EmitString(" = Temp");
        			EmitEnd();
        		}
        		else 
        		{
        			EmitString(" = Temp_F");
        			EmitEnd();
        		}
        	}
        	else
        	{
        		node->GetLeft()->Visit(this);
        		EmitString(" = ");
        		node->GetRight()->Visit(this);
        		EmitEnd();
        	}
        }
        
        virtual void Visit(cBinaryExprNode* node)
        {
        	// find the left will be emited based on its own type
        	node->GetLeft()->Visit(this);
        	//find the operator
        	node->GetOp()->Visit(this);
        	//find the right
        	node->GetRight()->Visit(this);
        }
        
        virtual void Visit(cOpNode* node)
        {
        	EmitString(' ' +  node->GetOpAsString() + ' ');
        }
        
        virtual void Visit(cVarExprNode* node)
        {
        	if (Check_Float(node))
        	{
        		EmitString("*(double *) &Memory[Frame_Pointer + " + to_string(node->GetOffset()) + "]");
        	}
        	else if (node->GetSize() > 1 && node->GetSize() < 5)
        	{
        		EmitString("*(int *) &Memory[Frame_Pointer + " + to_string(node->GetOffset()) + "]");
        	}
        	else
        	{
        		EmitString("Memory[Frame_Pointer + " + to_string(node->GetOffset()) + "]");
        	}
        }
        
        virtual void Visit(cIfNode* node)
        {
        	// create a end label 
        	
        	string end_l = GenerateLabel();
        	// check to see if the if has a else
        	if (node->GetElseStmts() != nullptr)
        	{
        		//had else
        		
        		// create an else lable
        		string else_l = GenerateLabel();
        		//emit if statement that jumps to the else based on condition
        		EmitString("if((");
        		node->GetCond()->Visit(this);
        		EmitString(") == 0) goto " + else_l);
        		EmitEnd();
        		node->GetIfStmts()->Visit(this);
        		EmitString("goto " + end_l);
        		EmitEnd();
        		EmitString(else_l + ":\n" );
        		node->GetElseStmts()->Visit(this);
        		EmitString(end_l + ":\n" );
        	}
        	// no else
        	else
        	{
        		//check condition
        		EmitString("if(( ");
        		node->GetCond()->Visit(this);
        		// jump to end lable
        		EmitString(") == 0) goto " + end_l);
        		EmitEnd();
        		node->GetIfStmts()->Visit(this);
        		EmitString(end_l + ":\n" );
        	}
        
        }
        
        virtual void Visit(cWhileNode* node)
        {
        	//create end and loop labels to goto
      	 	string end_l = GenerateLabel();
      	 	string loop_l =GenerateLabel();
      	 	
      	 	//emit the loop label
      	 	EmitString(loop_l + ":\n");
      	 	//start loop
      	 	EmitString("if(( ");
      	 	node->GetCond()->Visit(this);
      	 	EmitString(" ) == 0) goto " + end_l);
      	 	EmitEnd();
      	 	node->GetStmts()->Visit(this);
      	 	EmitString("goto " + loop_l);
      	 	EmitEnd();
      	 	EmitString(end_l + ":\n" );
        }
        
        virtual void Visit(cReturnNode* node)
        {
        	if(!Check_Float(node->GetExpr()))
        		EmitString("Temp = ");
        	else 
        		EmitString("Temp_F = ");
        		
        	node->GetExpr()->Visit(this);
        	EmitEnd();
        	EmitString("goto " + m_func_l);
        	EmitEnd();
        }
        virtual void Visit(cFuncExprNode* node)
        {
			EmitString("*(int *)&Memory[Stack_Pointer] = Frame_Pointer");
			EmitEnd();
			
			if(node->GetParamList() != nullptr)
			{
				EmitString("Stack_Pointer += " + to_string(node->GetDecl()->GetParams()->GetSize()));
				EmitEnd();
			}
			else
			{
				EmitString("Stack_Pointer += 4");
				EmitEnd();
			}
    
			if(node->GetParamList() != nullptr)
			{
				//Is there a better way todo this?
				for(int i = 0; i < node->GetParamList()->NumChildren(); ++i)
				{
					
					if(Check_Float(node->GetParamList()->GetParam(i)))
					{
						EmitString("*(double *)&Memory[Stack_Pointer] = ");
						node->GetParamList()->GetParam(i)->Visit(this);
						EmitEnd();
						EmitString("Stack_Pointer += 8");
						EmitEnd();
					}
					else
					{
						EmitString("*(int *)&Memory[Stack_Pointer] = ");
						node->GetParamList()->GetParam(i)->Visit(this);
						EmitEnd();
						EmitString("Stack_Pointer += 4");
						EmitEnd();
					}
				}

				EmitString("Frame_Pointer = Stack_Pointer");
				EmitEnd();
				EmitString("Frame_Pointer -= " + to_string(node->GetDecl()->GetParams()->GetSize()));
				EmitEnd();
			}
			else
			{
				EmitString("Frame_Pointer = Stack_Pointer");
				EmitEnd();
			}

			EmitString(node->GetName() + "()");
			EmitEnd();
			
			
			//if i reset my stack then my variable that are passed in are not able to be accessed 
			//after a function call
			
			if(node->GetParamList() != nullptr)
			{
				EmitString("Stack_Pointer -= " + to_string(node->GetDecl()->GetParams()->GetSize()));
				EmitEnd();
			}
    			else
    			{
				EmitString("Stack_Pointer -= 4");
				EmitEnd();
			}
			
			
			EmitString("Frame_Pointer = *(int *)&Memory[Stack_Pointer]");
			EmitEnd();
        }
        
        virtual void Visit(cFuncDeclNode* node)
        {
        	if(node->GetLocals() != nullptr || node->GetStmts() != nullptr)
        	{
        		m_func_l = GenerateLabel();
        		StartFunctionOutput(node->GetName());
        		
        		if(node->GetLocals())
        		{
        			EmitString("Stack_Pointer += " + to_string(node->GetLocals()->GetSize()));
        			EmitEnd();
        			node->GetLocals()->Visit(this);
        		}
        		if(node->GetStmts())
        		{
        			node->GetStmts()->Visit(this);
        		}
        		
        		
        		EmitString(m_func_l + ":\n");
        		if(node->GetLocals())
        		{
        			EmitString("Stack_Pointer -= " + to_string(node->GetLocals()->GetSize()));
        			EmitEnd();
        		} 
        		EndFunctionOutput();
        	}
        	else {}
        	//else you found a prototype
        }
        
        
       
        /*void Visit()
        {
        }*/
    
   private:
   	string m_func_l;

};

