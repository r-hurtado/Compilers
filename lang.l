%{
//**************************************
// lang.l
//
// Scanner definition file for CST 320 project
//
// Author: Russell Hurtado 
// russell.hurtado@oit.edu
//
// Date: Jan. 12, 2017
//

#include "tokens.h"
#include "lex.h"
#include "symtab.h"

#define DO_RETURN(a) return (a);
//#define DO_RETURN(a) return Return(a);
int Return(int val);

extern SymTab g_SymbolTable;
extern yylval_t yylval;

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


    /* definitions go here. period is an example. */
	
digit                       [0-9]
nonDigit					[_a-zA-Z]
identifier					{nonDigit}({digit}|{nonDigit})*

%%

    // token definitions go here. "if" is an example.
	
	// Keywords
"end"                       DO_RETURN(END);
"if"                        DO_RETURN(IF);
"else"                      DO_RETURN(ELSE);
"while"                     DO_RETURN(WHILE);
"print"                     DO_RETURN(PRINT);
"int"                       DO_RETURN(INT);
"float"                     DO_RETURN(FLOAT);
"struct"                    DO_RETURN(STRUCT);
"return"                    DO_RETURN(RETURN);
"array"                     DO_RETURN(ARRAY);
"char"                      DO_RETURN(CHAR);

"=="	                    DO_RETURN(EQUALS);
"&&"    	                DO_RETURN(AND);
"||"	                    DO_RETURN(OR);

"("                         DO_RETURN('(');
")"                         DO_RETURN(')');
"["                         DO_RETURN('[');
"]"                         DO_RETURN(']');
";"                         DO_RETURN(';');
","                         DO_RETURN(',');
"."                         DO_RETURN('.');
"+"                         DO_RETURN('+');
"-"                         DO_RETURN('-');
"*"                         DO_RETURN('*');
"/"                         DO_RETURN('/');
"%"                         DO_RETURN('%');
"="                         DO_RETURN('=');

"{"                         {
                                g_SymbolTable.IncreaseScope();
                                return yytext[0];
                            }
"}"                         {
                                g_SymbolTable.DecreaseScope();
                                return yytext[0];
                            }

{digit}+                    DO_RETURN(INT_VAL);
{digit}+"."{digit}+			DO_RETURN(FLOAT_VAL);
[\n\r\t ]					{};
"//".*                		{};
.							DO_RETURN(JUNK_TOKEN);

{identifier}                {
                                yylval.symbol = g_SymbolTable.Insert(yytext);
                                return IDENTIFIER;
                            }


%%

// This function allows us to do extra processing on each token
int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}
