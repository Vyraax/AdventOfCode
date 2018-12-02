#include "pch.h"

int d1p1()
{
	std::ifstream file("day1.txt");
	int sum = 0;

	for (std::string line; std::getline(file, line);)
		sum += std::stoi(line);

	return sum;
}

int d1p2()
{
	std::ifstream file("day1.txt");
	std::vector<int> lines;
	std::unordered_map<int, char> map;
	int found = 0, current = 0;

	for (std::string line; std::getline(file, line);)
		lines.push_back(std::stoi(line));

	while (found == 0) {
		for(auto line : lines) {
			current += line;

			if (map.find(current) != map.end()) {
				found = current;
				break;
			}

			map[current] = 0;
		}
	}

	return found;
}

int main()
{
	std::cout << "Advent of code 2018" << std::endl;
	std::cout << "===================" << std::endl;

	std::cout << "Day 1:" << std::endl;

	clock_t d1p1_start = clock();
	int d1p1_res = d1p1();
	clock_t d1p1_end = clock();
	std::cout << "\tPart 1: " << d1p1_res << " | Time: " << (double)(d1p1_end - d1p1_start) / CLOCKS_PER_SEC << std::endl;

	clock_t d1p2_start = clock();
	int d1p2_res = d1p2();
	clock_t d1p2_end = clock();
	std::cout << "\tPart 2: " << d1p2_res << " | Time: " << (double)(d1p2_end - d1p2_start) / CLOCKS_PER_SEC << std::endl;
}
