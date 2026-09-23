#pragma once

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <cctype>

std::string store;

class StringUtility
{
public:

	static std::string ReadFromConsole()
	{
		std::cin >> store;
	};

	static void WriteToConsole(const std::string& Str)
	{
		std::cout << Str << std::endl;
	};

	static bool EqualTo(const std::string& a, const std::string& b)
	{
		if (a == b)
		{
			return true;
		}
		else 
		{
			return false;
		}
	};

	static std::string Tolower(std::string& str)
	{	
		for (char& c : str)
		{
			c = static_cast<char>(std::tolower(c));
		}

		return str;
	}

	static size_t Length(const std::string& a)
	{
		return a.length();
	};

	static void Append(const std::string& A, const std::string B)
	{
		std::cout << A + B << std::endl;
	};

private:

	
};

