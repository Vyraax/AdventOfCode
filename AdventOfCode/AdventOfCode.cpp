#include "pch.h"

int dayOne()
{
	std::string line;
	std::ifstream file("day1.txt");

	if (!file.is_open())
		return NULL;

	int current = 0;

	while (getline(file, line))
	{
		int n = std::stoi(line);
		current += n;
	}

	file.close();
	return current;
}

int main()
{
	std::cout << "Advent of code 2018" << std::endl;
	std::cout << "===================" << std::endl;
	std::cout << "Day 1: " << dayOne() << std::endl;
}
