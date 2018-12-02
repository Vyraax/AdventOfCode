#include "pch.h"

std::string dayOne()
{
	std::string line;
	std::ifstream file("day1.txt");

	if (!file.is_open())
		return NULL;

	while (getline(file, line))
	{
		std::cout << line << '\n';
	}

	file.close();

	return "ok";
}

int main()
{
	std::cout << "Advent of code 2018" << std::endl;
	std::cout << "===================" << std::endl;
	std::cout << "Day 1: " << dayOne() << std::endl;
}
