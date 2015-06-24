#ifndef SYMTABLE_H_
#define SYMTABLE_H_

#include "ast.h"
#include <string>
#include <vector>
#include <map>

class SymTable{
	private:
		std::map<std::string,std::map<std::string, ast::Symbol*> > table;
		
	public:
		ast::Symbol* get(const std::string& name, const std::string& c) const;		
		bool add(ast::Symbol* s, const std::string& c);
		void clear();
};

#endif /*SYMTABLE_H_*/
