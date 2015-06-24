
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
#line 28 "grammar.yy"

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
  Pddl30Parser::Pddl30Parser (Domain& domain_yyarg, PlanningProgram& planning_program_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      domain (domain_yyarg),
      planning_program (planning_program_yyarg)
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
#line 145 "grammar.yy"
    {
		domain = *(yysemantic_stack_[(2) - (1)].domain_ptr);
		planning_program = *(yysemantic_stack_[(2) - (2)].planning_program_ptr);
	}
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 152 "grammar.yy"
    {requirements = (yysemantic_stack_[(7) - (7)].string_vec);}
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 152 "grammar.yy"
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
#line 169 "grammar.yy"
    {
		(yyval.string_vec) = new vector<string>();
		(yyval.string_vec) -> push_back(STRIPS);
	}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 175 "grammar.yy"
    {
		(yyval.string_vec) = (yysemantic_stack_[(3) - (2)].string_vec);
	}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 181 "grammar.yy"
    {
		(yyval.string_vec) = (yysemantic_stack_[(2) - (1)].string_vec);
		(yyval.string_vec) -> push_back(*(yysemantic_stack_[(2) - (2)].string_ptr));
		delete((yysemantic_stack_[(2) - (2)].string_ptr));
	}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 187 "grammar.yy"
    {
		(yyval.string_vec) = new vector<string>();
		(yyval.string_vec) -> push_back(*(yysemantic_stack_[(1) - (1)].string_ptr));
		delete((yysemantic_stack_[(1) - (1)].string_ptr));
	}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 194 "grammar.yy"
    {(yyval.string_ptr) = new string(STRIPS);}
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 196 "grammar.yy"
    {(yyval.string_ptr) = new string(TYPING);}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 204 "grammar.yy"
    {
		(yyval.type_vec) = new vector<Type*>();
	}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 209 "grammar.yy"
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
#line 255 "grammar.yy"
    {
		(yyval.constant_vec) = new vector<Constant*>();
	}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 260 "grammar.yy"
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
#line 302 "grammar.yy"
    {
		(yyval.predicate_vec) = new vector<const Predicate*>();
	}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 307 "grammar.yy"
    {
		(yyval.predicate_vec) = (yysemantic_stack_[(3) - (2)].predicate_vec);
	}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 313 "grammar.yy"
    {
		(yyval.predicate_vec) = new vector<const Predicate*>();
		(yyval.predicate_vec) -> push_back((yysemantic_stack_[(1) - (1)].predicate_ptr));
	}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 318 "grammar.yy"
    {
		(yyval.predicate_vec) = (yysemantic_stack_[(2) - (1)].predicate_vec);
		(yysemantic_stack_[(2) - (1)].predicate_vec) -> push_back((yysemantic_stack_[(2) - (2)].predicate_ptr));
	}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 325 "grammar.yy"
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
#line 346 "grammar.yy"
    {
		(yyval.action_vec) = (yysemantic_stack_[(1) - (1)].action_vec);
	}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 352 "grammar.yy"
    {
		(yyval.action_vec) = new vector<const Action*>();
	}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 356 "grammar.yy"
    {
		(yyval.action_vec) = (yysemantic_stack_[(2) - (1)].action_vec);
		(yyval.action_vec) -> push_back((yysemantic_stack_[(2) - (2)].action_ptr));
	}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 364 "grammar.yy"
    {createActionContext(*(yysemantic_stack_[(3) - (3)].typed_list_var_vec));}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 364 "grammar.yy"
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
#line 382 "grammar.yy"
    {
		(yyval.typed_list_var_vec) = new vector<Variable*>();
	}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 386 "grammar.yy"
    {
		(yyval.typed_list_var_vec) = (yysemantic_stack_[(4) - (3)].typed_list_var_vec);
	}
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 392 "grammar.yy"
    {
		(yyval.gd_ptr) = NULL;
	}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 396 "grammar.yy"
    {
		(yyval.gd_ptr) = NULL;
	}
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 400 "grammar.yy"
    {
		(yyval.gd_ptr) = (yysemantic_stack_[(2) - (2)].gd_ptr);
	}
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 406 "grammar.yy"
    {
		(yyval.gd_ptr) = new GD(new Literal((yysemantic_stack_[(1) - (1)].atomic_formula_term_ptr)));
	}
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 410 "grammar.yy"
    {
        (yyval.gd_ptr) = new GD(new Literal((yysemantic_stack_[(4) - (3)].atomic_formula_term_ptr),true));
    }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 414 "grammar.yy"
    {
		(yyval.gd_ptr) = new GD(*(yysemantic_stack_[(4) - (3)].gd_list_vec));
		delete((yysemantic_stack_[(4) - (3)].gd_list_vec));
	}
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 421 "grammar.yy"
    {
		(yyval.gd_list_vec) = new vector<GD*>();
	}
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 425 "grammar.yy"
    {
		(yyval.gd_list_vec) = (yysemantic_stack_[(2) - (1)].gd_list_vec);
		(yyval.gd_list_vec) -> push_back((yysemantic_stack_[(2) - (2)].gd_ptr));
	}
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 433 "grammar.yy"
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
#line 463 "grammar.yy"
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

  case 37:

/* Line 678 of lalr1.cc  */
#line 491 "grammar.yy"
    {
		(yyval.term_list_vec) = new vector<Term*>();
	}
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 495 "grammar.yy"
    {
		(yyval.term_list_vec) = (yysemantic_stack_[(2) - (1)].term_list_vec);
		(yyval.term_list_vec) -> push_back((yysemantic_stack_[(2) - (2)].constant_ptr));
	}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 502 "grammar.yy"
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

  case 40:

/* Line 678 of lalr1.cc  */
#line 515 "grammar.yy"
    {
		(yyval.term_list_vec) = new vector<Term*>();
	}
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 519 "grammar.yy"
    {
		(yyval.term_list_vec) = (yysemantic_stack_[(2) - (1)].term_list_vec);
		(yyval.term_list_vec) -> push_back((yysemantic_stack_[(2) - (2)].term_ptr));
	}
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 526 "grammar.yy"
    {
		(yyval.term_ptr) = (yysemantic_stack_[(1) - (1)].constant_ptr);
	}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 530 "grammar.yy"
    {
		Variable* variable = (Variable*)(context.get(*(yysemantic_stack_[(1) - (1)].string_ptr),VARIABLE));
		if (variable == NULL){// Undefined constant: error
			error(yylloc, string("variable \"") + *(yysemantic_stack_[(1) - (1)].string_ptr) + string("\" not defined"));
			exit(1);
		}
		(yyval.term_ptr) = variable;
		
	}
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 544 "grammar.yy"
    {
		(yyval.effect_ptr) = NULL;
	}
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 548 "grammar.yy"
    {
		(yyval.effect_ptr) = NULL;
	}
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 552 "grammar.yy"
    {
		(yyval.effect_ptr) = new Effect(*(yysemantic_stack_[(5) - (4)].c_effect_list_vec));
		delete((yysemantic_stack_[(5) - (4)].c_effect_list_vec));
	}
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 557 "grammar.yy"
    {
		(yyval.effect_ptr) = new Effect((yysemantic_stack_[(2) - (2)].c_effect_ptr));
	}
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 563 "grammar.yy"
    {
		(yyval.c_effect_ptr) = new CEffect((yysemantic_stack_[(1) - (1)].p_effect_ptr));
	}
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 569 "grammar.yy"
    {
		(yyval.c_effect_list_vec) = new vector<CEffect*>();
	}
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 573 "grammar.yy"
    {
		(yyval.c_effect_list_vec) = (yysemantic_stack_[(2) - (1)].c_effect_list_vec);
		(yysemantic_stack_[(2) - (1)].c_effect_list_vec) -> push_back((yysemantic_stack_[(2) - (2)].c_effect_ptr));
	}
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 581 "grammar.yy"
    {
		(yyval.p_effect_ptr) = new PEffect((yysemantic_stack_[(1) - (1)].literal_ptr));
	}
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 587 "grammar.yy"
    {
		(yyval.literal_ptr) = new Literal((yysemantic_stack_[(4) - (3)].atomic_formula_term_ptr),true);
	}
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 591 "grammar.yy"
    {
		(yyval.literal_ptr) = new Literal((yysemantic_stack_[(1) - (1)].atomic_formula_term_ptr),false);
	}
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 597 "grammar.yy"
    {
		(yyval.literal_ptr) = new Literal((yysemantic_stack_[(4) - (3)].atomic_formula_term_ptr),true);
	}
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 601 "grammar.yy"
    {
		(yyval.literal_ptr) = new Literal((yysemantic_stack_[(1) - (1)].atomic_formula_term_ptr),false);
	}
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 613 "grammar.yy"
    {
		(yyval.typed_string_list_vec) = new vector<TypedStringList*>();
	}
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 617 "grammar.yy"
    {
		(yyval.typed_string_list_vec) = (yysemantic_stack_[(4) - (1)].typed_string_list_vec);
		(yyval.typed_string_list_vec) -> push_back(new TypedStringList(*(yysemantic_stack_[(4) - (2)].string_vec), (yysemantic_stack_[(4) - (4)].string_ptr)));
		delete((yysemantic_stack_[(4) - (2)].string_vec));
	}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 623 "grammar.yy"
    {
		(yyval.typed_string_list_vec) = (yysemantic_stack_[(2) - (1)].typed_string_list_vec);
		(yyval.typed_string_list_vec) -> push_back(new TypedStringList(*(yysemantic_stack_[(2) - (2)].string_vec)));
		delete((yysemantic_stack_[(2) - (2)].string_vec));		
	}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 631 "grammar.yy"
    {
		(yyval.string_vec) = new vector<string>();
		(yyval.string_vec) -> push_back(*(yysemantic_stack_[(1) - (1)].string_ptr));
	}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 636 "grammar.yy"
    {
		(yysemantic_stack_[(2) - (1)].string_vec) -> push_back(*(yysemantic_stack_[(2) - (2)].string_ptr));
		(yyval.string_vec) = (yysemantic_stack_[(2) - (1)].string_vec);
	}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 646 "grammar.yy"
    {
		(yyval.typed_list_var_vec) = new vector<Variable*>();		
	}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 650 "grammar.yy"
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

  case 63:

/* Line 678 of lalr1.cc  */
#line 664 "grammar.yy"
    {
		(yyval.typed_list_var_vec) = (yysemantic_stack_[(2) - (1)].typed_list_var_vec);
		for (unsigned int i = 0; i < (yysemantic_stack_[(2) - (2)].string_vec) -> size(); i++){
			(yyval.typed_list_var_vec) -> push_back(new Variable((*(yysemantic_stack_[(2) - (2)].string_vec))[i], BASE_TYPE));
		}
		delete((yysemantic_stack_[(2) - (2)].string_vec));
	}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 674 "grammar.yy"
    {
		(yyval.string_vec) = new vector<string>();
		(yyval.string_vec) -> push_back(*(yysemantic_stack_[(1) - (1)].string_ptr));
	}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 679 "grammar.yy"
    {
		(yysemantic_stack_[(2) - (1)].string_vec) -> push_back(*(yysemantic_stack_[(2) - (2)].string_ptr));
		(yyval.string_vec) = (yysemantic_stack_[(2) - (1)].string_vec);
	}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 689 "grammar.yy"
    {
		// Check if the domain is defined
		Domain* domain = (Domain*)(symtable.get(*(yysemantic_stack_[(21) - (9)].string_ptr),DOMAIN));
		if (domain == NULL){
			// Error: problem not defined on current domain
			error(yylloc, string("planning program \"") + *(yysemantic_stack_[(21) - (5)].string_ptr) + "\" defined on domain \""+ *(yysemantic_stack_[(21) - (9)].string_ptr) + "\", which is undefined");
			exit(1);
		}
		(yyval.planning_program_ptr) = new PlanningProgram(*(yysemantic_stack_[(21) - (5)].string_ptr), domain, *(yysemantic_stack_[(21) - (11)].constant_vec), *(yysemantic_stack_[(21) - (12)].init_elem_list_vec), (yysemantic_stack_[(21) - (15)].node_ptr), *(yysemantic_stack_[(21) - (19)].transition_list_vec));
		delete((yysemantic_stack_[(21) - (5)].string_ptr));
		delete((yysemantic_stack_[(21) - (9)].string_ptr));
		delete((yysemantic_stack_[(21) - (11)].constant_vec));
		delete((yysemantic_stack_[(21) - (12)].init_elem_list_vec));
		delete((yysemantic_stack_[(21) - (19)].transition_list_vec));
	}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 708 "grammar.yy"
    {
		(yyval.transition_list_vec) = new vector<Transition*>();
	}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 712 "grammar.yy"
    {
		(yyval.transition_list_vec) = (yysemantic_stack_[(2) - (1)].transition_list_vec);
		(yyval.transition_list_vec) -> push_back((yysemantic_stack_[(2) - (2)].transition_ptr));
	}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 719 "grammar.yy"
    {
		(yyval.transition_ptr) = new Transition((yysemantic_stack_[(5) - (2)].node_ptr), (yysemantic_stack_[(5) - (3)].node_ptr), (yysemantic_stack_[(5) - (4)].gd_ptr));		
	}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 725 "grammar.yy"
    {
		// Check if the node is already defined
		Node* node = (Node*)(symtable.get(*(yysemantic_stack_[(1) - (1)].string_ptr),NODE));
		
		if (node == NULL){// Not defined, defining here			
			node = new Node(*(yysemantic_stack_[(1) - (1)].string_ptr));
			symtable.add(node, NODE);
		}		
		(yyval.node_ptr) = node;
		delete ((yysemantic_stack_[(1) - (1)].string_ptr));
	}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 743 "grammar.yy"
    {
		(yyval.constant_vec) = new vector<Constant*>();
	}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 748 "grammar.yy"
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

  case 73:

/* Line 678 of lalr1.cc  */
#line 790 "grammar.yy"
    {
		(yyval.init_elem_list_vec) = (yysemantic_stack_[(4) - (3)].init_elem_list_vec);
	}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 796 "grammar.yy"
    {
		(yyval.init_elem_list_vec) = new vector<InitElement*>();
	}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 800 "grammar.yy"
    {
		(yyval.init_elem_list_vec) = (yysemantic_stack_[(2) - (1)].init_elem_list_vec);
		(yyval.init_elem_list_vec) -> push_back(new InitElement((yysemantic_stack_[(2) - (2)].literal_ptr)));
	}
    break;



/* Line 678 of lalr1.cc  */
#line 1360 "grammar.tab.cc"
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
  const signed char Pddl30Parser::yypact_ninf_ = -115;
  const signed char
  Pddl30Parser::yypact_[] =
  {
        21,    48,    61,    36,    37,  -115,    62,  -115,    60,    40,
      43,    50,    42,    46,    65,    45,     7,  -115,    47,  -115,
    -115,    -5,  -115,    66,    69,  -115,  -115,  -115,    67,    52,
      15,  -115,    68,    51,  -115,  -115,     5,    16,    54,  -115,
      63,  -115,    57,  -115,    59,     4,  -115,    58,    72,  -115,
      64,  -115,  -115,  -115,  -115,  -115,    70,  -115,    17,    71,
      73,   -21,    74,  -115,  -115,    75,  -115,  -115,    20,    76,
    -115,    27,    77,  -115,    79,  -115,    78,     0,  -115,  -115,
    -115,  -115,    80,  -115,    25,    82,    81,    83,  -115,    84,
    -115,    -8,  -115,  -115,    85,    86,    88,    87,    22,    92,
    -115,    90,  -115,  -115,    -6,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,    29,    93,    91,    11,  -115,
      90,  -115,    31,    -4,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,    33,    94,    77,    95,  -115,     8,  -115,  -115,  -115,
      77,  -115,    97,    98,  -115
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Pddl30Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     3,     0,     9,
      10,     0,     8,    11,     0,     6,     7,    56,    13,     0,
       0,    56,    15,     0,    59,    12,    58,     0,     0,    21,
      71,    60,     0,    14,     0,     0,    17,     0,    20,    56,
       0,    57,    61,    16,    18,     4,     0,    22,     0,     0,
       0,     0,    25,    72,    74,     0,    64,    19,    63,     0,
      23,     0,     0,    65,     0,    61,    27,     0,    73,    55,
      75,    70,     0,    62,     0,     0,    44,     0,    37,     0,
      26,     0,    29,    30,     0,     0,     0,     0,     0,     0,
      33,     0,    40,    28,     0,    53,    47,    48,    51,    24,
      54,    39,    36,    38,    67,     0,     0,     0,     0,    49,
       0,    45,     0,     0,    32,    34,    31,    43,    35,    42,
      41,     0,     0,     0,     0,    68,     0,    46,    50,    52,
       0,    66,     0,     0,    69
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Pddl30Parser::yypgoto_[] =
  {
      -115,  -115,  -115,  -115,  -115,  -115,    99,  -115,  -115,  -115,
    -115,    41,  -115,  -115,  -115,  -115,  -115,  -115,  -114,  -115,
     -94,     1,  -115,   -29,  -115,  -115,  -115,   -38,  -115,  -115,
    -115,  -115,   -26,  -115,    23,  -115,  -115,  -115,  -115,  -106,
    -115,  -115,  -115
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Pddl30Parser::yydefgoto_[] =
  {
        -1,     2,     3,    23,    17,    21,    22,    28,    32,    39,
      45,    46,    47,    48,    57,    76,    70,    86,    92,   115,
      93,    79,    98,   113,   118,   130,    95,   106,   131,   107,
     108,    80,    30,    36,    61,    68,     7,   122,   135,    82,
      50,    60,    71
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Pddl30Parser::yytable_ninf_ = -1;
  const unsigned char
  Pddl30Parser::yytable_[] =
  {
       105,   125,    19,    20,    66,    37,    67,   117,   100,   101,
     119,   120,   100,   101,    19,    20,   102,    87,   102,   103,
     102,   121,    25,    58,    88,   120,   132,   140,   143,    41,
      44,    53,   102,    42,   142,   111,   127,   105,   128,    34,
      34,    34,    35,    43,    63,    73,   111,     1,    74,   112,
      66,     4,    90,    77,    78,   123,   124,   133,   134,   136,
     137,     5,     6,     8,    10,     9,    11,    12,    13,    14,
      15,    16,    18,    24,    29,    27,    33,    31,    40,    38,
      44,    51,    49,    52,    56,    55,    54,    69,    97,   129,
      59,    64,    85,   138,    62,     0,    94,    72,    84,    65,
       0,    81,    75,    83,     0,     0,     0,    89,    91,    96,
      99,   104,    88,   109,   110,   114,   116,   102,   126,     0,
      26,   139,   141,   123,     0,   144
  };

  /* YYCHECK.  */
  const short int
  Pddl30Parser::yycheck_[] =
  {
        94,   115,     7,     8,    25,    31,    27,   101,    16,    17,
      16,    17,    16,    17,     7,     8,    24,    17,    24,    27,
      24,    27,    27,    49,    24,    17,   120,   133,   142,    24,
      26,    27,    24,    28,   140,    24,    25,   131,    27,    24,
      24,    24,    27,    27,    27,    25,    24,    26,    28,    27,
      25,     3,    27,    26,    27,    26,    27,    26,    27,    26,
      27,     0,    26,    26,     4,     3,    26,    24,    18,    27,
      24,     6,    27,    26,     5,     9,    24,    10,    27,    11,
      26,    24,    19,    24,    12,    27,    45,    13,    87,   118,
      26,    20,    14,   131,    24,    -1,    15,    22,    75,    26,
      -1,    24,    26,    24,    -1,    -1,    -1,    27,    26,    26,
      26,    26,    24,    27,    27,    23,    26,    24,    27,    -1,
      21,    27,    27,    26,    -1,    27
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Pddl30Parser::yystos_[] =
  {
         0,    26,    30,    31,     3,     0,    26,    65,    26,     3,
       4,    26,    24,    18,    27,    24,     6,    33,    27,     7,
       8,    34,    35,    32,    26,    27,    35,     9,    36,     5,
      61,    10,    37,    24,    24,    27,    62,    61,    11,    38,
      27,    24,    28,    27,    26,    39,    40,    41,    42,    19,
      69,    24,    24,    27,    40,    27,    12,    43,    61,    26,
      70,    63,    24,    27,    20,    26,    25,    27,    64,    13,
      45,    71,    22,    25,    28,    26,    44,    26,    27,    50,
      60,    24,    68,    24,    63,    14,    46,    17,    24,    27,
      27,    26,    47,    49,    15,    55,    26,    50,    51,    26,
      16,    17,    24,    27,    26,    49,    56,    58,    59,    27,
      27,    24,    27,    52,    23,    48,    26,    49,    53,    16,
      17,    27,    66,    26,    27,    47,    27,    25,    27,    52,
      54,    57,    49,    26,    27,    67,    26,    27,    56,    27,
      68,    27,    68,    47,    27
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Pddl30Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    40,    41,    45
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Pddl30Parser::yyr1_[] =
  {
         0,    29,    30,    32,    31,    33,    33,    34,    34,    35,
      35,    36,    36,    37,    37,    38,    38,    39,    39,    40,
      41,    42,    42,    44,    43,    45,    45,    46,    46,    46,
      47,    47,    47,    48,    48,    49,    50,    51,    51,    52,
      53,    53,    54,    54,    55,    55,    55,    55,    56,    57,
      57,    58,    59,    59,    60,    60,    61,    61,    61,    62,
      62,    63,    63,    63,    64,    64,    65,    66,    66,    67,
      68,    69,    69,    70,    71,    71
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Pddl30Parser::yyr2_[] =
  {
         0,     2,     2,     0,    13,     0,     3,     2,     1,     1,
       1,     0,     3,     0,     3,     0,     3,     1,     2,     4,
       1,     0,     2,     0,     7,     0,     4,     0,     3,     2,
       1,     4,     4,     0,     2,     4,     4,     0,     2,     1,
       0,     2,     1,     1,     0,     3,     5,     2,     1,     0,
       2,     1,     4,     1,     4,     1,     0,     4,     2,     1,
       2,     0,     4,     2,     1,     2,    21,     0,     2,     5,
       1,     0,     3,     4,     0,     2
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
  "EFFECT", "AND", "NOT", "PLANPROG", "OBJECTS", "INIT", "GOAL",
  "INITNODE", "TRANSITIONS", "NAME", "VARIABLE", "'('", "')'", "'-'",
  "$accept", "specfication", "domain", "$@1", "require_def",
  "require_list", "require_key", "types_def", "constants_def",
  "predicates_def", "predicate_list", "single_predicate_def",
  "actions_def", "actions_def_list", "single_action_def", "$@2",
  "parameters", "precondition", "gd", "gd_list", "atomic_formula_term",
  "atomic_formula_name", "const_list", "constant_ref", "term_list", "term",
  "effect", "c_effect", "c_effect_list", "p_effect", "literal_term",
  "literal_name", "typed_list_name", "untyped_list_name",
  "typed_list_variable", "untyped_list_variable", "planning_program",
  "transition_list", "transition", "node", "object_decl", "init",
  "init_elem_list", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Pddl30Parser::rhs_number_type
  Pddl30Parser::yyrhs_[] =
  {
        30,     0,    -1,    31,    65,    -1,    -1,    26,     3,    26,
       4,    24,    27,    33,    32,    36,    37,    38,    41,    27,
      -1,    -1,     6,    34,    27,    -1,    34,    35,    -1,    35,
      -1,     7,    -1,     8,    -1,    -1,     9,    61,    27,    -1,
      -1,    10,    61,    27,    -1,    -1,    11,    39,    27,    -1,
      40,    -1,    39,    40,    -1,    26,    24,    63,    27,    -1,
      42,    -1,    -1,    42,    43,    -1,    -1,    12,    24,    45,
      44,    46,    55,    27,    -1,    -1,    13,    26,    63,    27,
      -1,    -1,    14,    26,    27,    -1,    14,    47,    -1,    49,
      -1,    26,    17,    49,    27,    -1,    26,    16,    48,    27,
      -1,    -1,    48,    47,    -1,    26,    24,    53,    27,    -1,
      26,    24,    51,    27,    -1,    -1,    51,    52,    -1,    24,
      -1,    -1,    53,    54,    -1,    52,    -1,    25,    -1,    -1,
      15,    26,    27,    -1,    15,    26,    16,    57,    27,    -1,
      15,    56,    -1,    58,    -1,    -1,    57,    56,    -1,    59,
      -1,    26,    17,    49,    27,    -1,    49,    -1,    26,    17,
      50,    27,    -1,    50,    -1,    -1,    61,    62,    28,    24,
      -1,    61,    62,    -1,    24,    -1,    62,    24,    -1,    -1,
      63,    64,    28,    24,    -1,    63,    64,    -1,    25,    -1,
      64,    25,    -1,    26,     3,    26,    18,    24,    27,    26,
       5,    24,    27,    69,    70,    26,    22,    68,    27,    26,
      23,    66,    27,    27,    -1,    -1,    66,    67,    -1,    26,
      68,    68,    47,    27,    -1,    24,    -1,    -1,    19,    61,
      27,    -1,    26,    20,    71,    27,    -1,    -1,    71,    60,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Pddl30Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     7,    21,    22,    26,    29,    31,
      33,    35,    36,    40,    41,    45,    46,    50,    52,    55,
      60,    62,    63,    66,    67,    75,    76,    81,    82,    86,
      89,    91,    96,   101,   102,   105,   110,   115,   116,   119,
     121,   122,   125,   127,   129,   130,   134,   140,   143,   145,
     146,   149,   151,   156,   158,   163,   165,   166,   171,   174,
     176,   179,   180,   185,   188,   190,   193,   215,   216,   219,
     225,   227,   228,   232,   237,   238
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Pddl30Parser::yyrline_[] =
  {
         0,   145,   145,   152,   152,   169,   175,   181,   187,   194,
     196,   204,   209,   255,   260,   302,   307,   313,   318,   325,
     346,   352,   356,   364,   364,   382,   386,   392,   396,   400,
     406,   410,   414,   421,   425,   433,   463,   491,   495,   502,
     515,   519,   526,   530,   544,   548,   552,   557,   563,   569,
     573,   581,   587,   591,   597,   601,   613,   617,   623,   631,
     636,   646,   650,   664,   674,   679,   689,   708,   712,   719,
     725,   743,   748,   790,   796,   800
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
      26,    27,     2,     2,     2,    28,     2,     2,     2,     2,
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
      25
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Pddl30Parser::yyeof_ = 0;
  const int Pddl30Parser::yylast_ = 125;
  const int Pddl30Parser::yynnts_ = 43;
  const int Pddl30Parser::yyempty_ = -2;
  const int Pddl30Parser::yyfinal_ = 5;
  const int Pddl30Parser::yyterror_ = 1;
  const int Pddl30Parser::yyerrcode_ = 256;
  const int Pddl30Parser::yyntokens_ = 29;

  const unsigned int Pddl30Parser::yyuser_token_number_max_ = 280;
  const Pddl30Parser::token_number_type Pddl30Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yy

/* Line 1054 of lalr1.cc  */
#line 1912 "grammar.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 816 "grammar.yy"



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


