#ifndef PLANPROG2TLV_H_
#define PLANPROG2TLV_H_

#include <iostream>
#include <string>

#include "ast.h"
#include "planprog.h"

/* This class realizes a functional module that 
 * which takes a domain and a planning program as input and 
 * outputs the translation of the problem into a TLV format
 */

class PlanProg2TLV{
	public:
		static std::ostream& toTLV(std::ostream& o, const ast::Domain* d, const pprog::PlanningProgram* p);
		
	private:
		// Auxiliary Functions
		static std::string ind(unsigned int i = 1);
		static void outputHeader(std::ostream& o);
		static void outputMain(std::ostream& o);
		static void outputSystem(const ast::Domain* d, const pprog::PlanningProgram* p, std::ostream& o);
		static void outputEnvironment(const ast::Domain* d, const pprog::PlanningProgram* p, std::ostream& o);
		static void outputActionList(const ast::Domain* d, std::ostream& o, unsigned int indt);
		static void outputFluents(const ast::Domain* d, std::ostream& o, unsigned int indt);
		static void outputPreconditions(const ast::Domain* d, std::ostream& o, unsigned int indt);
		static void outputPlanningProgramRequirement(const pprog::PlanningProgram* p, std::ostream& o, unsigned int indt);
		static void outputGDFormula(const ast::GD* gd, std::ostream& o, unsigned int indt, std::string scope = "");
		static void outputPlanningProgramNodes(const pprog::PlanningProgram* p, std::ostream& o, unsigned int indt);
		static void outputPlanningProgramTransitions(const pprog::PlanningProgram* p, std::ostream& o, unsigned int indt);
		static void outputEnvironmentInit(const ast::Domain* d, const pprog::PlanningProgram* p, std::ostream& o, unsigned int indt);
		static void outputEnvironmentActions(const ast::Domain* d, const pprog::PlanningProgram* p, std::ostream& o, unsigned int indt);
		static void outputPlanningProgramConstraints(const ast::Domain* d, const pprog::PlanningProgram* p, std::ostream& o, unsigned int indt);
		
		/*
		 * Returns a map
		 * associating each predicate p of d with the actions affecting p
		 */
		static std::map<const ast::Predicate*,std::set<const ast::Action*> > predicateDependencies(const ast::Domain* d);
		
		/* Returns the set of InitElement affecting predicate pred */
		static std::set<const ast::InitElement*> affectedBy(std::vector<ast::InitElement*> inits, const ast::Predicate* pred);
		
		
};

#endif /*PLANPROG2TLV_H_*/
