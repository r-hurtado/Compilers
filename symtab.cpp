#include "symtab.h"

void SymTab::IncreaseScope()
{
	
}

void SymTab::DecreaseScope()
{
	
}

void SymTab::Insert(cSymbol* s)
{
	m_table.insert({s.GetName(), s});
}

//returns true if s is found.
bool SymTab::Lookup(string s)
{
	unordered_map<string, cSymbol*>::iterator it;
	it = m_table.find(s);
	
	return it != m_table.end();
}
