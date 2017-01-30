#pragma once
//********************************************************
// symtab.h - Define a class for SymTab
//
// Author: Russ Hurtado
// Date:   Jan. 26, 2017
//
#include <unordered_map>
#include "cSymbol.h"
#include "lex.h"

using std::unordered_map;

class SymTab
{
    public:
        // Construct a symbol given its name
        //SymTab(){ }

        void IncreaseScope();
		void DecreaseScope();
		cSymbol* Insert(string);
		bool Lookup(string);
		virtual string ToString();

    protected:
        unordered_map<string, cSymbol*> m_table;
};
		
extern SymTab g_SymbolTable;
