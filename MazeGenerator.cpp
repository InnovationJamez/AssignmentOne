#include "MazeGenerator.h"

// set the valles

void MazeGenerator::setMazeWidth(int a)
{
	this->mazeWidth = a;
}

void MazeGenerator::setMazeHeight(int a)
{
	this->mazeHeight = a;
}

// get input for dimensions of maze

void MazeGenerator::takeVallues()
{
	int width, height;
	std::cout << "Enter Maze width then height and hit enter" << std::endl;
	std::cin >> width >> height;
	std::cout << "\nYou entered a height: " 
		<< height << " and width: " << width << std::endl;
	MazeGenerator::setMazeWidth(width);
	MazeGenerator::setMazeHeight(height);
}

// fill in the maze

void MazeGenerator::boardBuilder()
{
	for (int i = 0; i < this->mazeWidth; ++i)
	{
		std::vector<Cell>temp;
		for (int j = 0; j < this->mazeHeight; ++j)
		{
			Cell condition;
			temp.push_back(condition);
		}
		maze.push_back(temp);
	}
}

	// check position

bool MazeGenerator::checkNorth()
{
	bool answer;
	if (this->position.yPos == 0 || this->maze[this->position.xPos]
		[this->position.yPos-1].discovered == true)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}
	return answer;
}

bool MazeGenerator::checkSouth()
{
	bool answer;
	if (this->position.yPos == (this->mazeHeight-1) || this->maze[this->position.xPos]
		[this->position.yPos+1].discovered == true)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}
	return answer;
}

bool MazeGenerator::checkWest()
{
	bool answer;
	if (this->position.xPos == 0 || this->maze[this->position.xPos-1]
		[this->position.yPos].discovered == true)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}
	return answer;
}

bool MazeGenerator::checkEast()
{
	bool answer;
	if (this->position.xPos == (this->mazeHeight - 1) || this->maze[this->position.xPos+1]
		[this->position.yPos].discovered == true)
	{
		answer = true;
	}
	else
	{
		answer = false;
	}
	return answer;
}

	// Generates a random number

int MazeGenerator::randomNumber(int upperbound)
{
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(1, (upperbound - 1));
	int numPicked = distribution(generator);
	return numPicked;

}

	// place start

void MazeGenerator::placeStart()
{
	// find a random spot on the maze and set 
	// the coordinates to that point
	this->position.xPos == MazeGenerator::randomNumber(this->mazeWidth);
	this->position.yPos == MazeGenerator::randomNumber(this->mazeHeight);
}

	// during walk decine direction

void MazeGenerator::decideDirection()
{
	std::vector<int>tempVector;
	if (MazeGenerator::checkNorth()) {
		tempVector.push_back(1);
	}
	if (MazeGenerator::checkSouth()) {
		tempVector.push_back(2);
	}
	if (MazeGenerator::checkWest()) {
		tempVector.push_back(3);
	}
	if (MazeGenerator::checkEast()) {
		tempVector.push_back(4);
	}
	if (tempVector.size() == 0) {
		MazeGenerator::huntMode();
	}
	else {

	}
}

	// walk in direction

void MazeGenerator::walkNorth()
{
	maze[this->position.xPos][this->position.yPos].northConnection = true;
	maze[this->position.xPos][this->position.yPos-1].southConnection = true;
	this->position.yPos -= 1;
}

void MazeGenerator::walkSouth()
{
	maze[this->position.xPos][this->position.yPos+1].northConnection = true;
	maze[this->position.xPos][this->position.yPos].southConnection = true;
	this->position.yPos += 1;
}

void MazeGenerator::walkWest()
{
	maze[this->position.xPos][this->position.yPos].westConnection = true;
	maze[this->position.xPos][this->position.yPos-1].eastConnection = true;
	this->position.xPos -= 1;
}

void MazeGenerator::walkEast()
{
	maze[this->position.xPos][this->position.yPos].eastConnection = true;
	maze[this->position.xPos][this->position.yPos+1].westConnection = true;
	this->position.xPos += 1;
}

// hunt Mode 

void MazeGenerator::huntMode()
{

}

