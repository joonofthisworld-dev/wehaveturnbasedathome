#pragma once

#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::endl;

// Define Player/Class

enum Weapon
{
	Daggers,
	Sword,
	SwordBigger
};

class Hero {

private:

	string Name;

	Weapon weapon = Daggers;

	int
		// Level
		Level,

		// Stats
		Health,
		Endurance,
		Attack,
		Luck,
		Magic,
		Extra,

		// Attack

		Mana,
		MaxMana,
		Defense,
		MaxHealth;

	float
		CurrentHealth;


	bool CanRest = true;

	

public:

	bool Alive = true;

	string inventory[10]{"potion", "potion", "poison", "potion", "empty", "empty" ,"empty" ,"empty" ,"empty" ,"empty" };

	Hero() {
		Name = "Unkown";

		Level = 1;

		Health = 5;
		Endurance = 5;
		Attack = 5;
		Luck = 5;
		Magic = 5;
		Extra = 0;

		Mana = 100,
			MaxMana = 100,
			Defense = 5;
		MaxHealth = 100;
		CurrentHealth = 100;
	}

	void NameHero()
	{
		string name;

		cout << "Name your hero" << endl;

		cin >> name;

		Name = name;

		cout << "Ok, " << name << endl;
	}
	
	void TakeDamage(float damage)
	{
		CurrentHealth -= (damage * (Endurance * 0.2));

		if (CurrentHealth <= 0)
		{
			cout << "You died!" << endl;

			Alive = false;
		}


	}

	void ShowPlayerStats()
	{
		cout << endl;
		cout << "Level " << Level << endl;
		cout << endl;
		cout << "Health " << Health << endl;
		cout << "Endurance " << Endurance << endl;
		cout << "Attack " << Attack << endl;
		cout << "Luck " << Luck << endl;
		cout << "Magic " << Magic << endl;
		cout << "Extra " << Extra << endl;
		cout << endl;
		cout << "Mana " << Mana << endl;
		cout << "Health " << CurrentHealth << endl;
		cout << endl;

	}

	void DisplayBattle()
	{
		cout << endl;

		cout << Name << endl;

		cout << "Health: "<< CurrentHealth << endl;

		cout << "Mana: " << Mana << endl;
	}

	float GetDamage()
	{
		float attack = 0;

		switch ( weapon )
		{
		case Daggers:

			attack = ((Attack + Extra * .5)* .7) * 2;

			break;
		case Sword:

			attack = (Attack + Extra * .5);
			break;
		case SwordBigger:

			attack = (Attack + Extra * .5) * 2;

			break;
		}


		int outcome = random(1, 5);

		if (outcome == 1)
		{
			attack = 0;
		}

		return attack;
	}

	int GetDefense() { return Defense; }

	void Rest()
	{
		if (CanRest)
		{
			CurrentHealth = MaxHealth;
			Mana = MaxMana;
			CanRest = false;

			cout << endl;
			cout << "Rested" << endl;
		}
		else
		{
			cout << endl;
			cout << "Cant Rest!" << endl;
		}
	}

	void Heal(int ammount)
	{
		CurrentHealth += ammount;
		if ( CurrentHealth > MaxHealth)
		{
			CurrentHealth = MaxHealth;
		}

		cout << "Healed " << ammount << endl;
	}
	
	void ResetRest()
	{
		CanRest = true;
	}

	void ChooseWeapon()
	{
		int choice;
		cout << "Chose your weapon!" << endl;

		cout << "1. Daggers" << endl;
		cout << "2. Sword" << endl;
		cout << "3. Sword(Bigger)" << endl;

		cin >> choice;

		switch ( choice)
		{
		case 1:
			weapon = Daggers;
			break;
		case 2:
			weapon = Sword;
			break;
		case 3:
			weapon = SwordBigger;
			break;
		}
	}

	void Upgrade()
	{
		Level += 1;

		int points = random(1,3);

		int lvchoice;

		cout << "You have " << points << " points of upgrade. Where would you like to allocate ALL of them?" << endl;

		cout << "1. Health" << endl;
		cout << "2. Endurance" << endl;
		cout << "3. Attack" << endl;
		cout << "4. Luck" << endl;
		cout << "5. Magic" << endl;
		cout << "6. Extra" << endl;

		cin >> lvchoice;
		if (cin.fail())
		{
			cout << "use numbers";
			cin.clear();
			cin.ignore();

			Upgrade();
		}

		switch (lvchoice)
		{
		case 1:

			Health += points;
			MaxHealth += 20 * points;
			
			cout << "Leveled up Health" << endl;
			break;

		case 2:

			Endurance += points;
			cout << "Leveled up Endurance" << endl;
			break;

		case 3:
			Attack += points;
			cout << "Leveled up Attack" << endl;
			break;

		case 4:
			Luck += points;
			cout << "Leveled up Luck" << endl;
			break;
		
		case 5:
			Magic += points;
			MaxMana += 20 * points;
			cout << "Leveled up Magic" << endl;
			break;

		case 6:
			Extra += points;
			cout << "Leveled up Extra" << endl;
			break;

		default:

			cout << "error" << endl;
			break;
		}
	}

	void ManaChange(int change)
	{
		Mana += change;
	}

	void ViewInventory()
	{
		cout << endl;

		for (int i = 0; i < 10; ++i)
		{
			cout << i + 1 << ".  ";
			cout << inventory[i] << endl;

		}
	}

	string GetName() { return Name; }

	int GetLevel() { return Level; }



};