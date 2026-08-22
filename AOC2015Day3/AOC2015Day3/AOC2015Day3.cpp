#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <utility>

int getNumHousesVisitedAtLeastOnce(std::string santaSteps)
{
	int numHousesVisitedAtLeastOnce = 0;
	std::set<std::pair<int, int>> housesVisitedAtLeastOnce;

	int x = 0;
	int y = 0;

	housesVisitedAtLeastOnce.insert({ x, y });

	for (int i = 0; i < santaSteps.size(); i++)
	{
		// right
		if (santaSteps[i] == '>')
		{
			x++;
		}
		// left
		else if (santaSteps[i] == '<')
		{
			x--;
		}
		// up
		else if (santaSteps[i] == '^')
		{
			y++;
		}
		// down
		else
		{
			y--;
		}
		housesVisitedAtLeastOnce.insert({ x, y });
	}

	numHousesVisitedAtLeastOnce = static_cast<int>(housesVisitedAtLeastOnce.size());

	return numHousesVisitedAtLeastOnce;
}

int main()
{
	std::ifstream inputFile("AOC2015Day3Input.txt");
	std::string line;

	if (!inputFile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
	}

	std::string santaSteps;

	while (std::getline(inputFile, line))
	{
		santaSteps += line;
	}

	int numHousesWithAtLeastOnePresent = getNumHousesVisitedAtLeastOnce(santaSteps);

	std::cout << "Number of houses visited at least once: " << numHousesWithAtLeastOnePresent << std::endl;

	return 0;
}