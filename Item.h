#pragma once


#include <iostream>
#include "Hero.h"


class item
{
protected:

	std::string Name;
	int Value;


public:

	virtual void Use(Hero& player)
	{
		std::cout << "Used " << Name << std::endl;
	}

	item()
	{
		Name = "Unknown Item";
		Value = 0;
	}

	item(std::string name, int value)
	{
		Name = name;
		Value = value;
	}
};


class HealPotion : public item
{
public:

	HealPotion(std::string name, int value)
	{
		Name = name;
		Value = value;
	}

	void Use(Hero& player) override
	{
		if (Value > 0)
		{
			player.Heal(Value);
		}
		else
		{
			player.TakeDamage(Value);
		}
	}
};

class Poison : public item
{
public:

	Poison(std::string name, int value)
	{
		Name = name;
		Value = value;
	}

	void Use(Hero& player) override
	{

			player.TakeDamage(Value);

	}
};