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
	int found = 0, sum = 0;

	for (std::string line; std::getline(file, line);)
		lines.push_back(std::stoi(line));

	while (!found) {
		for(const int& line : lines) {
			sum += line;

			if (map.find(sum) != map.end()) {
				found = sum;
				break;
			}

			map[sum] = 0;
		}
	}

	return found;
}

int d2p1()
{
	std::ifstream file("day2.txt");
	short c2 = 0, c3 = 0;

	for (std::string line; std::getline(file, line);)
	{
		std::unordered_map<char, int> count;
		bool two = false, three = false;

		for (char& c : line)
		{
			if (count.find(c) == count.end())
				count[c] = 0;
			count[c] += 1;
		}

		for (auto x : count)
		{
			if (x.second == 2) two = true;
			if (x.second == 3) three = true;
		}

		if (two) c2 += 1;
		if (three) c3 += 1;
	}

	return c2 * c3;
}

std::string d2p2()
{
	std::ifstream file("day2.txt");
	std::vector<std::string> lines;
	std::vector<char> result;
	std::string str;

	for (std::string line; std::getline(file, line);)
		lines.push_back(line);

	for (const auto& x : lines)
	{
		for (const auto& y : lines)
		{
			short diff = 0;
			for (unsigned int i = 0; i < x.size(); ++i)
				if (x[i] != y[i]) 
					diff++;

			if (diff == 1) 
			{
				for (unsigned int i = 0; i < x.size(); ++i)
					if (x[i] == y[i])
						result.push_back(x[i]);

				for (const auto& c : result)
					str += c;

				return str;
			}
		}
	}

	return str;
}


int d3p1()
{
	const std::size_t WIDTH = 1000;
	const std::size_t HEIGHT = 1000;
	static int grid[WIDTH][HEIGHT] = {{0}};
	std::ifstream file("day3.txt");
	std::regex rgx("#(\\d+)\\s\\@\\s(\\d+),(\\d+):\\s(\\d+)x(\\d+)");
	std::smatch match;

	for (std::string line; std::getline(file, line);)
	{
		const std::string str(line);

		if (std::regex_search(str.begin(), str.end(), match, rgx))
		{
			int id     = std::atoi(match[1].str().c_str());
			int left   = std::atoi(match[2].str().c_str());
			int top    = std::atoi(match[3].str().c_str());
			int width  = std::atoi(match[4].str().c_str());
			int height = std::atoi(match[5].str().c_str());

			for (int y = top; y < (top + height); ++y)
				for (int x = left; x < (left + width); ++x)
					grid[x][y] += 1;
		}
	}

	int area = 0;
	for (int y = 0; y < HEIGHT; ++y)
		for (int x = 0; x < WIDTH; ++x)
			if (grid[x][y] > 1)
				area += 1;

	return area;
}

int d3p2()
{
	const std::size_t WIDTH = 1000;
	const std::size_t HEIGHT = 1000;
	static int grid[WIDTH][HEIGHT] = {{0}};

	std::ifstream file("day3.txt");
	std::regex rgx("#(\\d+)\\s\\@\\s(\\d+),(\\d+):\\s(\\d+)x(\\d+)");
	std::smatch match;
	std::vector<int> ids;

	for (std::string line; std::getline(file, line);)
	{
		const std::string str(line);

		if (std::regex_search(str.begin(), str.end(), match, rgx))
		{
			int id     = std::atoi(match[1].str().c_str());
			int left   = std::atoi(match[2].str().c_str());
			int top    = std::atoi(match[3].str().c_str());
			int width  = std::atoi(match[4].str().c_str());
			int height = std::atoi(match[5].str().c_str());

			ids.push_back(id);

			for (int x = 0; x < width; ++x) 
			{
				for (int y = 0; y < height; ++y) 
				{
					int prev = grid[x + left][y + top];

					if (prev == 0)
						grid[x + left][y + top] = id;
					else 
					{
						ids.erase(std::remove(ids.begin(), ids.end(), id), ids.end());
						ids.erase(std::remove(ids.begin(), ids.end(), prev), ids.end());
					}
				}
			}
		}
	}

	return ids[0];
}

double getReport(clock_t end, clock_t start) {
	return (double)(end - start) / CLOCKS_PER_SEC;
}

int main()
{
	clock_t total_start = clock();
	std::cout << "Advent of code 2018" << std::endl << std::endl;

	std::cout << "Day 1:" << std::endl;
	std::cout << "======================================" << std::endl;

	clock_t d1p1_start = clock();
	int d1p1_res = d1p1();
	clock_t d1p1_end = clock();
	std::cout << "\tPart 1: " << d1p1_res << "\tTime: " << getReport(d1p1_end, d1p1_start) << " s" << std::endl;

	clock_t d1p2_start = clock();
	int d1p2_res = d1p2();
	clock_t d1p2_end = clock();
	std::cout << "\tPart 2: " << d1p2_res << "\tTime: " << getReport(d1p2_end, d1p2_start) << " s" << std::endl << std::endl;

	std::cout << "Day 2:" << std::endl;
	std::cout << "======================================" << std::endl;

	clock_t d2p1_start = clock();
	int d2p1_res = d2p1();
	clock_t d2p1_end = clock();
	std::cout << "\tPart 1: " << d2p1_res << "\tTime: " << getReport(d2p1_end, d2p1_start) << " s" << std::endl;

	clock_t d2p2_start = clock();
	std::string d2p2_res = d2p2();
	clock_t d2p2_end = clock();
	std::cout << "\tPart 2: " << d2p2_res << "\tTime: " << getReport(d2p2_end, d2p2_start) << " s" << std::endl << std::endl;

	std::cout << "Day 3:" << std::endl;
	std::cout << "======================================" << std::endl;

	clock_t d3p1_start = clock();
	int d3p1_res = d3p1();
	clock_t d3p1_end = clock();
	std::cout << "\tPart 1: " << d3p1_res << "\tTime: " << getReport(d3p1_end, d3p1_start) << " s" << std::endl;

	clock_t d3p2_start = clock();
	int d3p2_res = d3p2();
	clock_t d3p2_end = clock();
	std::cout << "\tPart 2: " << d3p2_res << "\tTime: " << getReport(d3p2_end, d3p2_start) << " s" << std::endl << std::endl;

	std::cout << "======================================" << std::endl;
	clock_t total_end = clock();
	std::cout << "Total execution time:\t" << getReport(total_end, total_start) << " s" << std::endl << std::endl;
	system("pause");

	return 0;
}
