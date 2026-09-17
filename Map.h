#pragma once

#include <iostream>
#include <array> 
#include "Random.h"

using std::cout;
using std::cin;
using std::string;

const int mapsize = 10;

string Map[mapsize][mapsize];

string AvaliableRooms[5] = { "Empty", "Enemy", "Rest", "Shop", "Boss" };


string RandomRoom()
{
	string room;

	int AvailableRoom = random(0, 10);

	if (AvailableRoom < 5)
	{
		room = "Enemy";
	}
	else if (AvailableRoom < 7)
	{
		room = "Rest";
	}
	else if (AvailableRoom < 8)
	{
		room = "Shop";
	}
	else if (AvailableRoom < 9)
	{
		room = "Boss";
	}
	else
	{
		room = "Empty";
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

			//cout << Map[i][j] << endl;
		}
	}
}

int currentX = mapsize/2;
int currentY = mapsize/2;

string GetPosition(string map)
{
	cout << "You are current on " << "[" << currentX << "]" << "[" << currentY << "] " << endl;

	string Pos = Map[currentX][currentY];

	return Pos;
}

void Move(string Direction)
{
	if (Direction == "North" || "north")
	{
		currentY += 1;

	}
	else if (Direction == "South" || "east")
	{
		currentY -= 1;
	}
	else if (Direction == "East" || "east")
	{
		currentX += 1;
	}
	else if (Direction == "West" || "west")
	{
		currentX -= 1;
	}
}


