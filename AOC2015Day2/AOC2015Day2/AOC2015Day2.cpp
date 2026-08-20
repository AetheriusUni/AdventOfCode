#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>


int getSurfaceAreaPlusSmallestArea(int l, int w, int h)
{
	int surfaceAreaOfPresent;
	int lwArea = l * w;
	int whArea = w * h;
	int lhArea = l * h;
	int smallestArea = 0;

	surfaceAreaOfPresent = 2 * lwArea + 2 * whArea + 2 * lhArea;

	if (lwArea <= whArea && lwArea <= lhArea)
	{
		smallestArea = lwArea;
	}
	else if (whArea <= lwArea && whArea <= lhArea)
	{
		smallestArea = whArea;
	}
	else
	{
		smallestArea = lhArea;
	}

	return surfaceAreaOfPresent + smallestArea;
}

int getTotalWrappingPaperNeeded (std::vector<std::string> allPresentDimensions)
{
	int wrappingPaperNeeded = 0;
	int l = 0;
	int w = 0;
	int h = 0;
	char delimiter = 'x';

	
	for (int i = 0; i < allPresentDimensions.size(); i++)
	{
		// parse strings into dimensions
		std::stringstream stringStream(allPresentDimensions[i]);
		std::vector<int> dimensions;
		std::string token;

		while (std::getline(stringStream, token, delimiter))
		{
			dimensions.push_back(std::stoi(token));
		}

		// get dimensions
		l = dimensions[0];
		w = dimensions[1];
		h = dimensions[2];

		// get surface area of present + smallest area
		int currentPresentWrappingNeeded = getSurfaceAreaPlusSmallestArea(l, w, h);
		// add to final area required
		wrappingPaperNeeded += currentPresentWrappingNeeded;
	}

	return wrappingPaperNeeded;
}

int main()
{
	std::ifstream file("AOC2015Day2Input.txt");

	if (!file.is_open())
	{
		std::cout << "Error opening file" << std::endl;
	}

	std::string line;
	std::vector<std::string> allPresentDimensions;

	while (std::getline(file, line))
	{
		allPresentDimensions.push_back(line);
	}

	int wrappingPaperNeeded = getTotalWrappingPaperNeeded(allPresentDimensions);

	// returns 1588178
	std::cout << "We need this much square feet of wrapping paper: " << wrappingPaperNeeded << std::endl;

	return 0;
}

/*
--- Day 2: I Was Told There Would Be No Math ---
The elves are running low on wrapping paper, and so they need to submit an order for more. They have a list of the dimensions (length l, width w, and height h) of each present, and only want to order exactly as much as they need.

Fortunately, every present is a box (a perfect right rectangular prism), which makes calculating the required wrapping paper for each gift a little easier: find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l. 
The elves also need a little extra paper for each present: the area of the smallest side.

For example:

A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet of wrapping paper plus 6 square feet of slack, for a total of 58 square feet.
A present with dimensions 1x1x10 requires 2*1 + 2*10 + 2*10 = 42 square feet of wrapping paper plus 1 square foot of slack, for a total of 43 square feet.
All numbers in the elves' list are in feet. How many total square feet of wrapping paper should they order?
*/