#ifndef SYMTAB_H
#define SYMTAB_H
//********************************************************
// symtab.h - Define a class for SymTab
//
// Author: Russ Hurtado
// Date:   Jan. 26, 2017
//
#include <unordered_map>
#include <list>
#include "cSymbol.h"
#include "lex.h"

using std::unordered_map;
using std::list;

class SymTab
{
    public:
        // Construct a symbol given its name
        SymTab(){ m_maps(m_table); }

        void IncreaseScope();
		void DecreaseScope();
		cSymbol* Insert(string);
		bool Lookup(string);

    protected:
		list<unordered_map<string, cSymbol*>> m_maps;
        unordered_map<string, cSymbol*> m_table; 
};

#endif