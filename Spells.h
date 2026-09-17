#pragma once
#include <iostream>
#include <array>


using std::string;
using std::cout;
using std::cin;
using std::endl;


//Spells
string spells[6] =
{
	"Firebolt",
	"Heal",
	"SelfDestruct",
	"Eradicate",
	"Spell 5",
	"Psycilogical Warfare"
};

void FindSpells()
{
	for (int i = 0; i < std::size(spells); ++i)
	{
		cout << spells[i] << endl;
	}

}