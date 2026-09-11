#pragma once
#include <iostream>


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
	"Spell 5"
	"Psycilogical Warfare"
};

void FindSpells()
{
	for (int i = 0; i < 3; i++)
	{
		cout << spells[i] << endl;
	}

}