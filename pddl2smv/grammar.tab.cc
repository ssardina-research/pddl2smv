
/* A Bison parser, made by GNU Bison 2.4.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */


/* Line 311 of lalr1.cc  */
#line 41 "grammar.tab.cc"


#include "grammar.tab.hh"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 50 "grammar.tab.cc"
/* Unqualified %code blocks.  */

/* Line 318 of lalr1.cc  */
#line 26 "grammar.yy"

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
	



/* Line 318 of lalr1.cc  */
#line 96 "grammar.tab.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace yy {

/* Line 380 of lalr1.cc  */
#line 165 "grammar.tab.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Pddl30Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Pddl30Parser::Pddl30Parser (Domain& domain_yyarg, Problem& problem_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      domain (domain_yyarg),
      problem (problem_yyarg)
  {
  }

  Pddl30Parser::~Pddl30Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Pddl30Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Pddl30Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Pddl30Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Pddl30Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Pddl30Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Pddl30Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Pddl30Parser::debug_level_type
  Pddl30Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Pddl30Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Pddl30Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 138 "grammar.yy"
    {
		domain = *(yysemantic_stack_[(2) - (1)].domain_ptr);
		problem = *(yysemantic_stack_[(2) - (2)].problem_ptr);
	}
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 145 "grammar.yy"
    {requirements = (yysemantic_stack_[(7) - (7)].string_vec);}
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 145 "grammar.yy"
    {
		// Add the base type
		(yysemantic_stack_[(13) - (9)].type_vec) -> push_back(BASE_TYPE);
		(yyval.domain_ptr) = new Domain(*(yysemantic_stack_[(13) - (5)].string_ptr), *(yysemantic_stack_[(13) - (7)].string_vec) , *(yysemantic_stack_[(13) - (9)].type_vec), *(yysemantic_stack_[(13) - (10)].constant_vec), *(yysemantic_stack_[(13) - (11)].predicate_vec), *(yysemantic_stack_[(13) - (12)].action_vec));
		symtable.add((yyval.domain_ptr),DOMAIN);
		delete ((yysemantic_stack_[(13) - (5)].string_ptr));
		delete ((yysemantic_stack_[(13) - (9)].type_vec));
		delete ((yysemantic_stack_[(13) - (10)].constant_vec));
		delete ((yysemantic_stack_[(13) - (11)].predicate_vec));
		delete ((yysemantic_stack_[(13) - (12)].action_vec));
	}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 162 "grammar.yy"
    {
		(yyval.string_vec) = new vector<string>();
		(yyval.string_vec) -> push_back(STRIPS);
	}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 168 "grammar.yy"
    {
		(yyval.string_vec) = (yysemantic_stack_[(3) - (2)].string_vec);
	}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 174 "grammar.yy"
    {
		(yyval.string_vec) = (yysemantic_stack_[(2) - (1)].string_vec);
		(yyval.string_vec) -> push_back(*(yysemantic_stack_[(2) - (2)].string_ptr));
		delete((yysemantic_stack_[(2) - (2)].string_ptr));
	}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 180 "grammar.yy"
    {
		(yyval.string_vec) = new vector<string>();
		(yyval.string_vec) -> push_back(*(yysemantic_stack_[(1) - (1)].string_ptr));
		delete((yysemantic_stack_[(1) - (1)].string_ptr));
	}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 187 "grammar.yy"
    {(yyval.string_ptr) = new string(STRIPS);}
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 189 "grammar.yy"
    {(yyval.string_ptr) = new string(TYPING);}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 197 "grammar.yy"
    {
		(yyval.type_vec) = new vector<Type*>();
	}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 202 "grammar.yy"
    {
		if (!isRequirementDefined(TYPING)){
			error(yylloc, string("type definition not enabled (use :typing)"));			
			exit(1);
		}
		(yyval.type_vec) = new vector<Type*>();
		for (unsigned int i = 0; i < (yysemantic_stack_[(3) - (2)].typed_string_list_vec) -> size(); i++){
			TypedStringList* curTypedStringList = (*(yysemantic_stack_[(3) - (2)].typed_string_list_vec))[i];
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
					(yyval.type_vec) -> push_back(superType);
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
				(yyval.type_vec) -> push_back(type);
			}
		}
		delete((yysemantic_stack_[(3) - (2)].typed_string_list_vec));
	}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 248 "grammar.yy"
    {
		(yyval.constant_vec) = new vector<Constant*>();
	}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 253 "grammar.yy"
    {
		(yyval.constant_vec) = new vector<Constant*>();
		for (unsigned int i = 0; i < (yysemantic_stack_[(3) - (2)].typed_string_list_vec) -> size(); i++){
			TypedStringList* curTypedStringList = (*(yysemantic_stack_[(3) - (2)].typed_string_list_vec))[i];
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
				(yyval.constant_vec) -> push_back(constant);
			}
		}	
		delete ((yysemantic_stack_[(3) - (2)].typed_string_list_vec));
	}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 295 "grammar.yy"
    {
		(yyval.predicate_vec) = new vector<const Predicate*>();
	}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 300 "grammar.yy"
    {
		(yyval.predicate_vec) = (yysemantic_stack_[(3) - (2)].predicate_vec);
	}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 306 "grammar.yy"
    {
		(yyval.predicate_vec) = new vector<const Predicate*>();
		(yyval.predicate_vec) -> push_back((yysemantic_stack_[(1) - (1)].predicate_ptr));
	}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 311 "grammar.yy"
    {
		(yyval.predicate_vec) = (yysemantic_stack_[(2) - (1)].predicate_vec);
		(yysemantic_stack_[(2) - (1)].predicate_vec) -> push_back((yysemantic_stack_[(2) - (2)].predicate_ptr));
	}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 318 "grammar.yy"
    {
		// Check if the predicate is already defined
		Predicate* newPred = (Predicate*)(symtable.get(*(yysemantic_stack_[(4) - (2)].string_ptr),PREDICATE));
		if (newPred != NULL){// The new predicate has been already defined: error!
			error(yylloc, string("predicate \"") + *(yysemantic_stack_[(4) - (2)].string_ptr) + string("\" already defined"));
			exit(1);
		}
		// Build new predicate
		newPred = new Predicate(*(yysemantic_stack_[(4) - (2)].string_ptr),*(yysemantic_stack_[(4) - (3)].typed_list_var_vec));
		symtable.add(newPred, PREDICATE);
		(yyval.predicate_ptr) = newPred;
		delete((yysemantic_stack_[(4) - (2)].string_ptr));
		delete((yysemantic_stack_[(4) - (3)].typed_list_var_vec));
	}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 339 "grammar.yy"
    {
		(yyval.action_vec) = (yysemantic_stack_[(1) - (1)].action_vec);
	}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 345 "grammar.yy"
    {
		(yyval.action_vec) = new vector<const Action*>();
	}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 349 "grammar.yy"
    {
		(yyval.action_vec) = (yysemantic_stack_[(2) - (1)].action_vec);
		(yyval.action_vec) -> push_back((yysemantic_stack_[(2) - (2)].action_ptr));
	}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 357 "grammar.yy"
    {createActionContext(*(yysemantic_stack_[(3) - (3)].typed_list_var_vec));}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 357 "grammar.yy"
    {
		// Check duplicates in parameters
		Variable* duplicate = checkDuplicates(*(yysemantic_stack_[(7) - (3)].typed_list_var_vec));
		if (duplicate != NULL){
			// Duplicate varibale in action argument: error
			error(yylloc, string("parameter \"") + duplicate->getName() + string("\" in action \"") + *(yysemantic_stack_[(7) - (2)].string_ptr) + string("\" not unique"));
			exit(1);
		}
		
		(yyval.action_ptr) = new Action(*(yysemantic_stack_[(7) - (2)].string_ptr), *(yysemantic_stack_[(7) - (3)].typed_list_var_vec), (yysemantic_stack_[(7) - (5)].gd_ptr), (yysemantic_stack_[(7) - (6)].effect_ptr));
		delete((yysemantic_stack_[(7) - (2)].string_ptr));
		delete((yysemantic_stack_[(7) - (3)].typed_list_var_vec));
		
		context.clear();
	}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 375 "grammar.yy"
    {
		(yyval.typed_list_var_vec) = new vector<Variable*>();
	}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 379 "grammar.yy"
    {
		(yyval.typed_list_var_vec) = (yysemantic_stack_[(4) - (3)].typed_list_var_vec);
	}
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 385 "grammar.yy"
    {
		(yyval.gd_ptr) = NULL;
	}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 389 "grammar.yy"
    {
		(yyval.gd_ptr) = NULL;
	}
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 393 "grammar.yy"
    {
		(yyval.gd_ptr) = (yysemantic_stack_[(2) - (2)].gd_ptr);
	}
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 399 "grammar.yy"
    {
		(yyval.gd_ptr) = new GD((yysemantic_stack_[(1) - (1)].atomic_formula_term_ptr));
	}
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 403 "grammar.yy"
    {
		(yyval.gd_ptr) = new GD(*(yysemantic_stack_[(4) - (3)].gd_list_vec));	
		delete((yysemantic_stack_[(4) - (3)].gd_list_vec));
	}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 410 "grammar.yy"
    {
		(yyval.gd_list_vec) = new vector<GD*>();
	}
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 414 "grammar.yy"
    {
		(yyval.gd_list_vec) = (yysemantic_stack_[(2) - (1)].gd_list_vec);
		(yyval.gd_list_vec) -> push_back((yysemantic_stack_[(2) - (2)].gd_ptr));
	}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 422 "grammar.yy"
    {
		Predicate* predicate = (Predicate*)(symtable.get(*(yysemantic_stack_[(4) - (2)].string_ptr),PREDICATE));
		// Check if predicate is defined
		if (predicate == NULL){
			error(yylloc, string("predicate \"") + *(yysemantic_stack_[(4) - (2)].string_ptr) + string("\" not defined"));
			exit(1);
		}
		
		(yyval.atomic_formula_term_ptr) = new AtomicFormulaTerm(predicate,*(yysemantic_stack_[(4) - (3)].term_list_vec));
		
		// Check if term_list size matches predicate arity
		if (!(yyval.atomic_formula_term_ptr) -> isArityConsistent()){
			error(yylloc, string("number of terms does not match arity of predicate \"") + *(yysemantic_stack_[(4) - (2)].string_ptr) + "\"");
			exit(1);
		}
		
		// Check if term_list types match predicate arguments types
		Term* badTerm = (yyval.atomic_formula_term_ptr) -> isTypeConsistent();	
		if (badTerm != NULL){
			error(yylloc, string("term \"") + badTerm -> getName() + "\" does not match predicate \"" + *(yysemantic_stack_[(4) - (2)].string_ptr) + "\" argument type");
			exit(1);
		}
		delete((yysemantic_stack_[(4) - (2)].string_ptr));
		delete((yysemantic_stack_[(4) - (3)].term_list_vec));
				
	}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 452 "grammar.yy"
    {
		Predicate* predicate = (Predicate*)(symtable.get(*(yysemantic_stack_[(4) - (2)].string_ptr),PREDICATE));
		// Check if predicate is defined
		if (predicate == NULL){
			error(yylloc, string("predicate \"") + *(yysemantic_stack_[(4) - (2)].string_ptr) + string("\" not defined"));
			exit(1);
		}
		
		(yyval.atomic_formula_term_ptr) = new AtomicFormulaTerm(predicate,*(yysemantic_stack_[(4) - (3)].term_list_vec));
		
		// Check if term_list size matches predicate arity
		if (!(yyval.atomic_formula_term_ptr) -> isArityConsistent()){
			error(yylloc, string("number of terms does not match arity of predicate \"") + *(yysemantic_stack_[(4) - (2)].string_ptr) + "\"");
			exit(1);
		}
		
		// Check if term_list types match predicate arguments types
		Term* badTerm = (yyval.atomic_formula_term_ptr) -> isTypeConsistent();		
		if (badTerm != NULL){
			error(yylloc, string("term \"") + badTerm -> getName() + "\" does not match predicate \"" + *(yysemantic_stack_[(4) - (2)].string_ptr) + "\" argument type");
			exit(1);
		}
		delete((yysemantic_stack_[(4) - (2)].string_ptr));
		delete((yysemantic_stack_[(4) - (3)].term_list_vec));
	}
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 480 "grammar.yy"
    {
		(yyval.term_list_vec) = new vector<Term*>();
	}
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 484 "grammar.yy"
    {
		(yyval.term_list_vec) = (yysemantic_stack_[(2) - (1)].term_list_vec);
		(yyval.term_list_vec) -> push_back((yysemantic_stack_[(2) - (2)].constant_ptr));
	}
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 491 "grammar.yy"
    {
		Constant* constant = (Constant*)(symtable.get(*(yysemantic_stack_[(1) - (1)].string_ptr),CONSTANT));
		if (constant == NULL){// Undefined constant: error
			error(yylloc, string("constant \"") + *(yysemantic_stack_[(1) - (1)].string_ptr) + string("\" not defined"));
			exit(1);
		}
		delete ((yysemantic_stack_[(1) - (1)].string_ptr));
		(yyval.constant_ptr) = constant;
	}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 504 "grammar.yy"
    {
		(yyval.term_list_vec) = new vector<Term*>();
	}
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 508 "grammar.yy"
    {
		(yyval.term_list_vec) = (yysemantic_stack_[(2) - (1)].term_list_vec);
		(yyval.term_list_vec) -> push_back((yysemantic_stack_[(2) - (2)].term_ptr));
	}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 515 "grammar.yy"
    {
		(yyval.term_ptr) = (yysemantic_stack_[(1) - (1)].constant_ptr);
	}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 519 "grammar.yy"
    {
		Variable* variable = (Variable*)(context.get(*(yysemantic_stack_[(1) - (1)].string_ptr),VARIABLE));
		if (variable == NULL){// Undefined constant: error
			error(yylloc, string("variable \"") + *(yysemantic_stack_[(1) - (1)].string_ptr) + string("\" not defined"));
			exit(1);
		}
		(yyval.term_ptr) = variable;
		
	}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 533 "grammar.yy"
    {
		(yyval.effect_ptr) = NULL;
	}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 537 "grammar.yy"
    {
		(yyval.effect_ptr) = NULL;
	}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 541 "grammar.yy"
    {
		(yyval.effect_ptr) = new Effect(*(yysemantic_stack_[(5) - (4)].c_effect_list_vec));
		delete((yysemantic_stack_[(5) - (4)].c_effect_list_vec));
	}
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 546 "grammar.yy"
    {
		(yyval.effect_ptr) = new Effect((yysemantic_stack_[(2) - (2)].c_effect_ptr));
	}
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 552 "grammar.yy"
    {
		(yyval.c_effect_ptr) = new CEffect((yysemantic_stack_[(1) - (1)].p_effect_ptr));
	}
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 558 "grammar.yy"
    {
		(yyval.c_effect_list_vec) = new vector<CEffect*>();
	}
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 562 "grammar.yy"
    {
		(yyval.c_effect_list_vec) = (yysemantic_stack_[(2) - (1)].c_effect_list_vec);
		(yysemantic_stack_[(2) - (1)].c_effect_list_vec) -> push_back((yysemantic_stack_[(2) - (2)].c_effect_ptr));
	}
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 570 "grammar.yy"
    {
		(yyval.p_effect_ptr) = new PEffect((yysemantic_stack_[(1) - (1)].literal_ptr));
	}
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 576 "grammar.yy"
    {
		(yyval.literal_ptr) = new Literal((yysemantic_stack_[(4) - (3)].atomic_formula_term_ptr),true);
	}
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 580 "grammar.yy"
    {
		(yyval.literal_ptr) = new Literal((yysemantic_stack_[(1) - (1)].atomic_formula_term_ptr),false);
	}
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 586 "grammar.yy"
    {
		(yyval.literal_ptr) = new Literal((yysemantic_stack_[(4) - (3)].atomic_formula_term_ptr),true);
	}
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 590 "grammar.yy"
    {
		(yyval.literal_ptr) = new Literal((yysemantic_stack_[(1) - (1)].atomic_formula_term_ptr),false);
	}
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 602 "grammar.yy"
    {
		(yyval.typed_string_list_vec) = new vector<TypedStringList*>();
	}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 606 "grammar.yy"
    {
		(yyval.typed_string_list_vec) = (yysemantic_stack_[(4) - (1)].typed_string_list_vec);
		(yyval.typed_string_list_vec) -> push_back(new TypedStringList(*(yysemantic_stack_[(4) - (2)].string_vec), (yysemantic_stack_[(4) - (4)].string_ptr)));
		delete((yysemantic_stack_[(4) - (2)].string_vec));
	}
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 612 "grammar.yy"
    {
		(yyval.typed_string_list_vec) = (yysemantic_stack_[(2) - (1)].typed_string_list_vec);
		(yyval.typed_string_list_vec) -> push_back(new TypedStringList(*(yysemantic_stack_[(2) - (2)].string_vec)));
		delete((yysemantic_stack_[(2) - (2)].string_vec));		
	}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 620 "grammar.yy"
    {
		(yyval.string_vec) = new vector<string>();
		(yyval.string_vec) -> push_back(*(yysemantic_stack_[(1) - (1)].string_ptr));
	}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 625 "grammar.yy"
    {
		(yysemantic_stack_[(2) - (1)].string_vec) -> push_back(*(yysemantic_stack_[(2) - (2)].string_ptr));
		(yyval.string_vec) = (yysemantic_stack_[(2) - (1)].string_vec);
	}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 635 "grammar.yy"
    {
		(yyval.typed_list_var_vec) = new vector<Variable*>();		
	}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 639 "grammar.yy"
    {
		Type* type = (Type*)(symtable.get(*(yysemantic_stack_[(4) - (4)].string_ptr),TYPE));
		if (type == NULL){// Undeclared type: error!
			error(yylloc, string("type \"") + *(yysemantic_stack_[(4) - (4)].string_ptr) + string("\" not defined"));
			exit(1);
		}		
		(yyval.typed_list_var_vec) = (yysemantic_stack_[(4) - (1)].typed_list_var_vec);
		for (unsigned int i = 0; i < (yysemantic_stack_[(4) - (2)].string_vec) -> size(); i++){
			(yyval.typed_list_var_vec) -> push_back(new Variable((*(yysemantic_stack_[(4) - (2)].string_vec))[i], type));
		}
		delete((yysemantic_stack_[(4) - (2)].string_vec));
		delete((yysemantic_stack_[(4) - (4)].string_ptr));		
	}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 653 "grammar.yy"
    {
		(yyval.typed_list_var_vec) = (yysemantic_stack_[(2) - (1)].typed_list_var_vec);
		for (unsigned int i = 0; i < (yysemantic_stack_[(2) - (2)].string_vec) -> size(); i++){
			(yyval.typed_list_var_vec) -> push_back(new Variable((*(yysemantic_stack_[(2) - (2)].string_vec))[i], BASE_TYPE));
		}
		delete((yysemantic_stack_[(2) - (2)].string_vec));
	}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 663 "grammar.yy"
    {
		(yyval.string_vec) = new vector<string>();
		(yyval.string_vec) -> push_back(*(yysemantic_stack_[(1) - (1)].string_ptr));
	}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 668 "grammar.yy"
    {
		(yysemantic_stack_[(2) - (1)].string_vec) -> push_back(*(yysemantic_stack_[(2) - (2)].string_ptr));
		(yyval.string_vec) = (yysemantic_stack_[(2) - (1)].string_vec);
	}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 678 "grammar.yy"
    {
		// Check if the domain is defined
		Domain* domain = (Domain*)(symtable.get(*(yysemantic_stack_[(17) - (9)].string_ptr),DOMAIN));
		if (domain == NULL){
			// Error: problem not defined on current domain
			error(yylloc, string("planning program \"") + *(yysemantic_stack_[(17) - (5)].string_ptr) + "\" defined on domain \""+ *(yysemantic_stack_[(17) - (9)].string_ptr) + "\", which is undefined");
			exit(1);
		}
		
		(yyval.problem_ptr) = new Problem(*(yysemantic_stack_[(17) - (5)].string_ptr), domain, *requirements, *(yysemantic_stack_[(17) - (11)].constant_vec), *(yysemantic_stack_[(17) - (12)].init_elem_list_vec), (yysemantic_stack_[(17) - (15)].ltl_spec_ptr));
		// FP: check all delete below
		delete((yysemantic_stack_[(17) - (5)].string_ptr));
		delete((yysemantic_stack_[(17) - (11)].constant_vec));
		delete((yysemantic_stack_[(17) - (12)].init_elem_list_vec));
	}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 700 "grammar.yy"
    {
		(yyval.ltl_spec_ptr) = new LTLNode();
		(yyval.ltl_spec_ptr) -> op = NN;
		(yyval.ltl_spec_ptr) -> atom = (yysemantic_stack_[(1) - (1)].atomic_formula_term_ptr);
	}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 707 "grammar.yy"
    {
			(yyval.ltl_spec_ptr) = new LTLNode();
			(yyval.ltl_spec_ptr) -> op = NOT;
			(yyval.ltl_spec_ptr) -> left = (yysemantic_stack_[(2) - (2)].ltl_spec_ptr);		
	}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 714 "grammar.yy"
    {	
		(yyval.ltl_spec_ptr) = new LTLNode();
		(yyval.ltl_spec_ptr) -> op = NEXT;
		(yyval.ltl_spec_ptr) -> left = (yysemantic_stack_[(2) - (2)].ltl_spec_ptr);
	}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 721 "grammar.yy"
    {
		(yyval.ltl_spec_ptr) = (yysemantic_stack_[(3) - (2)].ltl_spec_ptr);
	}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 726 "grammar.yy"
    {	
		(yyval.ltl_spec_ptr) = new LTLNode();
		(yyval.ltl_spec_ptr) -> op = ALW;
		(yyval.ltl_spec_ptr) -> left = (yysemantic_stack_[(2) - (2)].ltl_spec_ptr);
	}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 733 "grammar.yy"
    {	
		(yyval.ltl_spec_ptr) = new LTLNode();
		(yyval.ltl_spec_ptr) -> op = EVT;
		(yyval.ltl_spec_ptr) -> left = (yysemantic_stack_[(2) - (2)].ltl_spec_ptr);
	}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 740 "grammar.yy"
    {
		(yyval.ltl_spec_ptr) = new LTLNode();
		(yyval.ltl_spec_ptr) -> op = AND;
		(yyval.ltl_spec_ptr) -> left = (yysemantic_stack_[(3) - (1)].ltl_spec_ptr);
		(yyval.ltl_spec_ptr) -> right = (yysemantic_stack_[(3) - (3)].ltl_spec_ptr);
	}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 748 "grammar.yy"
    {
		(yyval.ltl_spec_ptr) = new LTLNode();
		(yyval.ltl_spec_ptr) -> op = OR;
		(yyval.ltl_spec_ptr) -> left = (yysemantic_stack_[(3) - (1)].ltl_spec_ptr);
		(yyval.ltl_spec_ptr) -> right = (yysemantic_stack_[(3) - (3)].ltl_spec_ptr);
	}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 756 "grammar.yy"
    {
		(yyval.ltl_spec_ptr) = new LTLNode();
		(yyval.ltl_spec_ptr) -> op = IMPL;
		(yyval.ltl_spec_ptr) -> left = (yysemantic_stack_[(3) - (1)].ltl_spec_ptr);
		(yyval.ltl_spec_ptr) -> right = (yysemantic_stack_[(3) - (3)].ltl_spec_ptr);		
	}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 764 "grammar.yy"
    {
		(yyval.ltl_spec_ptr) = new LTLNode();
		(yyval.ltl_spec_ptr) -> op = IFF;
		(yyval.ltl_spec_ptr) -> left = (yysemantic_stack_[(3) - (1)].ltl_spec_ptr);
		(yyval.ltl_spec_ptr) -> right = (yysemantic_stack_[(3) - (3)].ltl_spec_ptr);		
	}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 772 "grammar.yy"
    {
		(yyval.ltl_spec_ptr) = new LTLNode();
		(yyval.ltl_spec_ptr) -> op = UNTIL;
		(yyval.ltl_spec_ptr) -> left = (yysemantic_stack_[(3) - (1)].ltl_spec_ptr);
		(yyval.ltl_spec_ptr) -> right = (yysemantic_stack_[(3) - (3)].ltl_spec_ptr);		
	}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 780 "grammar.yy"
    {
		(yyval.ltl_spec_ptr) = new LTLNode();
		(yyval.ltl_spec_ptr) -> op = RELEASE;
		(yyval.ltl_spec_ptr) -> left = (yysemantic_stack_[(3) - (1)].ltl_spec_ptr);
		(yyval.ltl_spec_ptr) -> right = (yysemantic_stack_[(3) - (3)].ltl_spec_ptr);	
	}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 794 "grammar.yy"
    {
		(yyval.constant_vec) = new vector<Constant*>();
	}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 799 "grammar.yy"
    {
		(yyval.constant_vec) = new vector<Constant*>();
		for (unsigned int i = 0; i < (yysemantic_stack_[(3) - (2)].typed_string_list_vec) -> size(); i++){
			TypedStringList* curTypedStringList = (*(yysemantic_stack_[(3) - (2)].typed_string_list_vec))[i];
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
				(yyval.constant_vec) -> push_back(constant);
			}
		}	
		delete ((yysemantic_stack_[(3) - (2)].typed_string_list_vec));
	}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 841 "grammar.yy"
    {
		(yyval.init_elem_list_vec) = (yysemantic_stack_[(4) - (3)].init_elem_list_vec);
	}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 847 "grammar.yy"
    {
		(yyval.init_elem_list_vec) = new vector<InitElement*>();
	}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 851 "grammar.yy"
    {
		(yyval.init_elem_list_vec) = (yysemantic_stack_[(2) - (1)].init_elem_list_vec);
		(yyval.init_elem_list_vec) -> push_back(new InitElement((yysemantic_stack_[(2) - (2)].literal_ptr)));
	}
    break;



/* Line 678 of lalr1.cc  */
#line 1442 "grammar.tab.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Pddl30Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Pddl30Parser::yypact_ninf_ = -111;
  const signed char
  Pddl30Parser::yypact_[] =
  {
       -31,     7,    17,    -2,     6,  -111,    53,  -111,    60,    27,
      40,    56,    41,    65,    80,    48,    28,  -111,    59,  -111,
    -111,    -6,  -111,   100,   105,  -111,  -111,  -111,   101,    76,
     -18,  -111,   102,    74,  -111,  -111,   -22,    29,    77,  -111,
      96,  -111,    81,  -111,    82,    15,  -111,    79,   108,  -111,
      83,  -111,  -111,  -111,  -111,  -111,    85,  -111,    37,   103,
      86,    57,   111,  -111,  -111,   106,  -111,  -111,    52,    87,
    -111,    64,    61,  -111,    92,  -111,   115,    -5,  -111,  -111,
    -111,    61,    61,    61,    61,   -15,  -111,    38,  -111,    62,
      91,   116,    93,  -111,    19,    19,    19,    19,    50,    61,
      61,    61,    61,    61,    61,    94,  -111,   -10,  -111,  -111,
      97,    95,   104,    98,    55,  -111,    19,    19,    19,    19,
      19,    19,  -111,  -111,  -111,  -111,   -13,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,    66,    10,  -111,   107,
    -111,   -11,  -111,  -111,  -111,  -111,  -111,  -111,    68,   109,
      99,    -4,  -111,  -111,  -111
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Pddl30Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     3,     0,     9,
      10,     0,     8,    11,     0,     6,     7,    55,    13,     0,
       0,    55,    15,     0,    58,    12,    57,     0,     0,    21,
      78,    59,     0,    14,     0,     0,    17,     0,    20,    55,
       0,    56,    60,    16,    18,     4,     0,    22,     0,     0,
       0,     0,    25,    79,    81,     0,    63,    19,    62,     0,
      23,     0,     0,    64,     0,    60,    27,     0,    80,    54,
      82,     0,     0,     0,     0,     0,    66,     0,    61,     0,
       0,    43,     0,    36,    70,    71,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    29,    30,
       0,     0,     0,     0,     0,    69,    75,    72,    73,    74,
      76,    77,    65,    32,    39,    28,     0,    52,    46,    47,
      50,    24,    53,    38,    35,    37,     0,     0,    48,     0,
      44,     0,    31,    33,    42,    34,    41,    40,     0,     0,
       0,     0,    45,    49,    51
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Pddl30Parser::yypgoto_[] =
  {
      -111,  -111,  -111,  -111,  -111,  -111,   112,  -111,  -111,  -111,
    -111,   110,  -111,  -111,  -111,  -111,  -111,  -111,     1,  -111,
    -110,   -64,  -111,     4,  -111,  -111,  -111,    -1,  -111,  -111,
    -111,  -111,   -16,  -111,    67,  -111,  -111,   -42,  -111,  -111,
    -111
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Pddl30Parser::yydefgoto_[] =
  {
        -1,     2,     3,    23,    17,    21,    22,    28,    32,    39,
      45,    46,    47,    48,    57,    76,    70,    91,   108,   136,
     109,    86,   114,   135,   137,   147,   111,   128,   148,   129,
     130,    80,    30,    36,    61,    68,     7,    87,    50,    60,
      71
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Pddl30Parser::yytable_ninf_ = -1;
  const unsigned char
  Pddl30Parser::yytable_[] =
  {
       127,    19,    20,   138,   139,   123,   123,    79,     1,    81,
       4,    82,    92,   139,    41,    37,    83,     5,    34,    42,
      84,    93,    35,   124,    85,   124,   124,   140,   113,   150,
     125,    93,   124,    58,    25,    19,    20,     6,   127,    94,
      95,    96,    97,    98,    99,     8,   133,   144,   100,   101,
     145,   102,   103,   104,    44,    53,     9,   116,   117,   118,
     119,   120,   121,    99,    10,    34,    11,   100,   101,    43,
     102,   103,   104,    34,    13,    99,    12,    63,   105,   100,
     101,    14,   102,   103,   104,    81,    16,    82,    18,    73,
     115,   133,    83,    74,    66,   134,    84,    67,    24,    66,
      85,    15,   106,    77,    78,   141,   142,   151,   152,    27,
      29,    31,    33,    38,    40,    49,    44,    51,    52,    55,
      56,    62,    59,    64,    69,    65,    75,    72,    88,    90,
     107,   110,   112,    26,   122,   131,   126,   143,   132,   154,
      93,   146,    89,     0,     0,   124,   149,   153,     0,     0,
       0,     0,     0,     0,     0,    54
  };

  /* YYCHECK.  */
  const short int
  Pddl30Parser::yycheck_[] =
  {
       110,     7,     8,    16,    17,    16,    16,    71,    39,    24,
       3,    26,    17,    17,    36,    31,    31,     0,    36,    41,
      35,    36,    40,    36,    39,    36,    36,    40,    92,   139,
      40,    36,    36,    49,    40,     7,     8,    39,   148,    81,
      82,    83,    84,    85,    25,    39,    36,    37,    29,    30,
      40,    32,    33,    34,    39,    40,     3,    99,   100,   101,
     102,   103,   104,    25,     4,    36,    39,    29,    30,    40,
      32,    33,    34,    36,    18,    25,    36,    40,    40,    29,
      30,    40,    32,    33,    34,    24,     6,    26,    40,    37,
      40,    36,    31,    41,    37,    40,    35,    40,    39,    37,
      39,    36,    40,    39,    40,    39,    40,    39,    40,     9,
       5,    10,    36,    11,    40,    19,    39,    36,    36,    40,
      12,    36,    39,    20,    13,    39,    39,    21,    36,    14,
      39,    15,    39,    21,    40,    40,    39,   136,    40,    40,
      36,   137,    75,    -1,    -1,    36,    39,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Pddl30Parser::yystos_[] =
  {
         0,    39,    43,    44,     3,     0,    39,    78,    39,     3,
       4,    39,    36,    18,    40,    36,     6,    46,    40,     7,
       8,    47,    48,    45,    39,    40,    48,     9,    49,     5,
      74,    10,    50,    36,    36,    40,    75,    74,    11,    51,
      40,    36,    41,    40,    39,    52,    53,    54,    55,    19,
      80,    36,    36,    40,    53,    40,    12,    56,    74,    39,
      81,    76,    36,    40,    20,    39,    37,    40,    77,    13,
      58,    82,    21,    37,    41,    39,    57,    39,    40,    63,
      73,    24,    26,    31,    35,    39,    63,    79,    36,    76,
      14,    59,    17,    36,    79,    79,    79,    79,    79,    25,
      29,    30,    32,    33,    34,    40,    40,    39,    60,    62,
      15,    68,    39,    63,    64,    40,    79,    79,    79,    79,
      79,    79,    40,    16,    36,    40,    39,    62,    69,    71,
      72,    40,    40,    36,    40,    65,    61,    66,    16,    17,
      40,    39,    40,    60,    37,    40,    65,    67,    70,    39,
      62,    39,    40,    69,    40
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Pddl30Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    40,
      41,    45
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Pddl30Parser::yyr1_[] =
  {
         0,    42,    43,    45,    44,    46,    46,    47,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      54,    55,    55,    57,    56,    58,    58,    59,    59,    59,
      60,    60,    61,    61,    62,    63,    64,    64,    65,    66,
      66,    67,    67,    68,    68,    68,    68,    69,    70,    70,
      71,    72,    72,    73,    73,    74,    74,    74,    75,    75,
      76,    76,    76,    77,    77,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      81,    82,    82
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Pddl30Parser::yyr2_[] =
  {
         0,     2,     2,     0,    13,     0,     3,     2,     1,     1,
       1,     0,     3,     0,     3,     0,     3,     1,     2,     4,
       1,     0,     2,     0,     7,     0,     4,     0,     3,     2,
       1,     4,     0,     2,     4,     4,     0,     2,     1,     0,
       2,     1,     1,     0,     3,     5,     2,     1,     0,     2,
       1,     4,     1,     4,     1,     0,     4,     2,     1,     2,
       0,     4,     2,     1,     2,    17,     1,     2,     2,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     0,     3,
       4,     0,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Pddl30Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "DEFINE", "DOMAIN",
  "COL_DOMAIN", "REQUIREMENTS", "TK_STRIPS", "TK_TYPING", "TYPES",
  "CONSTANTS", "PREDICATES", "ACTION", "PARAMETERS", "PRECONDITION",
  "EFFECT", "AND", "NOT", "PROBLEM", "OBJECTS", "INIT", "GOAL", "INITNODE",
  "TRANSITIONS", "TK_ALW", "TK_IFF", "TK_EVT", "TK_HYPHEN", "TK_EQ",
  "TK_LTL_AND", "TK_LTL_OR", "TK_EXCL", "TK_IMPL", "TK_UNTIL",
  "TK_RELEASE", "TK_NEXT", "NAME", "VARIABLE", "ERROR", "'('", "')'",
  "'-'", "$accept", "specification", "domain", "$@1", "require_def",
  "require_list", "require_key", "types_def", "constants_def",
  "predicates_def", "predicate_list", "single_predicate_def",
  "actions_def", "actions_def_list", "single_action_def", "$@2",
  "parameters", "precondition", "gd", "gd_list", "atomic_formula_term",
  "atomic_formula_name", "const_list", "constant_ref", "term_list", "term",
  "effect", "c_effect", "c_effect_list", "p_effect", "literal_term",
  "literal_name", "typed_list_name", "untyped_list_name",
  "typed_list_variable", "untyped_list_variable", "problem", "ltl_spec",
  "object_decl", "init", "init_elem_list", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Pddl30Parser::rhs_number_type
  Pddl30Parser::yyrhs_[] =
  {
        43,     0,    -1,    44,    78,    -1,    -1,    39,     3,    39,
       4,    36,    40,    46,    45,    49,    50,    51,    54,    40,
      -1,    -1,     6,    47,    40,    -1,    47,    48,    -1,    48,
      -1,     7,    -1,     8,    -1,    -1,     9,    74,    40,    -1,
      -1,    10,    74,    40,    -1,    -1,    11,    52,    40,    -1,
      53,    -1,    52,    53,    -1,    39,    36,    76,    40,    -1,
      55,    -1,    -1,    55,    56,    -1,    -1,    12,    36,    58,
      57,    59,    68,    40,    -1,    -1,    13,    39,    76,    40,
      -1,    -1,    14,    39,    40,    -1,    14,    60,    -1,    62,
      -1,    39,    16,    61,    40,    -1,    -1,    61,    60,    -1,
      39,    36,    66,    40,    -1,    39,    36,    64,    40,    -1,
      -1,    64,    65,    -1,    36,    -1,    -1,    66,    67,    -1,
      65,    -1,    37,    -1,    -1,    15,    39,    40,    -1,    15,
      39,    16,    70,    40,    -1,    15,    69,    -1,    71,    -1,
      -1,    70,    69,    -1,    72,    -1,    39,    17,    62,    40,
      -1,    62,    -1,    39,    17,    63,    40,    -1,    63,    -1,
      -1,    74,    75,    41,    36,    -1,    74,    75,    -1,    36,
      -1,    75,    36,    -1,    -1,    76,    77,    41,    36,    -1,
      76,    77,    -1,    37,    -1,    77,    37,    -1,    39,     3,
      39,    18,    36,    40,    39,     5,    36,    40,    80,    81,
      39,    21,    79,    40,    40,    -1,    63,    -1,    31,    79,
      -1,    35,    79,    -1,    39,    79,    40,    -1,    24,    79,
      -1,    26,    79,    -1,    79,    29,    79,    -1,    79,    30,
      79,    -1,    79,    32,    79,    -1,    79,    25,    79,    -1,
      79,    33,    79,    -1,    79,    34,    79,    -1,    -1,    19,
      74,    40,    -1,    39,    20,    82,    40,    -1,    -1,    82,
      73,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Pddl30Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     7,    21,    22,    26,    29,    31,
      33,    35,    36,    40,    41,    45,    46,    50,    52,    55,
      60,    62,    63,    66,    67,    75,    76,    81,    82,    86,
      89,    91,    96,    97,   100,   105,   110,   111,   114,   116,
     117,   120,   122,   124,   125,   129,   135,   138,   140,   141,
     144,   146,   151,   153,   158,   160,   161,   166,   169,   171,
     174,   175,   180,   183,   185,   188,   206,   208,   211,   214,
     218,   221,   224,   228,   232,   236,   240,   244,   248,   249,
     253,   258,   259
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Pddl30Parser::yyrline_[] =
  {
         0,   138,   138,   145,   145,   162,   168,   174,   180,   187,
     189,   197,   202,   248,   253,   295,   300,   306,   311,   318,
     339,   345,   349,   357,   357,   375,   379,   385,   389,   393,
     399,   403,   410,   414,   422,   452,   480,   484,   491,   504,
     508,   515,   519,   533,   537,   541,   546,   552,   558,   562,
     570,   576,   580,   586,   590,   602,   606,   612,   620,   625,
     635,   639,   653,   663,   668,   678,   699,   706,   713,   720,
     725,   732,   739,   747,   755,   763,   771,   779,   794,   799,
     841,   847,   851
  };

  // Print the state stack on the debug stream.
  void
  Pddl30Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Pddl30Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Pddl30Parser::token_number_type
  Pddl30Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,     2,    41,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Pddl30Parser::yyeof_ = 0;
  const int Pddl30Parser::yylast_ = 155;
  const int Pddl30Parser::yynnts_ = 41;
  const int Pddl30Parser::yyempty_ = -2;
  const int Pddl30Parser::yyfinal_ = 5;
  const int Pddl30Parser::yyterror_ = 1;
  const int Pddl30Parser::yyerrcode_ = 256;
  const int Pddl30Parser::yyntokens_ = 42;

  const unsigned int Pddl30Parser::yyuser_token_number_max_ = 293;
  const Pddl30Parser::token_number_type Pddl30Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yy

/* Line 1054 of lalr1.cc  */
#line 2013 "grammar.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 867 "grammar.yy"



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


