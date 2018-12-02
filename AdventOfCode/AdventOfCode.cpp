#include "pch.h"

int d1p1()
{
	std::ifstream file("day1.txt");
	std::vector<int> lines;
	std::string line;

	while (std::getline(file, line))
		lines.push_back(std::stoi(line));

	return std::accumulate(lines.begin(), lines.end(), 0);
}

int d1p2()
{
	std::ifstream file("day1.txt");
	std::string line;
	std::vector<int> lines;
	std::map<int, bool> map;
	int found = 0;
	int current = 0;

	while (std::getline(file, line))
		lines.push_back(std::stoi(line));

	while (found == 0) {
		for(auto line : lines) {
			current += line;

			if (map.count(current) > 0) {
				found = current;
				break;
			}

			map[current] = true;
		}
	}

	return found;
}

int main()
{
	std::cout << "Advent of code 2018" << std::endl;
	std::cout << "===================" << std::endl;
	std::cout << "Day 1:" << std::endl;
	std::cout << "\tPart 1: " << d1p1() << std::endl;
	std::cout << "\tPart 2: " << d1p2() << std::endl;
}
