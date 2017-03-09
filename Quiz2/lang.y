%{
//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Russ Hurtado
// russell.hurtado@oit.edu
//
// Date: Feb. 16, 2017
//
#include <iostream>
#include "lex.h"
#include "astnodes.h"

%}

%locations

 /* union defines the type for lexical values */
%union{
    int             int_val;
    cAstNode*       ast_node;
    cProgramNode*   program_node;
    cSymbol*        symbol;
	cOtherNode*		other_node;
	cSaabNode*		saab_node;
	cExprNode*		expr_node;
	cGloopsNode*	gloop_node;
	cSaab1Node*		saab1_node;
	cSaabNode*		saab2_node;
	cBlobNode*		blob_node;
	cFactNode*		fact_node;
    }

%{
    int yyerror(const char *msg);

    cAstNode *yyast_root;
%}

%start  program

%token <symbol>    IDENTIFIER
%token <int_val>   INT_VAL

%token  CAR TRAIN PLANE BOAT
%token  JUNK_TOKEN

%type <program_node> program
%type <other_node> other
%type <fact_node> fact
%type <saab_node> saab
%type <saab1_node> saab1
%type <saab2_node> saab2
%type <gloop_node> gloops 
%type <blob_node> blob
%type <expr_node> expr
%type <expr_node> term

%%

program: other                  { $$ = new cProgramNode($1);
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }

other:  '{' saab gloops '}'    { $$ = new cOtherNode($2, $3); }

saab:       saab1 ';'          { $$ = $1; }
        |   saab2 ';'          { $$ = $1; }

saab1:   IDENTIFIER '+' IDENTIFIER              { $$ = new cSaab1Node($1, $3); }
saab2:   IDENTIFIER IDENTIFIER '[' INT_VAL ']'  { $$ = new cSaab2Node($1, $2, $4); }

gloops:   gloops blob           { $$ = $1; $$->Insert($2); }
        | blob                  { $$ = new cGloopsNode($1); }

blob:       CAR fact ',' expr TRAIN ';'  { $$ = new cCarNode($2, $4); }
        |   BOAT '[' INT_VAL ']' ';'     { $$ = new cBoatNode($3); }
        |   PLANE saab ';'              { $$ = new cPlaneNode($2); }
        |   other                        { $$ = $1; }

expr:       expr '+' term       { $$ = new cBinaryExprNode($1, '+', $3); }
        |   expr '-' term       { $$ = new cBinaryExprNode($1, '-', $3); }
        |   term                { $$ = $1; }

term:       term '*' fact       { $$ = new cBinaryExprNode($1, '*', $3); }
        |   term '/' fact       { $$ = new cBinaryExprNode($1, '/', $3); }
        |   term '%' fact       { $$ = new cBinaryExprNode($1, '%', $3); }
        |   fact                { $$ = $1; }

fact:        '(' expr ')'       { $$ = new cFactNode($2); }
        |   INT_VAL             { $$ = new cFactNode(new cIntExprNode($1)); }

%%

// Function to format error messages
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
