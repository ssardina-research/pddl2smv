#ifndef PLANNING2SMV_H_
#define PLANNING2SMV_H_

#include <iostream>
#include <string>

#include "ast.h"

/* This class realizes a functional module 
 * which takes a domain and an ltl goal as input and 
 * outputs the translation of the problem into the SMV format, to be solved by NuSMV
 */

class Planning2SMV{
	public:
		static std::ostream& toSMV(std::ostream& o, const ast::Domain* d, const ast::Problem* p);
		
	private:
		// Auxiliary Functions
		static std::string ind(unsigned int i = 1);
		static void outputHeader(std::ostream& o);
		static void outputMain(std::ostream& o);
		static void outputSystem(const ast::Domain* d, std::ostream& o);
		static void outputEnvironment(const ast::Domain* d, const ast::Problem* p, std::ostream& o);
		static void outputActionList(const ast::Domain* d, std::ostream& o, unsigned int indt);
		static void outputFluents(const ast::Domain* d, std::ostream& o, unsigned int indt);
		static void outputPreconditions(const ast::Domain* d, std::ostream& o, unsigned int indt);
		static void outputGDFormula(const ast::GD* gd, std::ostream& o, unsigned int indt, std::string scope = "");
		static void outputEnvironmentInit(const ast::Domain* d, std::ostream& o, unsigned int indt);
		static void outputEnvironmentActions(const ast::Domain* d, const ast::Problem* p, std::ostream& o, unsigned int indt);
		static void outputGoal(const ast::LTLNode* g, std::ostream& o);
		
		/*
		 * Returns a map
		 * associating each predicate p of d with the actions affecting p
		 */
		static std::map<const ast::Predicate*,std::set<const ast::Action*> > predicateDependencies(const ast::Domain* d);
		
		/* Returns the set of InitElement affecting predicate pred */
		static std::set<const ast::InitElement*> affectedBy(std::vector<ast::InitElement*> inits, const ast::Predicate* pred);
		
		
};

#endif /*PLANNING2SMV_H_*/
