#include "ast.h"

// Output operators -- Put here, before namespaces inclusion directives

std::ostream& std::operator<<(std::ostream &o, const ast::Symbol& s){
	o << s.getName();
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const ast::TypedSymbol& t){
	o << (ast::Symbol) t;
	if (t.getType() != NULL){
		o << " - " << (ast::TypedSymbol)(*(t.getType()));
	}
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const ast::Term& t){
	o << (ast::TypedSymbol) t;
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const ast::Constant& c){
	o << (ast::TypedSymbol) c;
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const ast::Variable& v){
	o << (ast::TypedSymbol) v;
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const ast::Type& t){	
	o << (ast::TypedSymbol) t << ":{";
	std::set<const ast::Constant*>::iterator it = t.getConstants().begin();
	std::set<const ast::Constant*> constants = t.getConstants();
	for (std::set<const ast::Constant*>::iterator it = constants.begin(); it != constants.end(); it++){
		o << " " << **it;
	}
	o << "}";
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const std::vector<ast::Term*> t){
	for (unsigned int i = 0; i < t.size(); i++){
		o << *t[i];
		if (i < t.size() - 1){
			o << " ";
		}
	}	
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const std::vector<ast::Variable*> t){
	std::vector<ast::Term*> terms;
	for (unsigned int i = 0; i < t.size(); i++){
		terms.push_back((ast::Term*) t[i]);
		}
	o << terms;
	return o;
}	

std::ostream& std::operator<<(std::ostream &o, const std::vector<ast::Constant*> t){
	std::vector<ast::Term*> terms;
	for (unsigned int i = 0; i < t.size(); i++){
		terms.push_back((ast::Constant*) t[i]);
		}
	o << terms;
	return o;
}	

std::ostream& std::operator<<(std::ostream &o, const ast::Predicate& p){
	o << (ast::Symbol) p << "(" << p.getArguments() << ")";
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const ast::AtomicFormulaTerm& p){
	o << p.getPredicate() -> getName() << "(" << p.getTerms() << ")";
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const ast::GD& gd){
	if (gd.getAtom() != NULL){
		o << *(gd.getAtom());
	}
	else{
		std::vector<ast::GD*> conjuncts = gd.getConjuncts();
		o << "(and";
		for (unsigned int i = 0; i < conjuncts.size(); i++){
			o << " " << *conjuncts[i];
		}
		o << ")"; 
	}
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const ast::PrefGD& prefGD){
	o << prefGD.getGd();
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const ast::PreGD& preGD){
	if (preGD.getPrefGD() != NULL){
		o << preGD.getPrefGD();
	}
	else{
		std::set<ast::PreGD*> gds = preGD.getConjuncts();
		o << "(and";
		for (std::set<ast::PreGD*>::iterator it = gds.begin(); it != gds.end(); it++){
			o << " " << *it;
		}
		o << ")";
	}
	return o;
}

std::ostream& std::operator<<(std::ostream& o, const ast::Effect& effect){
	if (effect.getCEffect() != NULL){
		o << *(effect.getCEffect());
	}
	else{
		std::vector<ast::CEffect*> conjs = effect.getConjuncts();
		o << "(and";
		for (unsigned int i = 0; i < conjs.size(); i++){
			o << " " << *conjs[i];
		}
		o << ")";
	}
	return o;
}

std::ostream& std::operator<<(std::ostream& o, const ast::PEffect& pEffect){
	if (pEffect.getLiteral() != NULL){
		o << *pEffect.getLiteral();
	}
	return o;
}

std::ostream& std::operator<<(std::ostream& o, const ast::Literal& literal){
	if (literal.isNegated()){
		o << "(not " << *(literal.getAtomicFormulaTerm()) << ")";
	}
	else{
		o << *(literal.getAtomicFormulaTerm());		
	}
	return o;
}



std::ostream& std::operator<<(std::ostream& o, const ast::CEffect& cEffect){
	o << *cEffect.getPEffect();
	return o;
}

std::ostream& std::operator<<(std::ostream& o, const ast::Action& action){
	o << "(:action " << action.getName() << endl << "\t";
	o << "(:parameters " << action.getParameters() << ")" << endl << "\t";
	o << "(:precondition ";
	if (action.getPrecondition() != NULL){
		o << *action.getPrecondition();
	}
	o << ")" << endl << "\t";
	o << "(:effect ";
	if (action.getEffect() != NULL){
		o << *action.getEffect();
	}
	o << ")" << endl << "\t";
	o << ")";
	return o;
}

std::ostream& std::operator<<(std::ostream &o, const ast::Domain& d){
	o << "(domain " << d.getName() << endl;

	// Requirements
	o << "\t(:requirements";
	std::vector<std::string> requirements = d.getRequirements();
	for (unsigned int i = 0; i < requirements.size(); i++){
		o << " " << requirements[i];
	}
	o << ")" << endl;
	
	// Types
	o << "\t(:types";
	std::vector<ast::Type*> types = d.getTypes();
	for (unsigned int i = 0; i < types.size(); i++){
		o << " " << *(types[i]);
	}
	o << ")" << endl;
	
	// Constants
	o << "\t(:constants";
	std::vector<ast::Constant*> constants = d.getConstants();
	for (unsigned int i = 0; i < constants.size(); i++){
		o << " " << *(constants[i]);
	}
	o << ")" << endl;
	
	// Predicates
	o << "\t(:predicates";
	std::vector<const ast::Predicate*> predicates = d.getPredicates();
	for (unsigned int i = 0; i < predicates.size(); i++){
		o << endl << "\t\t" << *(predicates[i]);
	}
	o << endl << "\t)" << endl;
	
	// Actions
	std::vector<const ast::Action*> actions = d.getActions();
	for (unsigned int i = 0; i < actions.size(); i++){
		o << "\t" << *(actions[i]) << endl;
	}
	
	o << ")";
	return o;
}

std::ostream& std::operator<<(std::ostream& o, const ast::InitElement& ie){
	if (ie.getLiteral()!= NULL){
		o << *ie.getLiteral();
	}
	return o;
}

std::ostream& std::operator<<(std::ostream& o, const ast::Problem& p){
	o << "(:problem " << p.getName() << endl; 
	o << "\t(:domain ";
	if (p.getDomain() != NULL){
		o << p.getDomain() -> getName();
	}
	o << ")" << endl;;
		
	// Requirements
	o << "\t(:requirements";
	std::vector<std::string> requirements = p.getRequirements();
	for (unsigned int i = 0; i < requirements.size(); i++){
		o << " " << requirements[i];
	}
	o << ")" << endl;

	// Objects
	o << "\t(:objects";
	std::vector<ast::Constant*> objects = p.getObjects();
	for (unsigned int i = 0; i < objects.size(); i++){
		o << " " << *(objects[i]);
	}
	o << ")" << endl;
	
	// Init
	o << "\t(:init";
	std::vector<ast::InitElement*> init = p.getInit();
	for (unsigned int i = 0; i < init.size(); i++){
		o << " " << *(init[i]);
	}
	o << ")" << endl;
	
	if (p.getGoal() != NULL){
		o << "\t(:goal " << *p.getGoal() << ")" << endl;
	}
	o << ")";

	return o;
}

std::ostream& std::operator<<(std::ostream& o, const ast::Instance& i){
	if (i.getDomain() != NULL){
		o << *i.getDomain() << endl;
	}
	if (i.getProblem() != NULL){
		o << *i.getProblem() << endl;
	}
	return o;
}

std::ostream& std::operator<<(std::ostream& o, const std::vector<ast::InitElement*> d){
	for (unsigned int i = 0; i < d.size(); i++){
		o << " " << *d[i];
	}
	return o;
}



// AST class definitions

using namespace ast;
using namespace std;

/* Symbol */
Symbol::Symbol(const string& name){
	this -> name = name;
}

string Symbol::getName() const{
	return name;
}

/* TypedSymbol */
TypedSymbol::TypedSymbol(const string& name, Type* type) : Symbol(name){
	this -> type = type;
}

Type* TypedSymbol::getType() const{
	return type;
}

/* Type */
Type::Type(const string& name, Type* supertype) : TypedSymbol(name, supertype){};

set<const Constant*> Type::getConstants() const{
	return constants;
}

/* Term */
Term::Term(const std::string& name, Type* type) : TypedSymbol(name, type) {};


/* Constant */
Constant::Constant(const string& name, Type* type) : Term(name, type){
	while (type != NULL){		
		// Adds the constant to type and all of its supertypes
		type -> constants.insert(this);
		type = type -> getType();
	}
};

set<const Constant*> Constant::valuate() const{
	set<const Constant*> result;
	result.insert(this);
	return result;
}


/* Variable */
Variable::Variable(const string& name, Type* type) : Term(name, type){};

set<const Constant*> Variable::valuate() const{
	return this -> getType() -> getConstants();
}


/* Predicate */
Predicate::Predicate(const string& name, const vector<Variable*>& arguments) : Symbol(name){
	this -> arguments = arguments;
}

vector<Variable*> Predicate::getArguments() const{
	return arguments;
}

vector<Predicate*> Predicate::valuate() const{
	vector<Predicate*> new_preds;
	vector<vector<const Constant*> > tuples = ast::valuate(arguments);
	string cur_name;
	
	for (unsigned int i = 0; i < tuples.size(); i++){
		vector<const Constant*> tup = tuples[i];
		cur_name = getName();
		for (unsigned int j = 0; j < tup.size(); j++){
			cur_name += "_" + tup[j] -> getName();
		}
		new_preds.push_back(new Predicate(cur_name));
	}
	
	return new_preds;
}

const Predicate* Predicate::valuate(vector<const Constant*> valuations, vector<const Predicate*> groundPredicates) const{
	string name = getName();
	for(unsigned int i = 0; i < valuations.size(); i++){
		name += "_"+valuations[i] -> getName();
	}
	// Searches for the same predicate in groundPredicates
	for(unsigned int i = 0; i < groundPredicates.size(); i++){
		if (name == groundPredicates[i]->getName()){
			return groundPredicates[i];
		}
	}
	// This should never happen
	cerr << "ERROR in Predicate::valuate()" << endl;
	exit(1);
	
	return new Predicate(name);
}


/* AtomicFormulaTerm */
AtomicFormulaTerm::AtomicFormulaTerm(const Predicate* predicate, std::vector<Term*> terms){
	this -> predicate = predicate;
	this -> terms = terms;
}

const Predicate* AtomicFormulaTerm::getPredicate() const{
	return predicate;
}


std::vector<Term*> AtomicFormulaTerm::getTerms() const{
	return terms;
}

bool AtomicFormulaTerm::isArityConsistent(){
	return (predicate -> getArguments().size() == terms.size());
}

Term* AtomicFormulaTerm::isTypeConsistent(){
	// If terms is not arity-consistent with predicate returns NULL
	std::vector<Variable*> predArgs = predicate -> getArguments();
	if (predArgs.size() != terms.size()){
		return NULL;
	}
	for (unsigned int i = 0; i < predArgs.size(); i++){
		if (predArgs[i]->getType() != terms[i]->getType()){
			// check if the term is of subtype of current pred arg type
			Type* superType = terms[i]->getType()->getType();
			bool typeOk = false;
			while(superType != NULL && !typeOk){
				typeOk = (superType == predArgs[i]->getType());
				superType = superType -> getType();
			}
			if (!typeOk){
				return terms[i];
			}
		}
	}
	return NULL;
}


AtomicFormulaTerm* AtomicFormulaTerm::valuate(map<const Variable*, const Constant*> valuations, vector<const Predicate*> groundPredicates) const{
	vector<const Constant* > constants;
	for (unsigned int i = 0; i < terms.size(); i++){
		const Constant* c = dynamic_cast<Constant*> (terms[i]);
		if (c != NULL){// terms[i] is a constant
			constants.push_back(c);
		}
		else{// terms[i] is a variable
			constants.push_back(valuations[(Variable*) terms[i]]);			
		}
	}
	return new AtomicFormulaTerm(predicate -> valuate(constants,groundPredicates));
}




/* Literal */
Literal::Literal(AtomicFormulaTerm* atomicFormulaTerm, bool negated){
	this -> atomicFormulaTerm = atomicFormulaTerm;
	this -> negated = negated;
}

bool Literal::isNegated() const{
	return negated;
}

AtomicFormulaTerm* Literal::getAtomicFormulaTerm() const{
	return atomicFormulaTerm;
};

Literal* Literal::valuate(std::map<const Variable*, const Constant*> valuations, vector<const Predicate*> groundPredicates) const{
	return new Literal(atomicFormulaTerm->valuate(valuations,groundPredicates),negated);
}


/* GD */
GD::GD(Literal* atom){
	this -> atom = atom;
}

GD::GD(std::vector<GD*> conjuncts){
	atom = NULL;
	this -> conjuncts = conjuncts;
}

Literal* GD::getAtom() const{
	return atom;
}

std::vector<GD*> GD::getConjuncts() const{
	return conjuncts;
}


GD* GD::valuate(map<const Variable*, const Constant*> valuations, vector<const Predicate*> groundPredicates) const{
	if (atom != NULL){// The goal is an atom
		Literal* groundAtom = atom->valuate(valuations, groundPredicates);
		if (groundAtom == NULL){
			return NULL;
		}
		return new GD(groundAtom);
	}
	else{// The goal is a conjunction of goals
		vector<GD*> groundConjuncts;
		for (unsigned int i=0; i < conjuncts.size(); i++){
			GD* groundConj = conjuncts[i]->valuate(valuations, groundPredicates);
			if (groundConj == NULL){
				return NULL;
			}
			groundConjuncts.push_back(groundConj);
		}
		return new GD(groundConjuncts);
	}
}





/* PrefGD */
PrefGD::PrefGD(GD* gd){
	this -> gd = gd;
}

GD* PrefGD::getGd() const{
	return gd;
};

/* PreGD */
PreGD::PreGD(PrefGD* prefGD){
	this -> prefGD = prefGD;
}

PreGD::PreGD(const std::set<PreGD*> conjuncts){
	prefGD = NULL;
	this -> conjuncts = conjuncts;
}

PrefGD* PreGD::getPrefGD() const{
	return prefGD;
}

std::set<PreGD*> PreGD::getConjuncts() const{
	return conjuncts;
};

/*Action*/
Action::Action(const std::string& name, const std::vector<Variable*>& parameters, GD* precondition, const Effect* effect) : Symbol(name){
	this -> parameters = parameters;
	this -> precondition = precondition;
	this -> effect = effect;
	// Set up affected predicates
}

std::vector<Variable*> Action::getParameters() const{
	return parameters;
}

GD* Action::getPrecondition() const{
	return precondition;
}

const Effect* Action::getEffect() const{
	return effect;
}

vector<Action*> Action::valuate(vector<const Predicate*> groundPredicates) const{
	vector<Action*> new_acts;
	 
	//Associate each variable to the value currently assigned
	map<const Variable*, const Constant*> valuations; // association variables-values
	vector<Variable* > variables = parameters; // variables
	vector<vector<const Constant*> > values = ast::valuate(parameters); // values
	
	for (unsigned int i = 0; i < values.size(); i++){ // Generate one action per valuation		
		// Associate each variable with its valuation
		for (unsigned int j = 0; j < variables.size(); j++){
			valuations[variables[j]] = values[i][j];
		}
		
		string new_name = getName();
		// Build the action name
		for (unsigned int j = 0; j < variables.size(); j++){
			new_name += "_" + valuations[variables[j]] -> getName();
		}
		
		vector<Variable* > new_parameters; // the new (ground) action has no parameters
		
		
		GD* new_precondition = NULL;
		if (precondition != NULL){
			new_precondition = precondition->valuate(valuations, groundPredicates);
		}
		
		const Effect* new_effect = NULL;
		if (effect != NULL){
			new_effect = effect->valuate(valuations, groundPredicates);
		}
			
		new_acts.push_back(new Action(new_name, new_parameters, new_precondition, new_effect));
	}
	
	return new_acts;	
}


set<const Predicate* > Action::affectedPredicates() const{
	set<const Predicate* > result;
	if (effect != NULL){
		result = effect->occurringPredicates();
	}
	return result;
}

set<const Literal*> Action::affectingLiterals(const Predicate* p) const{
	set<const Literal*> result;
	if (effect != NULL){
		result = effect -> affectingLiterals(p);
	}
	return result;
}


/* Effect */
Effect::Effect(CEffect* cEffect){
	this -> cEffect = cEffect;
}
	
Effect::Effect(std::vector<CEffect*> conjuncts){
	cEffect = NULL;
	this -> conjuncts = conjuncts;
}

CEffect* Effect::getCEffect() const{
	return cEffect;
}

std::vector<CEffect*> Effect::getConjuncts() const{
	return conjuncts;
}

const Effect* Effect::valuate(std::map<const Variable*, const Constant*> valuations, vector<const Predicate*> groundPredicates) const{
	if (cEffect != NULL){
		return new Effect(cEffect -> valuate(valuations, groundPredicates));
	}
	vector <CEffect*> cEffects;
	for (unsigned int i = 0; i < conjuncts.size(); i++){
		cEffects.push_back(conjuncts[i]->valuate(valuations, groundPredicates));
	}
	return new Effect(cEffects);
}

std::set<const Predicate* > Effect::occurringPredicates() const{
	set<const Predicate* > result;
	if (cEffect != NULL){
		const Predicate* pred = cEffect->occurringPredicate();
		if (pred != NULL){
			result.insert(pred);
		}
	}
	else{
		for (unsigned int i = 0; i < conjuncts.size(); i++){
			const Predicate* pred = conjuncts[i]->occurringPredicate();
			if (pred != NULL){
				result.insert(pred);
			}
		}
	}
	return result;
}



set<const Literal*> Effect::affectingLiterals(const Predicate* p) const{
	set<const Literal*> result;
	if (cEffect != NULL){
		result = cEffect->affectingLiterals(p);
	}
	else{
		for (unsigned int i = 0; i < conjuncts.size(); i++){
			set<const Literal*> new_literals = conjuncts[i]->affectingLiterals(p);
			result.insert(new_literals.begin(),new_literals.end());
		}
	}
	return result;
}



/* CEffect */
CEffect::CEffect(PEffect* pEffect){
	this -> pEffect = pEffect;
}

PEffect* CEffect::getPEffect() const{
	return pEffect;
}

CEffect* CEffect::valuate(map<const Variable*, const Constant*> valuations, vector<const Predicate*> groundPredicates) const{
	return new CEffect(pEffect -> valuate(valuations, groundPredicates));
}

const Predicate* CEffect::occurringPredicate() const{
	if (pEffect != NULL){
		return pEffect->occurringPredicate();
	}
	return NULL;
}

set<const Literal*> CEffect::affectingLiterals(const Predicate* p) const{
	set<const Literal*> result;
	if (pEffect != NULL){
		if (pEffect -> getLiteral() != NULL)
			if (pEffect -> getLiteral() ->getAtomicFormulaTerm() != NULL){
				if (pEffect -> getLiteral() ->getAtomicFormulaTerm() -> getPredicate() == p){
					result.insert(pEffect -> getLiteral());
				}
			}
	}
	return result;
}




/* PEffect */
PEffect::PEffect(Literal* literal){
	this -> literal = literal;
}

Literal* PEffect::getLiteral() const{
	return literal;
}

PEffect* PEffect::valuate(std::map<const Variable*, const Constant*> valuations, vector<const Predicate*> groundPredicates) const{
	return new PEffect(literal->valuate(valuations, groundPredicates));
}

const Predicate* PEffect::occurringPredicate() const{
	if (literal != NULL){
		if (literal->getAtomicFormulaTerm() != NULL){
			if (literal->getAtomicFormulaTerm()->getPredicate() != NULL)
				return literal->getAtomicFormulaTerm()->getPredicate();
		}
	}
	return NULL;
}

/* Domain */
Domain::Domain():Symbol(""){};


Domain::Domain(const std::string& name, 
		const std::vector<std::string>& requirements, 
		const std::vector<Type*>& types, 
		const std::vector<Constant*>& constants, 
		const std::vector<const Predicate*>& predicates, 
		const std::vector<const Action*>& actions) : Symbol(name){
	this -> requirements = requirements;
	this -> types = types;
	this -> constants = constants;
	this -> predicates = predicates;
	this -> actions = actions;
}

vector<std::string> Domain::getRequirements() const{
	return requirements;
}

vector<Type*> Domain::getTypes() const{
	return types;
}

vector<Constant*> Domain::getConstants() const {
	return constants;
}

vector<const Predicate*> Domain::getPredicates() const{
	return predicates;
}

vector<const Action*> Domain::getActions() const{
	return actions;
}

Domain* Domain::valuate() const{
	// Intermediate results
	vector<const Predicate*> groundPredicates;
	vector<const Action*> groundActions;
	
	for (unsigned int i = 0; i < predicates.size(); i++){
		vector<Predicate*> cur_ground_predicates = predicates[i]->valuate();
		groundPredicates.insert(groundPredicates.end(), cur_ground_predicates.begin(), cur_ground_predicates.end());
	}
	
	for (unsigned int i = 0; i < actions.size(); i++){
		vector<Action*> cur_ground_actions = actions[i] -> valuate(groundPredicates);
		groundActions.insert(groundActions.end(), cur_ground_actions.begin(), cur_ground_actions.end());
	}
	
	// Create result domain
	return new Domain(
			"grnd_"  +  getName(),
			requirements, 
			types, 
			constants, 
			groundPredicates,
			groundActions);
}



/* TypedStringList */
TypedStringList::TypedStringList(const std::vector<std::string>& strings, std::string* type){
	this -> strings = strings;
	this -> typeString = type;			
}

std::vector<std::string> TypedStringList::getStrings() const{
	return strings;
}

std::string* TypedStringList::getTypeString() const{
	return typeString;
}


/* InitElement */
	InitElement::InitElement(Literal* literal){
	this -> literal = literal;
}

Literal* InitElement::getLiteral() const{
	return literal;
}

/* Problem */
Problem::Problem(const string& name, Domain* domain, vector<std::string> requirements, vector<Constant*> objects, vector<InitElement*> init, GD* goal) : Symbol(name){
	this -> domain =  domain;
	this -> requirements = requirements;
	this -> objects = objects;
	this -> init = init;
	this -> goal = goal;
}

Domain* Problem::getDomain() const{
	return domain;
}

vector<std::string> Problem::getRequirements() const{
	return requirements;
}
vector<Constant*> Problem::getObjects() const{
	return objects;
}

vector<InitElement*> Problem::getInit() const{
	return init;
}

GD* Problem::getGoal() const{
	return goal;
}

/* Instance */
Instance::Instance(){
	this -> domain = NULL;
	this -> problem = NULL;
}

Instance::Instance(Domain* domain, Problem* problem){
	this -> domain = domain;
	this -> problem = problem;
}
	
	
Domain* Instance::getDomain() const{
	return domain;
}

Problem* Instance::getProblem() const{
	return problem;
}


vector<vector<const Constant*> > ast::valuate(vector<Term*> terms){
	vector<vector<const Constant*> > result;
	if (terms.size() == 0){
		result.push_back(*(new vector<const Constant*>));
		return result;
	}
	if (terms.size() == 1){
		// Base case
		set<const Constant*> constants = terms.back()->valuate();
		for (set<const Constant*>::iterator it = constants.begin(); it != constants.end(); it++){
			vector<const Constant*> cur_tup;
			cur_tup.push_back(*it);
			result.push_back(cur_tup);
		}
		return result;
	}
	// Recursive step
	
	// Split vector components
	vector<Term*> tail;
	tail.push_back(terms.back());
	terms.pop_back();
	
	// Valuate separately
	vector<vector<const Constant*> > terms_result = valuate(terms);
	vector<vector<const Constant*> > tail_result = valuate(tail);
	
	// Merge
	for(unsigned int i = 0; i < terms_result.size(); i++){
		vector<const Constant*> cur_vec = terms_result[i];
		for(unsigned int j = 0; j < tail_result.size(); j++){
			vector<const Constant*> new_vec = cur_vec;
			new_vec.push_back(tail_result[j].back());
			result.push_back(new_vec);
		}
	}
	return result;
}


vector<vector<const Constant*> > ast::valuate(vector<Variable*> vars){
	vector<Term*> terms;
	for (unsigned int i = 0; i < vars.size(); i++){
		terms.push_back((Term*)vars[i]);
	}
	return valuate(terms);
}

