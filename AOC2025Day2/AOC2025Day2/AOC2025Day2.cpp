#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> parseCommaSeparatedString(std::string inputString)
{
	std::vector<std::string> parsedStringVector;

	std::stringstream stringStream(inputString);
	std::string line;

	while (std::getline(stringStream, line, ','))
	{
		parsedStringVector.push_back(line);
	}

	return parsedStringVector;
}

std::vector<std::vector<double>> parseDashSeparatedString(std::string inputString)
{
	std::vector<std::vector<double>> parsedStringVector;

	std::stringstream stringStream(inputString);
	std::string line;

	while (std::getline(stringStream, line, '-'))
	{
		double stringToDouble = std::stod(line);
		double lengthOfString = line.size();
		parsedStringVector.push_back({ stringToDouble, lengthOfString });
	}

	return parsedStringVector;
}

double getSumInvalidIDsInRange(double startRange, double endRange, int lengthOfStart, int lengthOfEnd)
{
	// Since the young Elf was just doing silly patterns, you can find the invalid IDs by looking for any ID which is made only of some sequence of digits repeated twice. 
	// So, 55 (5 twice), 6464 (64 twice), and 123123 (123 twice) would all be invalid IDs.

	// idk how to do this optimially with the gigantic numbers we have...
	// maybe we check the lengths and if the length is lower than 2 or odd there's no invalid ID

	double sum = 0;


	if (lengthOfStart == lengthOfEnd && lengthOfStart % 2 != 0)
	{
		return sum;
	}

	std::string prevMatch;
	for (int i = startRange; i < endRange + 1; i++)
	{
		std::string numToString = std::to_string(i);
		int numToStringLength = numToString.size();
		if (numToStringLength % 2 == 0)
		{
			std::string firstPart = numToString.substr(0, numToStringLength / 2);
			std::string secondPart = numToString.substr(numToStringLength / 2, numToStringLength / 2);
			if (firstPart == secondPart && firstPart != prevMatch)
			{
				sum += i;
				prevMatch = firstPart;
			}
		}
	}

	return sum;
}

int getInvalidIDs(std::string inputString)
{
	int numInvalidIDs = 0;

	// parse the input into a vector of the ranges
	// The ranges are separated by commas (,)
	std::vector<std::string> rangeStrings = parseCommaSeparatedString(inputString);

	// evaluate each of the ranges for invalid IDs
	for (int i = 0; i < rangeStrings.size(); i++)
	{
		// each range gives its first ID and last ID separated by a dash (-)
		std::vector<std::vector<double>> singleRange = parseDashSeparatedString(rangeStrings[i]);
		double startRange = singleRange[0][0];
		double endRange = singleRange[1][0];
		int lengthOfStart = static_cast<int>(singleRange[0][1]);
		int lengthOfEnd = static_cast<int>(singleRange[1][1]);
		numInvalidIDs += getSumInvalidIDsInRange(startRange, endRange, lengthOfStart, lengthOfEnd);
	}

	return numInvalidIDs;
}

int main()
{
	std::ifstream file("AOC2025Day2Input.txt");
	//std::ifstream file("AOC2025Day2ExampleInput.txt");

	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return 1;
	}

	std::string line;
	std::string inputString;

	while (std::getline(file, line))
	{
		//std::cout << line << std::endl;
		inputString += line;
	}

	file.close();

	int numInvalidIDs = getInvalidIDs(inputString);

	std::cout << numInvalidIDs << std::endl;

	return 0;
}

/*
--- Day 2: Gift Shop ---
You get inside and take the elevator to its only other stop: the gift shop. "Thank you for visiting the North Pole!" gleefully exclaims a nearby sign. You aren't sure who is even allowed to visit the North Pole, but you know you can access the lobby through here, and from there you can access the rest of the North Pole base.

As you make your way through the surprisingly extensive selection, one of the clerks recognizes you and asks for your help.

As it turns out, one of the younger Elves was playing on a gift shop computer and managed to add a whole bunch of invalid product IDs to their gift shop database! Surely, it would be no trouble for you to identify the invalid product IDs for them, right?

They've even checked most of the product ID ranges already; they only have a few product ID ranges (your puzzle input) that you'll need to check. For example:

11-22,95-115,998-1012,1188511880-1188511890,222220-222224,
1698522-1698528,446443-446449,38593856-38593862,565653-565659,
824824821-824824827,2121212118-2121212124
(The ID ranges are wrapped here for legibility; in your input, they appear on a single long line.)

The ranges are separated by commas (,); each range gives its first ID and last ID separated by a dash (-).

Since the young Elf was just doing silly patterns, you can find the invalid IDs by looking for any ID which is made only of some sequence of digits repeated twice. So, 55 (5 twice), 6464 (64 twice), and 123123 (123 twice) would all be invalid IDs.

None of the numbers have leading zeroes; 0101 isn't an ID at all. (101 is a valid ID that you would ignore.)

Your job is to find all of the invalid IDs that appear in the given ranges. In the above example:

11-22 has two invalid IDs, 11 and 22.
95-115 has one invalid ID, 99.
998-1012 has one invalid ID, 1010.
1188511880-1188511890 has one invalid ID, 1188511885.
222220-222224 has one invalid ID, 222222.
1698522-1698528 contains no invalid IDs.
446443-446449 has one invalid ID, 446446.
38593856-38593862 has one invalid ID, 38593859.
The rest of the ranges contain no invalid IDs.
Adding up all the invalid IDs in this example produces 1227775554.

What do you get if you add up all of the invalid IDs?
*/