// October 2010
// Author: Fabio Patrizi
// C++ Parser for PDDL 3.0 + planning programs

// directives for C++ code generation
%skeleton "lalr1.cc"
%defines
//

%locations // for location tracking
%debug // for parser tracing
%error-verbose // for verbose error messages

// Includes and namespaces needed to define the %union
%code requires{
	#include <iostream>
	#include <algorithm>
	#include <string>
	#include "ast.h"
	#include "symtable.h"
	#include "planprog.h"
 
 	using namespace::std;
	using namespace::ast;
	using namespace::pprog;
}

%code {
	// Anything defined here is accessible from within rules
	
	#include "defs.h"
	
	// Variables
	SymTable symtable;// The global symbol table
	SymTable context; // For local context

	vector<string>* requirements;	// For access during parsing, to check enabled rules
	
	Type* BASE_TYPE = new Type("base-type");	// default type	
	
	// Function declarations (definitions at the end of this file)

	bool isRequirementDefined(const string &r);	// returns true iff requirement r occurs in requirements
	
	vector<Variable*> createVariables(vector<TypedStringList*>* typedStringList);
	
	Variable* checkDuplicates(vector<Variable*> vars);
	// Checks if two variables with same name occur in vars
	// If so, returns the first duplicate found
	// else returns null
	

	void createActionContext(vector<Variable*> variables); 
	// Inserts variables from variables into context
	// Note if two variables with same name are defined, only the first one is added to context	

	// Definition of symbol classes
	const string DOMAIN = "domain";
	const string TYPE = "type";
	const string CONSTANT = "constant";
	const string PREDICATE = "predicate";
	const string VARIABLE = "variable";
	const string NODE = "node";	
	
}

// Generated parser class name
%define parser_class_name "Pddl30Parser"

// The output parameters of the parsing and scanning functions
%parse-param{Domain& domain}
%parse-param{PlanningProgram& planning_program}
//


%union{
	Domain* domain_ptr;
	Predicate* predicate_ptr;
	Action* action_ptr;
	Effect* effect_ptr;
	PEffect* p_effect_ptr;
	Constant* constant_ptr;
	CEffect* c_effect_ptr;
	vector<CEffect*>* c_effect_list_vec;
	vector<Type*>* type_vec;
	vector<Constant*>* constant_vec; 
	vector<const Predicate*>* predicate_vec; 
	vector<const Action*>* action_vec; 
	vector<string>* string_vec;
	string* string_ptr;
	vector<TypedStringList*>* typed_string_list_vec;
	GD* gd_ptr;
	AtomicFormulaTerm* atomic_formula_term_ptr;
	vector<GD*>* gd_list_vec;
	Term* term_ptr;
	vector<Term*>* term_list_vec;
	vector<Variable*>* typed_list_var_vec;
	Literal* literal_ptr;
	vector<Literal*>* literal_list_vec;
	Problem* problem_ptr;
	vector<InitElement*>* init_elem_list_vec;

	PlanningProgram* planning_program_ptr;
	Transition* transition_ptr;
	Node* node_ptr;
	vector<Transition*>* transition_list_vec;
}

%token END 0 "end of file"
%token DEFINE DOMAIN COL_DOMAIN REQUIREMENTS TK_STRIPS TK_TYPING TYPES CONSTANTS PREDICATES ACTION PARAMETERS PRECONDITION EFFECT AND NOT PLANPROG OBJECTS INIT GOAL INITNODE TRANSITIONS
%token <string_ptr> NAME VARIABLE

%type <domain_ptr> domain
%type <string_ptr> require_key
%type <type_vec> types_def
%type <constant_vec> constants_def object_decl 
%type <predicate_vec> predicates_def predicate_list
%type <predicate_ptr> single_predicate_def
%type <action_ptr> single_action_def
%type <action_vec> actions_def actions_def_list
%type <string_vec> untyped_list_name untyped_list_variable require_def require_list
%type <typed_string_list_vec> typed_list_name 
%type <gd_ptr> gd precondition goal
%type <gd_list_vec> gd_list
%type <atomic_formula_term_ptr> atomic_formula_term atomic_formula_name
%type <term_ptr> term
%type <term_list_vec> term_list const_list
%type <typed_list_var_vec> typed_list_variable parameters
%type <effect_ptr> effect
%type <p_effect_ptr> p_effect
%type <c_effect_ptr> c_effect
%type <c_effect_list_vec> c_effect_list
%type <literal_ptr> literal_term literal_name
%type <init_elem_list_vec> init_elem_list init
%type <constant_ptr> constant_ref

%type <planning_program_ptr> planning_program
%type <transition_ptr> transition
%type <transition_list_vec> transition_list
%type <node_ptr> node 

%%

specfication:
	domain planning_program {
		domain = *$1;
		planning_program = *$2;
	}
	;

domain:
	'(' DEFINE '(' DOMAIN NAME ')' require_def {requirements = $7;} types_def constants_def predicates_def actions_def ')' {
		// Add the base type
		$9 -> push_back(BASE_TYPE);
		$$ = new Domain(*$5, *$7 , *$9, *$10, *$11, *$12);
		symtable.add($$,DOMAIN);
		delete ($5);
		delete ($9);
		delete ($10);
		delete ($11);
		delete ($12);
	}
	;
	
		
/*** require_def ***/

require_def:
	/* empty */ {
		$$ = new vector<string>();
		$$ -> push_back(STRIPS);
	}
	|
	/* leading '(' eaten by token, to avoid s/r conflicts when empty */
	REQUIREMENTS require_list ')' {
		$$ = $2;
	}
	;
	
require_list:
	require_list require_key {
		$$ = $1;
		$$ -> push_back(*$2);
		delete($2);
	}
	|
	require_key{
		$$ = new vector<string>();
		$$ -> push_back(*$1);
		delete($1);
	};
	
require_key:
	TK_STRIPS {$$ = new string(STRIPS);}
	|
	TK_TYPING {$$ = new string(TYPING);}
	;
	
/********************/
	
	
/******* types_def ******/
types_def:
	/* empty */ {
		$$ = new vector<Type*>();
	}
	|
	/* leading '(' eaten by token, to avoid s/r conflicts when empty */
	TYPES typed_list_name ')' {
		if (!isRequirementDefined(TYPING)){
			error(yylloc, string("type definition not enabled (use :typing)"));			
			exit(1);
		}
		$$ = new vector<Type*>();
		for (unsigned int i = 0; i < $2 -> size(); i++){
			TypedStringList* curTypedStringList = (*$2)[i];
			vector<string> typeNameList = curTypedStringList -> getStrings();
			string* superTypeName = curTypedStringList -> getTypeString();
			Type* superType = BASE_TYPE;
			
			// Extracts the current superType (if any) from the symtable
			if (superTypeName != NULL){
				superType = (Type*)(symtable.get(*superTypeName,TYPE));
				if (superType == NULL){
					// superType not present, we add it
					superType = new Type(*superTypeName, BASE_TYPE);
					symtable.add(superType, TYPE);
					$$ -> push_back(superType);
				}
			}
			
			// Iterate on (sub)types
			for (unsigned int j = 0; j < typeNameList.size(); j++){
				// Check if the type is in the table
				string curName = typeNameList[j];
				Type* type = (Type*)(symtable.get(curName,TYPE));
				if (type != NULL){ // Error: type already defined
					error(yylloc, string("type \"") + curName + string("\" already defined (does it appear as a super type?)"));
					exit(1);
				}
				type = new Type(curName,superType);
				symtable.add(type,TYPE);
				$$ -> push_back(type);
			}
		}
		delete($2);
	}
	;
/********************/


/*** constants_def ***/

constants_def:
	/* empty */{
		$$ = new vector<Constant*>();
	}
	|
	/* leading '(' eaten by token, to avoid s/r conflicts when empty */
	CONSTANTS typed_list_name ')' {
		$$ = new vector<Constant*>();
		for (unsigned int i = 0; i < $2 -> size(); i++){
			TypedStringList* curTypedStringList = (*$2)[i];
			vector<string> constNameList = curTypedStringList -> getStrings();
			string* typeName = curTypedStringList -> getTypeString();
			Type* type = BASE_TYPE; // default type
			
			// Extracts the current type (if any) from the symtable
			if (typeName != NULL){
				type = (Type*)(symtable.get(*typeName,TYPE));
				if (type == NULL){// The type has not been declared: error!
					error(yylloc, string("type \"") + *typeName + string("\" not defined"));
					exit(1);
				}
			}
			
			// Iterate on constants
			for (unsigned int j = 0; j < constNameList.size(); j++){
				// Check if the constant is already defined
				string curName = constNameList[j];
				Constant* constant = (Constant*)(symtable.get(curName,CONSTANT));
				if (constant != NULL){
					//Error: constant already defined
					error(yylloc, string("constant \"") + curName + string("\" already defined"));
					exit(1);
				}
				constant = new Constant(curName,type);
				symtable.add(constant,CONSTANT);
				$$ -> push_back(constant);
			}
		}	
		delete ($2);
	}
	;
	

/********************/

/*** predicates_def ***/

predicates_def:
	/* empty */{
		$$ = new vector<const Predicate*>();
	}
	|
	/* leading '(' eaten by token, to avoid s/r conflicts when empty */
	PREDICATES predicate_list ')' {
		$$ = $2;
	}
	;

predicate_list:
	single_predicate_def{
		$$ = new vector<const Predicate*>();
		$$ -> push_back($1);
	}
	|
	predicate_list single_predicate_def{
		$$ = $1;
		$1 -> push_back($2);
	}
	;
	
single_predicate_def:
	'(' NAME typed_list_variable ')'{
		// Check if the predicate is already defined
		Predicate* newPred = (Predicate*)(symtable.get(*$2,PREDICATE));
		if (newPred != NULL){// The new predicate has been already defined: error!
			error(yylloc, string("predicate \"") + *$2 + string("\" already defined"));
			exit(1);
		}
		// Build new predicate
		newPred = new Predicate(*$2,*$3);
		symtable.add(newPred, PREDICATE);
		$$ = newPred;
		delete($2);
		delete($3);
	}
	;

	
/********************/

/*** actions_def ***/
actions_def :
	actions_def_list {
		$$ = $1;
	}
	;
	
actions_def_list:
	/* empty */ {
		$$ = new vector<const Action*>();
	}
	|
	actions_def_list single_action_def{
		$$ = $1;
		$$ -> push_back($2);
	}
	;

single_action_def:
	/* leading '(' eaten by token, to avoid s/r conflicts when empty */
	ACTION NAME parameters {createActionContext(*$3);} precondition effect ')' {
		// Check duplicates in parameters
		Variable* duplicate = checkDuplicates(*$3);
		if (duplicate != NULL){
			// Duplicate varibale in action argument: error
			error(yylloc, string("parameter \"") + duplicate->getName() + string("\" in action \"") + *$2 + string("\" not unique"));
			exit(1);
		}
		
		$$ = new Action(*$2, *$3, $5, $6);
		delete($2);
		delete($3);
		
		context.clear();
	}
	;
	
parameters:
	/* empty */{
		$$ = new vector<Variable*>();
	}
	|
	PARAMETERS '(' typed_list_variable ')'{
		$$ = $3;
	}
	;
	
precondition:
	/* empty */{
		$$ = NULL;
	}
	|
	PRECONDITION '(' ')'{
		$$ = NULL;
	}
	|
	PRECONDITION gd {
		$$ = $2;
	}
	;
		
gd:
	atomic_formula_term{
		$$ = new GD(new Literal($1));
	}
    |
    '(' NOT atomic_formula_term ')'{
        $$ = new GD(new Literal($3,true));
    }
	|
	'(' AND gd_list ')'{
		$$ = new GD(*$3);
		delete($3);
	}
	;
	
gd_list:
	/* empty */{
		$$ = new vector<GD*>();
	}
	|
	gd_list gd{
		$$ = $1;
		$$ -> push_back($2);
	}
	;
	
		
atomic_formula_term:
	'(' NAME term_list ')'{
		Predicate* predicate = (Predicate*)(symtable.get(*$2,PREDICATE));
		// Check if predicate is defined
		if (predicate == NULL){
			error(yylloc, string("predicate \"") + *$2 + string("\" not defined"));
			exit(1);
		}
		
		$$ = new AtomicFormulaTerm(predicate,*$3);
		
		// Check if term_list size matches predicate arity
		if (!$$ -> isArityConsistent()){
			error(yylloc, string("number of terms does not match arity of predicate \"") + *$2 + "\"");
			exit(1);
		}
		
		// Check if term_list types match predicate arguments types
		Term* badTerm = $$ -> isTypeConsistent();	
		if (badTerm != NULL){
			error(yylloc, string("term \"") + badTerm -> getName() + "\" does not match predicate \"" + *$2 + "\" argument type");
			exit(1);
		}
		delete($2);
		delete($3);
				
	}
	;
	
	
atomic_formula_name:
	'(' NAME const_list ')'{
		Predicate* predicate = (Predicate*)(symtable.get(*$2,PREDICATE));
		// Check if predicate is defined
		if (predicate == NULL){
			error(yylloc, string("predicate \"") + *$2 + string("\" not defined"));
			exit(1);
		}
		
		$$ = new AtomicFormulaTerm(predicate,*$3);
		
		// Check if term_list size matches predicate arity
		if (!$$ -> isArityConsistent()){
			error(yylloc, string("number of terms does not match arity of predicate \"") + *$2 + "\"");
			exit(1);
		}
		
		// Check if term_list types match predicate arguments types
		Term* badTerm = $$ -> isTypeConsistent();		
		if (badTerm != NULL){
			error(yylloc, string("term \"") + badTerm -> getName() + "\" does not match predicate \"" + *$2 + "\" argument type");
			exit(1);
		}
		delete($2);
		delete($3);
	}
	;
	
const_list:
	/* empty */{
		$$ = new vector<Term*>();
	}
	|
	const_list constant_ref{
		$$ = $1;
		$$ -> push_back($2);
	}
	;
	
constant_ref:
	NAME{
		Constant* constant = (Constant*)(symtable.get(*$1,CONSTANT));
		if (constant == NULL){// Undefined constant: error
			error(yylloc, string("constant \"") + *$1 + string("\" not defined"));
			exit(1);
		}
		delete ($1);
		$$ = constant;
	}
	;
	

term_list:
	/* empty */{
		$$ = new vector<Term*>();
	}
	|
	term_list term{
		$$ = $1;
		$$ -> push_back($2);
	}
	;

term:
	constant_ref{
		$$ = $1;
	}
	|
	VARIABLE{
		Variable* variable = (Variable*)(context.get(*$1,VARIABLE));
		if (variable == NULL){// Undefined constant: error
			error(yylloc, string("variable \"") + *$1 + string("\" not defined"));
			exit(1);
		}
		$$ = variable;
		
	}
	;


	
effect:
	/* empty */{
		$$ = NULL;
	}
	|
	EFFECT '(' ')'{
		$$ = NULL;
	}
	|
	EFFECT '(' AND c_effect_list ')'{
		$$ = new Effect(*$4);
		delete($4);
	}
	|
	EFFECT	c_effect{
		$$ = new Effect($2);
	}
	;
	
c_effect:
	p_effect{
		$$ = new CEffect($1);
	}
	;

c_effect_list:
	/* empty */{
		$$ = new vector<CEffect*>();
	}
	|
	c_effect_list c_effect{
		$$ = $1;
		$1 -> push_back($2);
	}
	;


p_effect:
	literal_term{
		$$ = new PEffect($1);
	}
	;

literal_term:
	'(' NOT  atomic_formula_term ')'{
		$$ = new Literal($3,true);
	}
	|
	atomic_formula_term{
		$$ = new Literal($1,false);
	}
	;
	
literal_name:
	'(' NOT  atomic_formula_name ')'{
		$$ = new Literal($3,true);
	}
	|
	atomic_formula_name{
		$$ = new Literal($1,false);
	}
	;
	

/********************/


/*** typed_list_name ***/

typed_list_name:
	/* empty */{
		$$ = new vector<TypedStringList*>();
	}
	|
	 typed_list_name untyped_list_name '-' NAME{
		$$ = $1;
		$$ -> push_back(new TypedStringList(*$2, $4));
		delete($2);
	}
	|
	typed_list_name untyped_list_name{
		$$ = $1;
		$$ -> push_back(new TypedStringList(*$2));
		delete($2);		
	}
	;
	
untyped_list_name:
	NAME {
		$$ = new vector<string>();
		$$ -> push_back(*$1);
	}
	|
	untyped_list_name NAME{
		$1 -> push_back(*$2);
		$$ = $1;
	};

/********************/

/*** typed_list_variable ***/

typed_list_variable:
	/* empty */{
		$$ = new vector<Variable*>();		
	}
	|
	 typed_list_variable untyped_list_variable '-' NAME{
		Type* type = (Type*)(symtable.get(*$4,TYPE));
		if (type == NULL){// Undeclared type: error!
			error(yylloc, string("type \"") + *$4 + string("\" not defined"));
			exit(1);
		}		
		$$ = $1;
		for (unsigned int i = 0; i < $2 -> size(); i++){
			$$ -> push_back(new Variable((*$2)[i], type));
		}
		delete($2);
		delete($4);		
	}
	|
	typed_list_variable untyped_list_variable{
		$$ = $1;
		for (unsigned int i = 0; i < $2 -> size(); i++){
			$$ -> push_back(new Variable((*$2)[i], BASE_TYPE));
		}
		delete($2);
	}
	;
	
untyped_list_variable:
	VARIABLE {
		$$ = new vector<string>();
		$$ -> push_back(*$1);
	}
	|
	untyped_list_variable VARIABLE{
		$1 -> push_back(*$2);
		$$ = $1;
	};
/********************/


/*** planning_program ****/

planning_program: 
	'(' DEFINE '(' PLANPROG NAME ')' '(' COL_DOMAIN NAME ')' object_decl init '(' INITNODE node ')' '(' TRANSITIONS transition_list ')' ')'{
		// Check if the domain is defined
		Domain* domain = (Domain*)(symtable.get(*$9,DOMAIN));
		if (domain == NULL){
			// Error: problem not defined on current domain
			error(yylloc, string("planning program \"") + *$5 + "\" defined on domain \""+ *$9 + "\", which is undefined");
			exit(1);
		}
		$$ = new PlanningProgram(*$5, domain, *$11, *$12, $15, *$19);
		delete($5);
		delete($9);
		delete($11);
		delete($12);
		delete($19);
	}
	;

/*** transition_list ***/
transition_list:
	/* empty */{
		$$ = new vector<Transition*>();
	}
	|
	transition_list transition {
		$$ = $1;
		$$ -> push_back($2);
	}
	;
	
transition:
	'(' node node gd ')'{
		$$ = new Transition($2, $3, $4);		
	}
	;
	
node: 
	NAME {
		// Check if the node is already defined
		Node* node = (Node*)(symtable.get(*$1,NODE));
		
		if (node == NULL){// Not defined, defining here			
			node = new Node(*$1);
			symtable.add(node, NODE);
		}		
		$$ = node;
		delete ($1);
	};
	
/*******************/

		
/*** object_decl ***/

object_decl:
	/* empty */{
		$$ = new vector<Constant*>();
	}
	|
	/* leading '(' eaten by token, to avoid s/r conflicts when empty */
	OBJECTS typed_list_name ')' {
		$$ = new vector<Constant*>();
		for (unsigned int i = 0; i < $2 -> size(); i++){
			TypedStringList* curTypedStringList = (*$2)[i];
			vector<string> constNameList = curTypedStringList -> getStrings();
			string* typeName = curTypedStringList -> getTypeString();
			Type* type = BASE_TYPE; // default type
			
			// Extracts the current type (if any) from the symtable
			if (typeName != NULL){
				type = (Type*)(symtable.get(*typeName,TYPE));
				if (type == NULL){// The type has not been declared: error!
					error(yylloc, string("type \"") + *typeName + string("\" not defined"));
					exit(1);
				}
			}
			
			// Iterate on constants
			for (unsigned int j = 0; j < constNameList.size(); j++){
				// Check if the constant is already defined
				string curName = constNameList[j];
				Constant* constant = (Constant*)(symtable.get(curName,CONSTANT));
				if (constant != NULL){
					//Error: constant already defined
					error(yylloc, string("constant \"") + curName + string("\" already defined"));
					exit(1);
				}
				constant = new Constant(curName,type);
				symtable.add(constant,CONSTANT);
				$$ -> push_back(constant);
			}
		}	
		delete ($2);
	}
	;
	

/********************/
		

/****** init ********/
init:
	'(' INIT init_elem_list')' {
		$$ = $3;
	}
	;
	
init_elem_list:
	/* empty */{
		$$ = new vector<InitElement*>();
	}
	|
	init_elem_list literal_name{
		$$ = $1;
		$$ -> push_back(new InitElement($2));
	}
	;
/********************/

/******* goal *******/
goal:
	'(' GOAL gd ')'{
		$$ = $3;
	}
	;

/********************/

%%


void yy::Pddl30Parser::error(const yy::location& l, const string& message){
	cerr << l << " : error : " << message << endl;
}

bool isRequirementDefined(const string& r){
		return (find(requirements -> begin(),requirements -> end(),r) != requirements -> end());
}
	
void createActionContext(vector<Variable*> variables){
	// Note if two variables with same are defined, only the first one is added to context
	for (unsigned int i = 0; i < variables.size(); i++){
		context.add(variables[i],VARIABLE);
	}
}

vector<Variable*> createVariables(vector<TypedStringList*>* typedStringList){
	vector<Variable*> result;
	for (unsigned int i = 0; i < typedStringList -> size(); i++){
		TypedStringList* curTypedStringList = (*typedStringList)[i];
		string* curTypeName = curTypedStringList -> getTypeString();
		Type* curType = NULL;
		
		if (curTypeName == NULL){// No type specified, using default BASE_TYPE
			curType = BASE_TYPE;
		}
		else{// Type specified, check if it exists
			curType = (Type*)(symtable.get(*curTypeName,TYPE));
			if (curType == NULL){
				cerr << "Unexpected empty type!" << endl;
				exit(1);
			}
		}
		
		// Iterate over all variable names, build the variables and add them to result
		vector<string> curVarNames = curTypedStringList -> getStrings();
		for (unsigned int j = 0; j < curVarNames.size(); j++){
			//No duplicate check!
			result.push_back(new Variable(curVarNames[j],curType));
		}
	}
	return result;
}


Variable* checkDuplicates(vector<Variable*> vars){
	// Checks if two variables with same name occur in vars
	// If so, returns the first duplicate found
	// else returns null
	for (unsigned int i = 0; i < vars.size(); i++){
		for (unsigned int j = i+1; j < vars.size(); j++){
			if (vars[i]->getName() == vars[j]->getName()){
				return vars[j];
			}
		}
	}
	return NULL;
}

