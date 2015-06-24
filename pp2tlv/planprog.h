#ifndef PLANNINGPROGRAM_H_
#define PLANNINGPROGRAM_H_


#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "ast.h"



namespace pprog{
	class Transition;
	class Node;	
	class PlanningProgram;	
}

namespace std{
	// Must be re-define here, to avoid problems when mixing namespaces
	ostream& operator<<(ostream& o, const pprog::Node& n);
	ostream& operator<<(ostream& o, const pprog::Transition& t);
	ostream& operator<<(ostream& o, const pprog::PlanningProgram& p);
}

namespace pprog{
	
	class Node : public ast::Symbol {
		private:
			std::vector<Transition*> outgoingTransitions;
		public:
			Node(const std::string& id);
			std::vector<Transition*> getOutgoingTransitions() const;
		friend class Transition; // to set outgoing transitions
	};
	
	class Transition : public ast::Symbol{// Each transition is uniquely identified by its name 
		private:
			static int num_trans;
			Node* from;
			Node* to;
			ast::GD* goal;// literals of the goal to be achieved
			
		public:
			Transition(Node* from, Node* to, ast::GD* goal);
			Node* getTo() const;
			Node* getFrom() const;
			ast::GD* getGoal() const;
			Transition* valuate(std::vector<const ast::Predicate*> groundPredicates, std::map<Node*,Node*>& nodes) const;
			
		private:
			// Auxiliary functions
			std::string nextName() const;
	};
	
	class PlanningProgram : public ast::Symbol{
		private:
			ast::Domain* domain;
			std::vector<ast::Constant*> objects;
			Node* init_node;
			std::set<const Node*> nodes;						
			std::vector<ast::InitElement*> init_state;
			std::vector<Transition*> transitions;
		public:
			PlanningProgram();
			PlanningProgram(
					const std::string& name, 
					ast::Domain* domain, 
					const std::vector<ast::Constant*>& objects, 
					const std::vector<ast::InitElement*>& init_state,
					Node* init_node,
					std::vector<Transition*> transitions);
			
			ast::Domain* getDomain() const;
			std::vector<ast::Constant*> getObjects() const;
			Node* getInitNode() const;
			std::set<const Node*> getNodes() const;
			std::vector<ast::InitElement*> getInitState() const;
			std::vector<Transition*> getTransitions() const;
			PlanningProgram* valuate(std::vector<const ast::Predicate*>groundPredicates) const;
	};
}
#endif /*PLANNINGPROGRAM_H_*/
