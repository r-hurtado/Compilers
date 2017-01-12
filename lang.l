%{
//**************************************
// lang.l
//
// Scanner definition file for CST 320 project
//
// Author: Russell Hurtado 
// phil.howard@oit.edu
//
// Date: Nov. 23, 2015
//

#include "tokens.h"

#define DO_RETURN(a) return (a)
//#define DO_RETURN(a) return Return(a)
int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


    /* definitions go here. period is an example. */
leftParenthesis				['(']
rightParenthesis         	[')']
leftCurly          			['{']
rightCurly          		['}']
leftBracket          		['[']
rightBracket          		[']']
semiColon          			[';']
comma         				[',']
period          			['.']
plus          				['+']
minus          				['-']
asterisk          			['*']
forwardSlash          		['/']
modulos          			['%']
equal          				['=']

digit                       [0-9]
nonDigit					[_a-zA-Z]

%%

    // token definitions go here. "if" is an example.
	
	// Keywords
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
"{"                         DO_RETURN('{');
"}"                         DO_RETURN('}');
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

{digit}+                    DO_RETURN(INT_VAL);
{digit}+"."{digit}+			DO_RETURN(FLOAT_VAL);
[\n\r\t ]					{};
"//".*                		{};
{nonDigit}({digit}|{nonDigit})*	DO_RETURN(IDENTIFIER);
.							DO_RETURN(JUNK_TOKEN);

%%

// This function allows us to do extra processing on each token
int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}

