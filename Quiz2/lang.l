%{
//**************************************
// lang.l
//
// scanner definition file. flex uses this file to create the scanner
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 22, 2016
//

#include "cSymbol.h"
#include "lex.h"
#include "astnodes.h"
#include "langparse.h"

// Macros that can be used to create debug output from the scanner
// The first one does NOT create debug output, the second does.
// Uncomment one or the other then use DO_RETURN(val) for all your return 
// statements
#define DO_RETURN(a) { return (a); }
//#define DO_RETURN(a) { return Return(a); }

int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


    /* definitions go here. period is an example. */
%%

    // token definitions 
[\t\n\t ]*                  ;   /* Ignore whitespace */
[,{}()\[\];+\-*/%]           { 
                                yylval.int_val = yytext[0];
                                DO_RETURN(yytext[0]);
                            }
"car"                       DO_RETURN(CAR);
"train"                     DO_RETURN(TRAIN);
"plane"                     DO_RETURN(PLANE);
"boat"                      DO_RETURN(BOAT);
[a-zA-Z_][a-zA-Z0-9_]*      { 
                              yylval.symbol = new cSymbol(yytext); 
                              DO_RETURN(IDENTIFIER);
                            }
[0-9]+                      {
                                yylval.int_val = atoi(yytext); 
                                DO_RETURN(INT_VAL); 
                            }
"//".*"\n"                  ;   /* Ignore comments */
.                           DO_RETURN(JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
// It is used to generate lexer debug info
int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}

