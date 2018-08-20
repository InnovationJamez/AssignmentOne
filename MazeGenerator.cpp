#include "MazeGenerator.h"

	// set Position

void MazeGenerator::setPosition(int i, int j)
{
	this->position.xPos = i;
	this->position.yPos = j;
}

void MazeGenerator::setDimensions(int a, int b)
{
	this->mazeWidth = a;
	this->mazeHeight = a;
}

// get input for dimensions of maze

void MazeGenerator::takeVallues()
{
	int width, height;
	std::cout << "Enter Maze width then height and hit enter" << std::endl;
	std::cin >> width >> height;
	std::cout << "\nYou entered the height: " 
		<< height << " and width: " << width << std::endl;
	MazeGenerator::setDimensions(width, height);
}

	// fill in the maze

void MazeGenerator::boardBuilder()
{
	for (int i = 0; i < (this->mazeWidth-1); ++i)
	{
		std::vector<Cell>temp;
		for (int j = 0; j < (this->mazeHeight-1); ++j)
		{
			Cell condition;
			temp.push_back(condition);
		}
		this->maze.push_back(temp);
	}
}

	///////////////////////////////// checkBoundries ///////////////////////////////

bool MazeGenerator::checkNorthBound() {
	if (this->position.yPos == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkSouthBound() {
	if (this->position.yPos == (this->mazeHeight - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkWestBound() {
	if (this->position.xPos == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkEastBound()
{
	if (this->position.xPos == (this->mazeWidth - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

	// check position

bool MazeGenerator::checkNorth()
{
	if (this->maze[this->position.xPos][this->position.yPos-1].discovered == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkSouth()
{
	if (this->maze[this->position.xPos][this->position.yPos+1].discovered == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkWest()
{
	if (this->maze[this->position.xPos-1][this->position.yPos].discovered == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkEast()
{
	if (this->maze[this->position.xPos+1][this->position.yPos].discovered == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

	// check canMove

bool MazeGenerator::canMoveNorth() {
	if (MazeGenerator::checkNorthBound() || MazeGenerator::checkNorth())
	{
		return false;
	}
	else
	{
		 return true;
	}
}

bool MazeGenerator::canMoveSouth() {
	if (MazeGenerator::checkSouthBound() || MazeGenerator::checkSouth())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool MazeGenerator::canMoveWest() {
	if (MazeGenerator::checkWestBound() || MazeGenerator::checkWest())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool MazeGenerator::canMoveEast() {
	if (MazeGenerator::checkEastBound() || MazeGenerator::checkEast())
	{
		return false;
	}
	else
	{
		return true;
	}
}

	// Generates a random number

int MazeGenerator::randomNumber(int upperBound)
{
	std::random_device seed;
	std::mt19937 gen(seed());
	std::uniform_int_distribution<> dis(0, (upperBound-1));
	return dis(gen);
}

	// place start

void MazeGenerator::placeStart()
{
	// find a random spot on the maze and set 
	// the coordinates to that point
	MazeGenerator::setPosition(MazeGenerator::randomNumber(this->mazeWidth),
	MazeGenerator::randomNumber(this->mazeHeight));
}


	// during walk decine direction

DIRECTION MazeGenerator::decideDirection()
{
	std::vector<DIRECTION>tempVector;
	if (MazeGenerator::canMoveNorth()) {
		tempVector.push_back(NORTH);
	}
	if (MazeGenerator::canMoveSouth()) {
		tempVector.push_back(SOUTH);
	}
	if (MazeGenerator::canMoveSouth()) {
		tempVector.push_back(WEST);
	}
	if (MazeGenerator::canMoveSouth()) {
		tempVector.push_back(EAST);
	}
	if (tempVector.size() == 0) {
		return NONE;
	}
	else
	{
		return tempVector[MazeGenerator::randomNumber(tempVector.size())];
	}
}

	// Connect the pieces as it moves

void MazeGenerator::connectNorth()
{
	maze[this->position.xPos][this->position.yPos].northConnection = true;
	maze[this->position.xPos][this->position.yPos - 1].southConnection = true;
}

void MazeGenerator::connectSouth()
{
	maze[this->position.xPos][this->position.yPos + 1].northConnection = true;
	maze[this->position.xPos][this->position.yPos].southConnection = true;
}

void MazeGenerator::connectWest()
{
	maze[this->position.xPos][this->position.yPos].westConnection = true;
	maze[this->position.xPos][this->position.yPos - 1].eastConnection = true;
}

void MazeGenerator::connectEast()
{
	maze[this->position.xPos][this->position.yPos].eastConnection = true;
	maze[this->position.xPos][this->position.yPos + 1].westConnection = true;
}

	///////////          walk in direction             //////////////

void MazeGenerator::walkNorth()
{
	this->position.yPos -= 1;
}

void MazeGenerator::walkSouth()
{
	this->position.yPos += 1;
}

void MazeGenerator::walkWest()
{
	this->position.xPos -= 1;
}

void MazeGenerator::walkEast()
{
	this->position.xPos += 1;
}

	// walk mode

void MazeGenerator::walkMode()
{
	MazeGenerator::placeStart();
	DIRECTION direction = MazeGenerator::decideDirection();
	switch (direction)
	{
	case NORTH:
		MazeGenerator::connectNorth();
		MazeGenerator::walkNorth();
		break;
	case SOUTH:
		MazeGenerator::connectSouth();
		MazeGenerator::walkSouth();
		break;
	case WEST:
		MazeGenerator::connectWest();
		MazeGenerator::walkWest();
		break;
	case EAST:
		MazeGenerator::connectEast();
		MazeGenerator::walkWest();
		break;
	case NONE:
		MazeGenerator::huntMode();
		break;
	default:
		std::cout << "error in the decide direction function" << std::endl;
	}
}

	// hunt check

void MazeGenerator::huntChecker(int i, int j)
{
	if (!MazeGenerator::checkNorthBound() && MazeGenerator::checkNorth())
	{
		MazeGenerator::setPosition(i, j);
		MazeGenerator::connectSouth();
		MazeGenerator::walkMode();
	}
	else if (!MazeGenerator::checkSouthBound() && MazeGenerator::checkSouth())
	{
		MazeGenerator::setPosition(i, j);
		MazeGenerator::connectNorth();
		MazeGenerator::walkMode();
	}
	else if (!MazeGenerator::checkWestBound() && MazeGenerator::checkWest())
	{
		MazeGenerator::setPosition(i, j);
		MazeGenerator::connectEast();
		MazeGenerator::walkMode();
	}
	else if (!MazeGenerator::checkEastBound() && MazeGenerator::checkEast())
	{
		MazeGenerator::setPosition(i, j);
		MazeGenerator::connectWest();
		MazeGenerator::walkMode();
	}
}

	// hunt Mode 

void MazeGenerator::huntMode()
{
	for (int j = 0; j < this->mazeHeight; ++j)
	{
		for (int i = 0; i < this->mazeWidth; ++i)
		{
			if (maze[i][j].discovered == false )
			{
				MazeGenerator::huntChecker(i,j);
			}
		}
	}
}

/*
	Binary Files creation
*/

void MazeGenerator::openBinFile()
{
	this->binFile.open("binFile.bin");
}

void MazeGenerator::setFirstThreeNumbers()
{

}

void MazeGenerator::setSouthWall(int i, int j)
{
	coords a, b;
	a.xPos = i;
	a.yPos = j;
	b.xPos = i;
	b.yPos = j + 1;
}

void MazeGenerator::setEastWall(int i, int j)
{
	coords a, b;
	a.xPos = i;
	a.yPos = j;
	b.xPos = i + 1;
	b.yPos = j;
}

void MazeGenerator::mazeConnectionChecker()
{
	for (int j = 0; j < (this->mazeHeight - 1); j++)
	{
		for (int i = 0; i < (this->mazeWidth - 2); i++)
		{
			if (this->maze[i][j].eastConnection == false)
			{
				MazeGenerator::setEastWall(i, j);
			}
		}
	}
	for (int i = 0; i < (this->mazeWidth - 1); i++)
	{
		for (int j = 0; j < (this->mazeWidth - 2); j++)
		{
			if (this->maze[i][j].southConnection == false)
			{
				MazeGenerator::setSouthWall(i, j);
			}
		}
	}
}

std::string MazeGenerator::intToBin(int num)
{
	std::string binNum;
	while (num > 0)
	{
		if (num % 2 == 1)
		{
			binNum = '1' + binNum;
		}
		else
		{
			binNum = '0' + binNum;
		}
		num = num/2;
	}
	while (binNum.size() < 32)
	{
		binNum = '0' + binNum;
	}
	return binNum;
}

void MazeGenerator::binFileEditor()
{

}

void MazeGenerator::closeBinFile()
{

}