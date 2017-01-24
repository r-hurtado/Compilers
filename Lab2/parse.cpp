//**************************************
// parse.cpp
//
// Starting point for top-down recursive-descent parser
// Used in CST 320 Lab2
//
// Author: Russ Hurtado 
// russell.hurtado@oit.edu
//
// Date: Jan. 23, 2017
//

#include <iostream>
#include "lex.h"
#include "parse.h"
#include "utils.h"
#include "tokens.h"

//*******************************************
// Find a PROG non-terminal
bool FindPROG()
{
	FindSTMTS();
	
	if(PeekToken() == END)
	{
		//std::cout << "Found a Program\n";
		return true;
	}
	
    //Error("Program");
    return false;
}

bool FindSTMTS()
{
	while(FindSTMT());
	return true;
}

bool FindSTMT()
{
	//expr ;
	if(FindEXPR())
	{
		if(PeekToken() == ';') 
		{
			AdvanceToken();
			std::cout << "Found a statement\n";
			return true;
		}
		else
		{
			Error(";");
		}
	}
	
	if(PeekToken() == END)
		return false;
	
	if(PeekToken() != ';')
	{
		while(PeekToken() != ';')
			AdvanceToken();
		AdvanceToken();
		return true;
	}
	//else if(PeekToken() == 'e')
	//	Error("EXPR");
	return false;
}

bool FindEXPR()
{
	/*//TERM
	if(FindTERM()) return true;
	
	//(EXPR) EXPR'
	if (PeekToken() != '(') {Error("("); AdvanceToken(); return false;} AdvanceToken();
	if (!FindEXPR()) return false;
	if (PeekToken() != ')') {Error(")"); AdvanceToken(); return false;} AdvanceToken();
	if (!FindEXPR_P()) return false;
	else{
	AdvanceToken();
	return true;
	}*/

	//(EXPR) EXPR'
	if (PeekToken() == '(')
	{
		AdvanceToken();
		if (FindEXPR())
		{
			//Error("EXPR*");
			//AdvanceToken();
			if (PeekToken() == ')')
			{
				AdvanceToken();
				if (FindEXPR_P())
				{
					return true;
				}
			}
			else
			{ 
				Error(")"); 
				return false;
			}
		}
	}
	else	
	{
		//TERM
		if(FindTERM()) return true;
	}
	
	//AdvanceToken();
	return false;
}

bool FindEXPR_P()
{
	//PLUSOP (EXPR) EXPR'
	/*if (!FindPLUSOP()) return false;
	if (PeekToken() != '(') {Error("("); AdvanceToken(); return false;} AdvanceToken();
	if (!FindEXPR()) return false;
	if (PeekToken() != ')') {Error(")"); AdvanceToken(); return false;} AdvanceToken();
	if (!FindEXPR_P()) return false;
	return true;*/
	
	if(FindPLUSOP())
	{
		if(PeekToken() == '(')
		{
			AdvanceToken();
			if(FindEXPR())
			{
				if(PeekToken() == ')')
				{
					AdvanceToken();
					if(FindEXPR_P())
					{
						return true;
					}
				}
			}
		}
		
		//Only matches some of EXPR'
		return false;
	}
	
	//Lambda
	return true;
}

bool FindPLUSOP()
{
	int token = PeekToken();
	if (token == '+' || token == '-')
	{
		AdvanceToken();
		return true;
	}
	//AdvanceToken();
	return false;
}

bool FindTERM()
{
	/*if(PeekToken() == INT_VAL)
	{		Error("INT_VAL*");
		AdvanceToken();
		return true;
	}
	
	Error("INT_VAL");
	AdvanceToken();
	
	//[EXPR] TERM'
	if (PeekToken() != '[') {Error("["); return false;} AdvanceToken();
	if (!FindEXPR()) return false;
	if (PeekToken() != ']') {Error("]"); return false;} AdvanceToken();
	if (!FindTERM_P()) return false;
	else {AdvanceToken(); return true;}
	
	return false;*/
	
	//[EXPR] TERM'
	if (PeekToken() == '[')
	{
		AdvanceToken();
		if (FindEXPR())
		{
			//Error("EXPR*");
			//AdvanceToken();
			if (PeekToken() == ']')
			{
				AdvanceToken();
				if (FindTERM_P())
				{
					return true;
				}
			}
			else
			{
				Error("]");
				return false;
			}
		}
	}
	else	
	{
		//num
		if(PeekToken() == INT_VAL)
		{		
			AdvanceToken();
			return true;
		}
	}
	
	//AdvanceToken();
	return false;
}

bool FindTERM_P()
{
	/*//if term' == timesop [expr] term' --> recurse into term'
	if (!FindPLUSOP()) return false;
	//if(![EXPR]) return false;
	if(!FindTERM_P()) return false;
	
	//if term' == lambda --> return true
	return true;*/
	
	//TIMESOP [EXPR] TERM'
	/*if (!FindTIMESOP()) return false;
	if (PeekToken() != '[') {Error("["); return false;} AdvanceToken();
	if (!FindEXPR()) return false;
	if (PeekToken() != ']') {Error("]"); return false;} AdvanceToken();
	if (!FindTERM_P()) return false;
	return true;*/

	if(FindTIMESOP())
	{
		if(PeekToken() == '[')
		{
			AdvanceToken();
			if(FindEXPR())
			{
				if(PeekToken() == ']')
				{
					AdvanceToken();
					if(FindTERM_P())
					{
						return true;
					}
				}
				else
				{
					Error("]");
					return false;
				}
			}
		}
		else
		{
			Error("[");
			return false;
		}
		
		//Only matches some of EXPR'
		return false;
	}
	
	//Lambda
	return true;
}

bool FindTIMESOP()
{
	int token = PeekToken();
	if (token == '*' || token == '/') 
	{
		AdvanceToken();
		return true;
	}
	return false;
}

/*******************************************
bool FindExample()
{
    if (!FindPART1()) return false;
    
    int token = PeekToken();
    if (token != '+') return false;
    AdvanceToken();         // past '+'

    if (!FindPART2()) return false;

    return true;
}
*/

