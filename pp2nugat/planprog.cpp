
#include "planprog.h"

using namespace std;

std::ostream& std::operator<<(std::ostream& o, const pprog::Node& n){
	o << (ast::Symbol) n;
	return o;
}

std::ostream& std::operator<<(std::ostream& o, const pprog::Transition& t){
	o << *t.getFrom() << "- "; 
	ast::GD* goal = t.getGoal(); 
	o << *goal;
	o << " ->" << *t.getTo();
	return o;
}


std::ostream& std::operator<<(std::ostream& o, const pprog::PlanningProgram& p){
	o << "(planprog " << p.getName() << endl;
	o << "\t(:domain " << p.getDomain() -> getName() << ")" << endl;
	o << "\t(:objects " << p.getObjects() << ")" << endl;
	o << "\t(:init " << p.getInitState() << ")" << endl;
	o << "\t(:initnode " << *p.getInitNode() << ")" << endl;
	o << "\t(:transitions " << endl;	
	std::vector<pprog::Transition*> transitions = p.getTransitions();
	for (unsigned int i = 0; i < transitions.size(); i++){
		o << "\t\t" << *transitions[i] << endl;
	}
	o << "\t)" << endl;	
	o << ")";
	return o;
}

using namespace std;
using namespace ast;
using namespace pprog;


/* Node */
Node::Node(const string& id) : Symbol(id){}

vector<Transition*> Node::getOutgoingTransitions() const{
	return outgoingTransitions;
}


/* Transition */
int Transition::num_trans = 0; // static member initialization

string Transition::nextName() const{
	ostringstream s_str;
	s_str << "trans_" << num_trans;
	num_trans++;
	return s_str.str();	
}


Transition::Transition(Node* from, Node* to, GD* goal) : Symbol(nextName()){
	from -> outgoingTransitions.push_back(this);
	this -> from = from;
	this -> to = to;
	this -> goal = goal;
}

Node* Transition::getTo() const{
	return to;
}

Node*  Transition::getFrom() const{
	return from;
}

GD* Transition::getGoal() const{
	return goal;
}

Transition* Transition::valuate(vector<const Predicate*> groundPredicates, map<Node*,Node*>& nodes) const{
	map<const Variable*,const Constant*> empty_map;// Pprog transitions are already ground, useless
	Node* new_from;
	Node* new_to;
	if (nodes.find(from) != nodes.end()){
		new_from = nodes[from];
	}
	else{
		new_from = new Node(from->getName());
		nodes[from] = new_from;
	}
	if (nodes.find(to) != nodes.end()){
		new_to = nodes[to];
	}
	else{
		new_to = new Node(to->getName());
		nodes[to] = new_to;
	}
	
	return new Transition(new_from, new_to, goal->valuate(empty_map,groundPredicates));
}





/* PlanningProgram */

PlanningProgram::PlanningProgram(
		const std::string& name, 
		ast::Domain* domain, 
		const std::vector<ast::Constant*>& objects, 
		const std::vector<ast::InitElement*>& init_state, 
		Node* init_node, 
		std::vector<Transition*> transitions) : Symbol(name) {
	this -> domain = domain;
	this -> objects = objects;
	this -> init_node = init_node;
	this -> init_state = init_state;
	this -> transitions = transitions;
	
	// Quick reference to all nodes
	nodes.insert(init_node);
	for (unsigned int i = 0; i < transitions.size(); i++){
		nodes.insert(transitions[i]->getFrom());
		nodes.insert(transitions[i]->getTo());
	}
}
		
PlanningProgram::PlanningProgram() : Symbol(""){
	this -> domain = NULL;
	this -> init_node = NULL;
}

Domain* PlanningProgram::getDomain() const{
	return domain;
}

vector<Constant*> PlanningProgram::getObjects() const{
	return objects	;
}


Node* PlanningProgram::getInitNode() const{
	return init_node;
}

set<const Node*> PlanningProgram::getNodes() const{
	return nodes;
}


std::vector<ast::InitElement*> PlanningProgram::getInitState() const{
	return init_state;
}

vector<Transition*> PlanningProgram::getTransitions() const{
	return transitions;
}

PlanningProgram* PlanningProgram::valuate(vector<const Predicate*> groundPredicates) const{
	vector<Transition*> grnd_transitions;
	map<Node*,Node*> node_correspondences;// function Transition::valuate has side effect
	for (unsigned int i = 0; i < transitions.size(); i++){
		grnd_transitions.push_back(transitions[i]->valuate(groundPredicates,node_correspondences));
	}
	
	
	Node* init_grnd_node;	
	for (unsigned int i = 0; i < grnd_transitions.size(); i++){
		if (grnd_transitions[i]->getFrom()->getName() == init_node -> getName()){
			init_grnd_node = grnd_transitions[i]->getFrom();
		}
	}
	
	map<const Variable*,const Constant*> empty_map;
	vector<InitElement*> grnd_init_state;
	for (unsigned int i = 0; i < init_state.size(); i++){
			grnd_init_state.push_back(new InitElement(init_state[i]->getLiteral()->valuate(empty_map,groundPredicates)));
	}
		
	return new PlanningProgram("grnd_"+getName(),domain,objects,grnd_init_state,init_grnd_node,grnd_transitions);
}




