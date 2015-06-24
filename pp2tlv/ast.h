#ifndef AST_H_
#define AST_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

namespace ast{
	// Class declaration required here for I/O operators definition
	class Symbol;
	class Type;
	class TypedSymbol;
	class Term;
	class Variable;
	class Constant;
	class Predicate;
	class AtomicFormulaTerm;
	class GD;
	class PrefGD;
	class PreGD;
	class Effect;	
	class CEffect;	
	class PEffect;
	class Action;
	class Domain;
	class Literal;
	class InitElement;
	class Problem;
	class Instance;
}

namespace std{
	// Must be re-define here, to avoid problems when mixing namespaces
	ostream& operator<<(ostream& o, const ast::Symbol& s);
	ostream& operator<<(ostream& o, const ast::TypedSymbol& t);
	ostream& operator<<(ostream &o, const ast::Term& t);
	ostream& operator<<(ostream &o, const ast::Constant& t);
	ostream& operator<<(ostream &o, const ast::Variable& t);
	ostream& operator<<(ostream& o, const ast::Type& t);
	ostream& operator<<(ostream& o, const vector<ast::Term*> t);
	ostream& operator<<(ostream& o, const vector<ast::Variable*> v);
	ostream& operator<<(ostream& o, const vector<ast::Constant*> c);
	ostream& operator<<(ostream& o, const ast::Predicate& p);
	ostream& operator<<(ostream& o, const ast::Action& a);
	ostream& operator<<(ostream& o, const ast::AtomicFormulaTerm& p);
	ostream& operator<<(ostream& o, const ast::GD& gd);
	ostream& operator<<(ostream& o, const ast::PrefGD& prefGD);
	ostream& operator<<(ostream& o, const ast::PreGD& preGD);
	ostream& operator<<(ostream& o, const ast::Effect& effect);
	ostream& operator<<(ostream& o, const ast::PEffect& pEffect);
	ostream& operator<<(ostream& o, const ast::CEffect& cEffect);
	ostream& operator<<(ostream& o, const ast::Domain& d);
	ostream& operator<<(ostream& o, const ast::Literal& d);
	ostream& operator<<(ostream& o, const ast::InitElement& d);
	ostream& operator<<(ostream& o, const ast::Problem& d);
	ostream& operator<<(ostream& o, const ast::Instance& d);
	ostream& operator<<(ostream& o, const std::vector<ast::InitElement*> d);
};

namespace ast{
	// Contains the definition of all classes for the Abstract Syntax Tree of a PDDL 3.0 specification

	// Requirements (for now, only :strips and :typing are supported)
	const std::string STRIPS = ":strips";
	const std::string TYPING = ":typing";
		
	class Symbol{
		// Abstract class
		private:
			std::string name;
		protected:
			Symbol(const std::string& name);
		public:
			std::string getName() const;
	};
	
	class TypedSymbol: public Symbol{
		private:
			Type* type;
		protected:
			TypedSymbol(const std::string& name, Type* type);
		public:
			Type* getType() const;
	};
	
	class Type : public TypedSymbol{
		private:
			std::set<const Constant*> constants;
		public:
			Type(const std::string& name, Type* supertype = NULL);
			std::set<const Constant*> getConstants() const;
		friend class Constant; // To keep track of Type constants
	};
	
	class Term : public TypedSymbol{
		public:
			Term(const std::string& name, Type* type);
			virtual std::set<const Constant*> valuate() const = 0; // pure virtual function
	};
	
	class Constant : public Term{
		public:
			Constant(const std::string& name, Type* type);
			std::set<const Constant*> valuate() const;
	};
	
	class Variable : public Term{
		public:
			Variable(const std::string& name, Type* type);
			std::set<const Constant*> valuate() const;
	};

	
	class Predicate : public Symbol{
		private:
			std::vector<Variable*> arguments;
		public:
			Predicate(const std::string& name, const std::vector<Variable*>& arguments = *(new std::vector<Variable*>));
			std::vector<Variable*> getArguments() const;
			
			/* 
			 * Returns a vector of 0-ary predicates with name of the form: pred-name_c1_c2_..._cn
			 * Each ci corresponds to a valuation of predicate's i-th argument
			 * The obtained vector contains one such predicate per tuple, obtained by valuating all the arguments
			 */
			std::vector<Predicate*> valuate() const;

			
			/* 
			 * Returns a 0-ary predicate with name of the form: pred-name_c1_c2_..._cn
			 * Each ci corresponds to the substitution of the i-th p[redicate argument with the corresponding value provided by "valuations"
			 * If "valuations" is not appropriate (num of arguments and/or types) returns NULL
			 */
			const Predicate* valuate(std::vector<const Constant*> valuations, std::vector<const Predicate*> groundPredicates) const;
	};

	// The following classes follow the PDDL3.0 syntax. Possible redundancies may be present to allow future extensions (e.g., preferences)
	
	class AtomicFormulaTerm{
		private:
			const Predicate* predicate;
			std::vector<Term*> terms;
		public:
			AtomicFormulaTerm(const Predicate* predicate, std::vector<Term*> terms = *(new std::vector<Term*>()));
			const Predicate* getPredicate() const;
			std::vector<Term*> getTerms() const;

			Term* isTypeConsistent();	
			// Checks if terms types in "terms" match predicate types, PROVIDED terms is arity-consistent with predicate
			// If not, returns the first element that doesn't match
			// otherwise, returns NULL
			
			bool isArityConsistent();	
			// Checks if number of terms matches the predicate arity
			// If so, returns true; otherwise, returns false
			
			AtomicFormulaTerm* valuate(std::map<const ast::Variable*, const ast::Constant*> valuations, std::vector<const Predicate*> groundPredicates) const;
			/* Returns the AtomicFormulaTerm (arranged in a vector) obtained by replacing each occurrence of a variable in "terms"
			 * with a corresponding constant, where the correspondence in established by the function argument "valuations"
			 * returns null if valuations is not appropriate (i.e., num of arguments and/or types are not consistent)
			 */
			
			
	};
	
	class Literal{
		private:
			bool negated;
			AtomicFormulaTerm* atomicFormulaTerm;
		public:
			Literal(AtomicFormulaTerm* atomicFormulaTerm, bool negated = false);
			bool isNegated() const;
			AtomicFormulaTerm* getAtomicFormulaTerm() const;
			Literal* valuate(std::map<const Variable*, const Constant*> valuations, std::vector<const Predicate*> groundPredicates) const;
	};
	
	class GD{
		private:
            Literal* atom;
			std::vector<GD*> conjuncts;
		public:
			GD(Literal* atom);
			GD(std::vector<GD*> conjuncts);
			Literal* getAtom() const;
			std::vector<GD*> getConjuncts() const;
			
			/* Returns the goal obtained by replacing each arguments with a corresponding constant, according to the correspondences in "valuations"
			 * returns null if valuations is not appropriate (i.e., num of arguments and/or types are not consistent)
			 */
			GD* valuate(std::map<const Variable*, const Constant*> valuations, std::vector<const Predicate*> groundPredicates) const;
	};
	
	/* ========================= */ 
	// Not used (for preferences)
	class PrefGD{
		private:
			GD* gd;
		public:
			PrefGD(GD* gd);
			GD* getGd() const;
	};
	
	class PreGD{
		private:
			PrefGD* prefGD;
			std::set<PreGD*> conjuncts;
		public:
			PreGD(PrefGD* prefGD);
			PreGD(const std::set<PreGD*> conjuncts);
			PrefGD* getPrefGD() const;
			std::set<PreGD*> getConjuncts() const;
	};
	/* ========================= */ 
	
	
	class Effect{
		private:
			CEffect* cEffect;
			std::vector<CEffect*> conjuncts;
		public:
			Effect(CEffect* cEffect);
			Effect(std::vector<CEffect*> conjuncts);
			CEffect* getCEffect() const;
			std::vector<CEffect*> getConjuncts() const;
			const Effect* valuate(std::map<const Variable*, const Constant*> valuations, std::vector<const Predicate*> groundPredicates) const;
			std::set<const Predicate* > occurringPredicates() const;
			std::set<const Literal*> affectingLiterals(const Predicate* p) const;
	};
	
	class CEffect{
		private:
			PEffect* pEffect;
		public:
			CEffect(PEffect* pEffect);
			PEffect* getPEffect() const;			
			CEffect* valuate(std::map<const Variable*, const Constant*> valuations, std::vector<const Predicate*> groundPredicates) const;
			const Predicate* occurringPredicate() const; // returns the set of predicates occurring in the effect
			std::set<const Literal*> affectingLiterals(const Predicate* p) const;// returns the set of effect literals affecting p
	};
	
	class PEffect{
		private:
			Literal* literal;
		public:
			PEffect(Literal* literal);
			Literal* getLiteral() const;
			PEffect* valuate(std::map<const Variable*, const Constant*> valuations, std::vector<const Predicate*> groundPredicates) const;
			const Predicate* occurringPredicate() const; // returns the set of predicates occurring in the effect
	};
	
	class Action : public Symbol{
		private:
			std::vector<Variable*> parameters;
			GD* precondition;
			const Effect* effect;
		public:
			Action(const std::string& name, const std::vector<Variable*>& parameters, GD* precondition, const Effect* effect);
			std::vector<Variable*> getParameters() const;
			GD* getPrecondition() const;
			const Effect* getEffect() const;
			std::vector<Action*> valuate(std::vector<const Predicate*> groundPredicates) const;
			std::set<const Predicate* > affectedPredicates() const;
			std::set<const Literal*> affectingLiterals(const Predicate* p) const;// returns the set of effect literals affecting p (in current action)
	};
	
	class Domain : public Symbol{
		private: 
			std::vector<std::string> requirements;
			std::vector<Type*> types;
			std::vector<Constant*> constants;
			std::vector<const Predicate*> predicates;
			std::vector<const Action*> actions;
			
		public:
			Domain();
			Domain(const std::string& name, 
					const std::vector<std::string>& requirements, 
					const std::vector<Type*>& types, 
					const std::vector<Constant*>& constants, 
					const std::vector<const Predicate*>& predicates, 
					const std::vector<const Action*>& actions);
			
			std::vector<std::string> getRequirements() const;
			std::vector<Type*> getTypes() const;		
			std::vector<Constant*> getConstants() const;
			std::vector<const Predicate*> getPredicates() const;
			std::vector<const Action*> getActions() const;
			Domain* valuate() const;
	};
	
	
	class TypedStringList{
		private:
			std::vector<std::string> strings;
			std::string* typeString;
		public:
			TypedStringList(const std::vector<std::string>& strings, std::string* type = NULL);
			std::vector<std::string> getStrings() const;
			std::string* getTypeString() const;
	};
	
	class InitElement{
		private:
			Literal* literal;
		public:
			InitElement(Literal* literal);
			Literal* getLiteral() const;
	};
	
	class Problem : public Symbol{
		private:
			Domain* domain;
			std::vector<std::string> requirements;
			std::vector<Constant*> objects;
			std::vector<InitElement*> init;
			GD* goal;
		public:			
			Problem(const std::string& name, Domain* domain, std::vector<std::string> requirements, std::vector<Constant*> objects, std::vector<InitElement*> init, GD* goal);
			Domain* getDomain() const;
			std::vector<std::string> getRequirements() const;
			std::vector<Constant*> getObjects() const;
			std::vector<InitElement*> getInit() const;
			GD* getGoal() const;
	};
	
	class Instance{
		private:
			Domain* domain;
			Problem* problem;
		public:
			Instance();
			Instance(Domain* domain, Problem* problem);
			Domain* getDomain() const;
			Problem* getProblem() const;
	};
	
	// Auxiliary functions
	
	// Given a vector of term, returns all possible tuples (arranged in a vector) obtained by all possible valuations (according to types) of the terms.  
	std::vector<std::vector<const Constant*> > valuate(std::vector<Term*> terms);

	// Given a vector of variable, returns all possible tuples (arranged in a vector) obtained by all possible valuations (according to types) of the variables.  
	std::vector<std::vector<const Constant*> > valuate(std::vector<Variable*> vars);		
};// EOF namespace

#endif /*AST_H_*/
