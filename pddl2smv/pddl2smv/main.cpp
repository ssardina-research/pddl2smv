#include "grammar.tab.hh"
#include "planning2smv.h"

using namespace std;
using namespace yy;
using namespace ast;
	

int main(int argc, char* argv[]){
	Domain* domain = new Domain();
	Problem* problem = new Problem();
	
	// Create the parser
	Pddl30Parser parser(*domain, *problem);

	// Parse the input (parse has side effect on parser constructor's arguments)
	int parsingOk = parser.parse();
	if (parsingOk == 0){
		Domain* valuated_domain = domain -> valuate();
		Problem* valuated_problem = problem -> valuate(valuated_domain->getPredicates());
		Planning2SMV::toSMV(cout, valuated_domain, valuated_problem);
	}
}
