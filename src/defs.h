/* Fabio Patrizi, October 2010
 * This file includes the definitions shared by the parser and the scanner
 */

#ifndef PDDL30PARSER_DEFS_H_
#define PDDL30PARSER_DEFS_H_

	#include "grammar.tab.hh"
	
	#define YY_DECL yy::Pddl30Parser::token_type yylex(yy::Pddl30Parser::semantic_type* yylval, yy::Pddl30Parser::location_type* yylloc)
	YY_DECL;

#endif /*PDDL30PARSER_DEFS_H_*/


