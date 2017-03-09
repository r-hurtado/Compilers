#pragma once
//**************************************
// lex.h
//
// Defines global symbols used the the flex generated lexer 
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2016
//
//Modified: Ryan Williams, Feb 21
//

#include "cSymbolTable.h"
#include "cAstNode.h"


extern cSymbolTable g_SymbolTable;
extern bool g_semanticErrorHappened;
int yyparse();                          // parsing function
int yylex();                            // scanning function
extern char *yytext;                    // text of current token
extern int yylineno;                    // line number of input file
extern int yynerrs;                     // Num of compile errors
extern FILE *yyin;                      // FILE pointer for input
extern cAstNode *yyast_root;            // root of AST
