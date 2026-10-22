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

int getOnePresentHousesViaSantaOrRoboSanta(std::string santaSteps)
{
	int numHousesVisitedAtLeastOnce = 0;
	std::set<std::pair<int, int>> housesVisitedAtLeastOnce;

	int xSanta = 0;
	int ySanta = 0;
	int xRoboSanta = 0;
	int yRoboSanta = 0;

	housesVisitedAtLeastOnce.insert({ xSanta, ySanta });

	for (int i = 0; i < santaSteps.size(); i++)
	{
		// Santa Movement
		if (i % 2 == 0)
		{
			// right
			if (santaSteps[i] == '>')
			{
				xSanta++;
			}
			// left
			else if (santaSteps[i] == '<')
			{
				xSanta--;
			}
			// up
			else if (santaSteps[i] == '^')
			{
				ySanta++;
			}
			// down
			else
			{
				ySanta--;
			}
			housesVisitedAtLeastOnce.insert({ xSanta, ySanta });
		}
		// Robo Santa Movement
		else
		{
			// right
			if (santaSteps[i] == '>')
			{
				xRoboSanta++;
			}
			// left
			else if (santaSteps[i] == '<')
			{
				xRoboSanta--;
			}
			// up
			else if (santaSteps[i] == '^')
			{
				yRoboSanta++;
			}
			// down
			else
			{
				yRoboSanta--;
			}
			housesVisitedAtLeastOnce.insert({ xRoboSanta, yRoboSanta });
		}
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
	int numHousesViaSantaAndRoboSanta = getOnePresentHousesViaSantaOrRoboSanta(santaSteps);

	// Number of houses visited at least once via Santa: 2592
	// Number of houses visited at least once via Santa and Robo Santa : 2360
	std::cout << "Number of houses visited at least once via Santa: " << numHousesWithAtLeastOnePresent << std::endl;
	std::cout << "Number of houses visited at least once via Santa and Robo Santa: " << numHousesViaSantaAndRoboSanta << std::endl;

	return 0;
}

/*
--- Day 3: Perfectly Spherical Houses in a Vacuum ---
Santa is delivering presents to an infinite two-dimensional grid of houses.

He begins by delivering a present to the house at his starting location, and then an elf at the North Pole calls him via radio and tells him where to move next. Moves are always exactly one house to the north (^), south (v), east (>), or west (<). After each move, he delivers another present to the house at his new location.

However, the elf back at the north pole has had a little too much eggnog, and so his directions are a little off, and Santa ends up visiting some houses more than once. How many houses receive at least one present?

For example:

> delivers presents to 2 houses: one at the starting location, and one to the east.
^>v< delivers presents to 4 houses in a square, including twice to the house at his starting/ending location.
^v^v^v^v^v delivers a bunch of presents to some very lucky children at only 2 houses.
Your puzzle answer was 2592.

The first half of this puzzle is complete! It provides one gold star: *

--- Part Two ---
The next year, to speed up the process, Santa creates a robot version of himself, Robo-Santa, to deliver presents with him.

Santa and Robo-Santa start at the same location (delivering two presents to the same starting house), then take turns moving based on instructions from the elf, who is eggnoggedly reading from the same script as the previous year.

This year, how many houses receive at least one present?

For example:

^v delivers presents to 3 houses, because Santa goes north, and then Robo-Santa goes south.
^>v< now delivers presents to 3 houses, and Santa and Robo-Santa end up back where they started.
^v^v^v^v^v now delivers presents to 11 houses, with Santa going one direction and Robo-Santa going the other.
*/