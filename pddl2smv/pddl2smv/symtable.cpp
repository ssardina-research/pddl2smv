#include "symtable.h"

using namespace ast;
using namespace std;


Symbol* SymTable::get(const string& name, const string& c) const{
	if (table.count(name) == 0){
		return NULL;
	}
	map<string,map<string, Symbol*> >::const_iterator it = table.find(name);
	if (it -> second.count(c) == 0){
		return NULL;
	}
	map<string, Symbol*>::const_iterator it2 = it -> second.find (c);
	return it2 -> second;
}

bool SymTable::add(ast::Symbol* s, const string& c){
	string name = s -> getName();
	if (get(name,c) != NULL){
		// Symbol already present in class
		return false;
	}
	// The symbol is not present, can be safely added
	table[name][c] = s;	
	return true;
}

void SymTable::clear(){
	table.clear();
}