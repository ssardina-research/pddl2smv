/* 
Created: October 2010
Author: Fabio Patrizi

This file was written starting from the C++ scanner example
at page 130 of the Bison 2.4.3 manual (v. 5 August 2010)
Please refer to that for any clarification
*/

%{
	#include "defs.h"	
	#include "grammar.tab.hh"

	// Type shortcuts
	typedef yy::Pddl30Parser parser;
	typedef parser::token token;
	typedef parser::token_type token_type;
	
	// Modify yyterminate() to return a token (by default it returns an int)
	#define yyterminate() return token::END
%}

%option nounput

/* Abbreviations */

char [a-zA-Z_]
digit [0-9]
string {char}+(-|{char}|{digit})*
blank [ \t]
comment ;.*

%{
	#define YY_USER_ACTION yylloc -> columns(yyleng);
%}

%%

%{
	yylloc -> step();
%}

{blank}+ {yylloc -> step();}

{comment} {}

[\n]+	{
	yylloc -> lines(yyleng);
	yylloc -> step();
}

[()-] {return token_type (yytext[0]);}
 
"define" {return token::DEFINE;}
"domain" {return token::DOMAIN;}
"planprog" {return token::PLANPROG;}
":init" {return token::INIT;}
":initnode" {return token::INITNODE;}
":transitions" {return token::TRANSITIONS;}
":goal" {return token::GOAL;}
":domain" {return token::COL_DOMAIN;}
 
"("({blank}|\n)*":requirements" {yyless(1); yylloc -> end = yylloc -> begin; yylloc -> columns(1);}
"("({blank}|\n)*":types" {yyless(1); yylloc -> end = yylloc -> begin; yylloc -> columns(1);}
"("({blank}|\n)*":constants" {yyless(1); yylloc -> end = yylloc -> begin; yylloc -> columns(1);}
"("({blank}|\n)*":predicates" {yyless(1); yylloc -> end = yylloc -> begin; yylloc -> columns(1);}
"("({blank}|\n)*":action" {yyless(1); yylloc -> end = yylloc -> begin; yylloc -> columns(1);}
"("({blank}|\n)*":objects" {yyless(1); yylloc -> end = yylloc -> begin; yylloc -> columns(1);}

":objects" {return token::OBJECTS;}
":requirements" {return token::REQUIREMENTS;}
":types" {return token::TYPES;}
":constants" {return  token::CONSTANTS;}
":predicates" {return  token::PREDICATES;}
":action" {return  token::ACTION;}

":parameters" {return  token::PARAMETERS;}
":precondition" {return token::PRECONDITION;}
":effect" {return  token::EFFECT;}
":strips" {return  token::TK_STRIPS;}
":typing" {return  token::TK_TYPING;}

"and" {return  token:: AND;}
"not" {return  token:: NOT;}

"?"{string} {
	yylval -> string_ptr = new string(yytext);
	return token::VARIABLE;
}


{string} {
	yylval -> string_ptr = new string(yytext);
	return token::NAME;
}

%%

/* User code section */

int yywrap(){
	return 1;
}

