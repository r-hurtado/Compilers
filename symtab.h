#pragma once
//********************************************************
// symtab.h - Define a class for SymTab
//
// Author: Russ Hurtado
// Date:   Jan. 26, 2017
//
#include <unordered_map>
#include "cSymbol.h"

using std::unordered_map;

class SymTab
{
    public:
        // Construct a symbol given its name
        SymTab()
        {
            m_table;
        }

        void IncreaseScope();
		void DecreaseScope();
		void Insert(cSymbol*);
		bool Lookup(string);

    protected:
        unordered_map<string, cSymbol*> m_table;
};
