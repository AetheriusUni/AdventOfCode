#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

int countTimesDialSettlesOnZero(std::vector<std::string> rotations, int dialStart)
{
	int n = rotations.size();
	int currentValue = dialStart;
	int numSettledOnZero = 0;

	for (int i = 0; i < n; i++)
	{
		// get the part of the string that is a number and convert that to an int
		std::string stringToConvert;
		for (int j = 1; j < rotations[i].size(); j++)
		{
			stringToConvert += rotations[i][j];
		}
		int convertedString = std::stoi(stringToConvert);

		// if we rotate over 99 we must have passed zero
		if (convertedString > 99)
		{
			// make value we continue to process be the one between 0-99
			convertedString = convertedString % 100;
		}

		// get the first character which will always be R or L
		// if R we add to the currentValue
		// if L we subtract from the currentValue
		if (rotations[i][0] == 'R')
		{
			currentValue += convertedString;
		}
		else
		{
			currentValue -= convertedString;
		}


		// The safe has a dial with only an arrow on it; around the dial are the numbers 0 through 99 in order. 
		if (currentValue > 99)
		{
			currentValue = currentValue % 100;
		}
		else
		{
			currentValue = ( 100 + currentValue ) % 100;
		}

		// The actual password is the number of times the dial is left pointing at 0 after any rotation in the sequence.
		if (currentValue == 0)
		{
			numSettledOnZero++;
		}
	}

	return numSettledOnZero;
}

int main()
{
	/*
	The attached document (your puzzle input) contains a sequence of rotations, one per line, which tell you how to open the safe. 
	A rotation starts with an L or R which indicates whether the rotation should be to the left (toward lower numbers) or to the right (toward higher numbers). 
	Then, the rotation has a distance value which indicates how many clicks the dial should be rotated in that direction.
	*/

	// attempt to open file
	std::ifstream file("AOCDay12025Input.txt");
	//std::ifstream file("AOC2025Day1ExampleInput.txt");

	// if file didn't open properly return error
	if (!file.is_open()) 
	{
		std::cerr << "Error: Could not open the file." << std::endl;
		return 1;
	}

	std::string line;
	std::vector<std::string> rotations;

	// Loop through the file line by line
	while (std::getline(file, line)) 
	{
		// Process the line (e.g., print it to the screen)
		// the input is correct, no need to print for this problem
		// std::cout << line << std::endl;

		// add rotations to vector
		rotations.push_back(line);
	}

	// Close the file
	file.close();

	// The dial starts by pointing at 50.
	int start = 50;

	// The actual password is the number of times the dial is left pointing at 0 after any rotation in the sequence.
	int numZeros = countTimesDialSettlesOnZero(rotations, start);

	std::cout << "The actual password is: " << numZeros << std::endl;

	return 0;
}

/*

--- Day 1: Secret Entrance ---
// FLAVOR TEXT START
The Elves have good news and bad news.
The good news is that they've discovered project management! This has given them the tools they need to prevent their usual Christmas emergency. For example, they now know that the North Pole decorations need to be finished soon so that other critical tasks can start on time.
The bad news is that they've realized they have a different emergency: according to their resource planning, none of them have any time left to decorate the North Pole!
To save Christmas, the Elves need you to finish decorating the North Pole by December 12th.
Collect stars by solving puzzles. Two puzzles will be made available on each day; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!
// FLAVOR TEXT END

// PROBLEM START
You arrive at the secret entrance to the North Pole base ready to start decorating. Unfortunately, the password seems to have been changed, so you can't get in. 
A document taped to the wall helpfully explains:
"Due to new security protocols, the password is locked in the safe below. Please see the attached document for the new combination."

The safe has a dial with only an arrow on it; around the dial are the numbers 0 through 99 in order. 
As you turn the dial, it makes a small click noise as it reaches each number.

The attached document (your puzzle input) contains a sequence of rotations, one per line, which tell you how to open the safe. 
A rotation starts with an L or R which indicates whether the rotation should be to the left (toward lower numbers) or to the right (toward higher numbers). 
Then, the rotation has a distance value which indicates how many clicks the dial should be rotated in that direction.

So, if the dial were pointing at 11, a rotation of R8 would cause the dial to point at 19. After that, a rotation of L19 would cause it to point at 0.

Because the dial is a circle, turning the dial left from 0 one click makes it point at 99. Similarly, turning the dial right from 99 one click makes it point at 0.

So, if the dial were pointing at 5, a rotation of L10 would cause it to point at 95. After that, a rotation of R5 could cause it to point at 0.

The dial starts by pointing at 50.

You could follow the instructions, but your recent required official North Pole secret entrance security training seminar taught you that the safe is actually a decoy. 
The actual password is the number of times the dial is left pointing at 0 after any rotation in the sequence.

For example, suppose the attached document contained the following rotations:

L68
L30
R48
L5
R60
L55
L1
L99
R14
L82
Following these rotations would cause the dial to move as follows:

The dial starts by pointing at 50.
The dial is rotated L68 to point at 82.
The dial is rotated L30 to point at 52.
The dial is rotated R48 to point at 0.
The dial is rotated L5 to point at 95.
The dial is rotated R60 to point at 55.
The dial is rotated L55 to point at 0.
The dial is rotated L1 to point at 99.
The dial is rotated L99 to point at 0.
The dial is rotated R14 to point at 14.
The dial is rotated L82 to point at 32.
Because the dial points at 0 a total of three times during this process, the password in this example is 3.

Analyze the rotations in your attached document. What's the actual password to open the door?

To begin, get your puzzle input.

Answer: 1055
^the answer to my own puzzle input AOCDay12025Input
*/