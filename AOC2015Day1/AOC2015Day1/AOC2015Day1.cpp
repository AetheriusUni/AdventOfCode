#include <iostream>
#include <fstream>
#include <string>
#include <queue>

int santaTraversal(int startFloor, std::string santaSteps)
{
	int currentFloor = startFloor;

	// need to process inputs in FIFO so we use a queue
	//std::queue<char> q;

	for (int i = 0; i < santaSteps.size(); i++)
	{
		// An opening parenthesis, (, means he should go up one floor
		if (santaSteps[i] == '(')
		{
			currentFloor++;
		}
		// a closing parenthesis, ), means he should go down one floor
		else
		{
			currentFloor--;
		}
	}

	return currentFloor;
}

int main()
{
	std::ifstream file("AOC2015Day1Input.txt");

	if (!file.is_open())
	{
		std::cout << "Error opening file" << std::endl;
	}

	std::string line;
	std::string santaSteps;

	while (std::getline(file, line))
	{
		santaSteps += line;
	}

	// He starts on the ground floor (floor 0)
	int startFloor = 0;
	
	// To what floor do the instructions take Santa?
	int finalFloor = santaTraversal(startFloor, santaSteps);

	// he ends up on floor 74
	std::cout << "Santa ends up on floor " << finalFloor << std::endl;
	
	return 0;
}

/*
--- Day 1: Not Quite Lisp ---
Santa was hoping for a white Christmas, but his weather machine's "snow" function is powered by stars, and he's fresh out! To save Christmas, he needs you to collect fifty stars by December 25th.

Collect stars by helping Santa solve puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

Here's an easy puzzle to warm you up.

Santa is trying to deliver presents in a large apartment building, but he can't find the right floor - the directions he got are a little confusing. He starts on the ground floor (floor 0) and then follows the instructions one character at a time.

An opening parenthesis, (, means he should go up one floor, and a closing parenthesis, ), means he should go down one floor.

The apartment building is very tall, and the basement is very deep; he will never find the top or bottom floors.

For example:

(()) and ()() both result in floor 0.
((( and (()(()( both result in floor 3.
))((((( also results in floor 3.
()) and ))( both result in floor -1 (the first basement level).
))) and )())()) both result in floor -3.
To what floor do the instructions take Santa?
*/