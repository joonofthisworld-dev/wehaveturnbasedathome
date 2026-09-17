#pragma once

#include <iostream>
#include "Random.h"

using std::cout;
using std::cin;
using std::string;

const int mapsize = 10;

string Map[mapsize][mapsize];

string AvaliableRooms[5] = {"Empty, Enemy, Rest, Shop, Boss"};

string RandomRoom()
{
	string room;

	int AvailableRoom = random(1, sizeof(AvaliableRooms));

	switch (AvailableRoom)
	{
	case 1: 
		room = "Empty";
		break;

	case 2:
		room = "Enemy";
		break;
	case 3:
		room = "Rest";
		break;
	case 4:
		room = "Shop";
		break;

	default:
		room = "Empty";
		break;
	}

	return room;
}

void Generatemap()
{
	for (int i = 0; i < mapsize; ++i)
	{
		for (int j = 0; j < mapsize; ++j)
		{
			Map[i][j] = RandomRoom();

			cout << Map[i][j] << endl;
		}
	}
}
