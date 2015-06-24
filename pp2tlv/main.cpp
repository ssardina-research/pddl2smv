#include "grammar.tab.hh"
#include "planprog2tlv.h"

using namespace std;
using namespace yy;
using namespace ast;
	

int main(int argc, char* argv[]){
	Domain domain;
	PlanningProgram planning_program;
	
	// Create the parser
	Pddl30Parser parser(domain, planning_program);

	// Parse the input
	int parsingOk = parser.parse();
	if (parsingOk == 0){
		Domain* valuated_domain = domain.valuate();
		PlanningProgram* valuated_pprog = planning_program.valuate(valuated_domain -> getPredicates());
		PlanProg2TLV::toTLV(cout, valuated_domain, valuated_pprog);
	}
}
