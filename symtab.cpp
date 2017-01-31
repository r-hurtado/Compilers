#include "symtab.h"

void SymTab::IncreaseScope()
{
	unordered_map<string, cSymbol*> temp;
	m_maps.push_back(m_table);
	m_table = temp;
}

void SymTab::DecreaseScope()
{
	m_table = m_maps.back();
	m_maps.pop_back();
}

cSymbol* SymTab::Insert(string s)
{
	cSymbol* temp;
	if(!Lookup(s))
	{
		temp = new cSymbol(s);
		m_table.insert({s, temp});
	}
	else
	{
		unordered_map<string, cSymbol*>::iterator it;
		it = m_table.find(s);
		temp = it->second;
	}
	
	return temp;
}

//returns true if s is found.
bool SymTab::Lookup(string s)
{
	unordered_map<string, cSymbol*>::iterator it;
	it = m_table.find(s);
	
	return it != m_table.end();
}

//returns true if s is found.
bool SymTab::FullLookup(string s)
{
	list<unordered_map<string, cSymbol*>>::reverse_iterator stack_it;
	stack_it = m_maps.rbegin();
	
	unordered_map<string, cSymbol*>::iterator map_it;
	
	bool done = false;
	bool found = false;
	
	while(!done)
	{
		map_it = stack_it->find(s);
		
		if(map_it != stack_it->end())
		{
			done = true;
			found = true;
		}
		else if (stack_it != m_maps.rend())
		{
			stack_it++;
		}
		else
		{
			done = true;
		}
	}
	
	return found;
}
