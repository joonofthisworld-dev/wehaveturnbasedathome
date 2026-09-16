#pragma once

#include <fstream>
#include <iostream>


std::ofstream GameLog;
std::ifstream HighScore;


void writeToFile(std::string text)
{
	std::ofstream logFile("GameLog.txt");
	if (logFile.is_open())
	{
		logFile << text << std::endl;

		logFile.close();

		std::cout << "File written successfully" << std::endl;
	}
	else
	{
		std::cout << "Error: Could not create file!" << std::endl;

	}
}



void appendToLog(std::string file ,std::string text)
{
	std::ofstream logFile(file, std::ios::app);

	if (logFile.is_open())
	{
		logFile << text << std::endl;

		logFile.close();
	}
}