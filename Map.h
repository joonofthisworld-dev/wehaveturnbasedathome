#pragma once

#include <iostream>
#include <array> 
#include "Random.h"

using std::cout;
using std::cin;
using std::string;

const int mapsize = 3;

string Map[mapsize][mapsize];

string AvaliableRooms[5] = { "Empty", "Enemy", "Rest", "Shop", "Boss" };

string RandomRoom()
{
	string room;

	int AvailableRoom = random(0, 100);

	cout << AvailableRoom << endl;

	switch (AvailableRoom)
	{
	case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:
		room = "Enemy";
		break;
	case 16:case 12:case 13:case 14:case 15:
		room = "Rest";
		break;
	case 21:case 17:case 18:case 19:case 20:
		room = "Shop";
		break;
	case 11:case 22:case 33:case 44:case 55:case 66:case 77:case 88: case 99:
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
			//Map[i][j] = RandomRoom();

			//cout << Map[i][j] << endl;

			cout << RandomRoom() << endl;
		}
	}
}
