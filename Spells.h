#pragma once
#include <iostream>


using std::string;
using std::cout;
using std::cin;
using std::endl;


//Spells
string spells[3] =
{
	"Firebolt",
	"Heal",
	"SelfDestruct",
};

void FindSpells()
{
	for (int i = 0; i < 3; i++)
	{
		cout << spells[i] << endl;
	}

}