%{
//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Ryan Williams 
// ryan.williams@oit.edu
//
// Date: Jan. 18, 2015
//

#include <iostream>
#include "lex.h"
#include "astnodes.h"

%}

%locations

 /* define the type used for returning lexical values */
%union{
    int             int_val;
    double          float_val;
    cAstNode*       ast_node;
    cProgramNode*   program_node;
    cBlockNode*     block_node;
    cStmtsNode*     stmts_node;
    cStmtNode*      stmt_node;
    cExprNode*      expr_node;
    cVarExprNode*   varexpr_node;
    cSymbol*        symbol;
    cSymbolTable::symbolTable_t*   sym_table;
    cDeclNode*      decl_node;
    cDeclsNode*     decls_node;
    cAssignNode*    assign_node;
    cParamsNode*    params_node;
    cParamListNode* paramlist_node;
    cFuncDeclNode*  funcdecl_node;
    cFuncExprNode*  funcexpr_node;	    
    }

%{
    // function to call when errors happen
    int yyerror(const char *msg);

    // Root of the AST node. Returned by the parser on success.
    cAstNode *yyast_root;
%}

%start  program

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID
%token <int_val>   CHAR_VAL
%token <int_val>   INT_VAL
%token <float_val> FLOAT_VAL

%token  PRINT
%token  WHILE IF ELSE ENDIF
%token  STRUCT
%token  RETURN
%token  AND OR EQUALS
%token  JUNK_TOKEN

 /* NOTE: you will have to change some of these as you complete your lab */
%type <program_node> program
%type <block_node> block
%type <sym_table> open
%type <sym_table> close
%type <decls_node> decls
%type <decl_node> decl
%type <decl_node> var_decl
%type <decl_node> struct_decl
%type <funcdecl_node> func_decl
%type <funcdecl_node>  func_header
%type <funcdecl_node>  func_prefix
%type <funcexpr_node> func_call
%type <params_node> paramsspec
%type <decl_node> paramspec
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <varexpr_node> lval
%type <paramlist_node> params
%type <expr_node> param
%type <expr_node> expr
%type <expr_node> term
%type <expr_node> fact
%type <varexpr_node> varref
%type <symbol> varpart
%type <expr_node> addit

%%

program: block                  { $$ = new cProgramNode($1);
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:  open decls stmts close  { $$ = new cBlockNode($2, $3); }
    |   open stmts close        { $$ = new cBlockNode(nullptr, $2); }

open:   '{'                     {
                                  $$ = g_SymbolTable.IncreaseScope();
                                }

close:  '}'                     {
                                  $$=g_SymbolTable.DecreaseScope();
                                }

decls:      decls decl          {$$ = $1; $$->Insert($2);}
        |   decl                {$$ = new cDeclsNode($1);}
decl:       var_decl ';'        { $$ = $1; }
        |   struct_decl ';'     {$$ = $1;}
        |   func_decl           {$$ = $1;}
        |   error ';'           {}

var_decl:   TYPE_ID IDENTIFIER  { $$ = new cVarDeclNode($1, $2);}
var_decl:   STRUCT IDENTIFIER IDENTIFIER {$$ = new cVarDeclNode($2,$3);}

struct_decl:  STRUCT open decls close IDENTIFIER    
                                {$$ = new cStructDeclNode($3, $5);}
func_decl:  func_header ';'
                                {$$ = $1; g_SymbolTable.DecreaseScope();}
        |   func_header  '{' decls stmts '}'
                                {$$= $1; $$->Insert($3);$$->Insert($4);g_SymbolTable.DecreaseScope();}
        |   func_header  '{' stmts '}'
                                {$$= $1; $$->Insert($3);g_SymbolTable.DecreaseScope();}
func_header: func_prefix paramsspec ')'
                                {$$=$1; $$->Insert($2);}
        |    func_prefix ')'    {$$ = $1;}
func_prefix: TYPE_ID IDENTIFIER '('
                                {$$ = new cFuncDeclNode($1,$2); g_SymbolTable.IncreaseScope();}
paramsspec:     
            paramsspec',' paramspec 
                                {$$ = $1; $$->AddChild($3);}
        |   paramspec           {$$ = new cParamsNode($1);}

paramspec:  var_decl            {$$=$1;}

stmts:      stmts stmt          { $$ = $1; $$->Insert($2); }
        |   stmt                { $$ = new cStmtsNode($1); }

stmt:       IF '(' expr ')' stmts ENDIF ';'
                                { $$ = new cIfNode($3, $5);}//single statment
        |   IF '(' expr ')' stmts ELSE stmts ENDIF ';'
                                { $$ = new cIfNode($3, $5, $7);}//multiple statments
        |   WHILE '(' expr ')' stmt
                                { $$ = new cWhileNode($3, $5);}
        |   PRINT '(' expr ')' ';'
                                { $$ = new cPrintNode($3); }
        |   lval '=' expr ';'  
        			 { $$ = new cAssignNode($1, $3);}
        |   lval '=' func_call ';'  
        			 { $$ = new cAssignNode($1, $3);}
        |   func_call ';'       {$$ = $1;}
        |   block               {$$ = $1;}
        |   RETURN expr ';'     { $$ = new cReturnNode($2);}
        |   error ';'           {}

func_call:  IDENTIFIER '(' params ')' {$$ = new cFuncExprNode($1);
					$$->AddPrams($3);
					g_SymbolTable.IncreaseScope();
					}
        |   IDENTIFIER '(' ')'  {$$ = new cFuncExprNode($1); g_SymbolTable.IncreaseScope(); }

varref:   varref '.' varpart    { $$ = $1; $$->AddChild($3);}
        | varpart               { $$ = new cVarExprNode($1);}

varpart:  IDENTIFIER            { $$ = $1;}

lval:     varref                { $$ = $1;}

params:     params',' param     {$$ = $1; $$->AddChild($3);}
        |   param               {$$ = new cParamListNode($1);}

param:      expr                {$$ = $1;}

expr:       expr EQUALS addit   {$$ =  new cBinaryExprNode($1, "==", $3);}
        |   addit		{$$ =  $1;}
        
addit:      addit '+' term       { $$ = new cBinaryExprNode( $1, "+", $3);}
        |   addit '-' term       { $$ = new cBinaryExprNode( $1, "-", $3);}
        |   term                { $$ = $1; }

term:       term '*' fact       { $$ = new cBinaryExprNode($1,"*",$3);}
        |   term '/' fact       { $$ = new cBinaryExprNode($1,"/",$3);}
        |   term '%' fact       { $$ = new cBinaryExprNode($1,"%",$3);}
        |   fact                { $$ = $1; }

fact:       '(' expr ')'        { $$ = $2;}
        |   INT_VAL             { $$ = new cIntExprNode($1); }
        |   FLOAT_VAL           { $$ = new cFloatExprNode($1);}
        |   varref              {$$ = $1;}

%%

// function for formatting error messages
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
