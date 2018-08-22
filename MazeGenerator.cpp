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
	this->mazeHeight = b;
}

// get input for dimensions of maze

void MazeGenerator::takeVallues()
{
	int width, height;
	std::cout << "Enter Maze width then height and hit enter" << std::endl;
	std::cout << "Maze dimenaions cannont fall bellow three" << std::endl;
	std::cin >> width >> height;
	if (width < 3 || height < 3)
	{
		MazeGenerator::takeVallues();
	}
	else
	{
		MazeGenerator::setDimensions(width, height);
	}
	std::cout << "\nYou entered the height: " 
		<< this->mazeHeight << " and width: " << this->mazeWidth << std::endl;
}

	// fill in the maze

void MazeGenerator::boardBuilder()
{
	for (int i = 0; i < (this->mazeWidth);i++)
	{
		std::vector<Cell>temp;
		for (int j = 0; j < (this->mazeHeight);j++)
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
	if (this->position.yPos == (this->mazeHeight-1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::checkWestBound() {
	if (this->position.xPos < 1)
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
	if (this->position.xPos == (this->mazeWidth-1))
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
	if (!MazeGenerator::checkNorthBound())
	{
		if(!MazeGenerator::checkNorth())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		 return false;
	}
}

bool MazeGenerator::canMoveSouth() {
	if (!MazeGenerator::checkSouthBound())
	{
		if (!MazeGenerator::checkSouth())
		{
			return true;
		}
		else
		{
			return false;
		}	
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::canMoveWest() {
	if (!MazeGenerator::checkWestBound())
	{
		if (!MazeGenerator::checkWest())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool MazeGenerator::canMoveEast() {
	if (!MazeGenerator::checkEastBound())
	{
		if (!MazeGenerator::checkEast())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

	// Generates a random number

double MazeGenerator::randomNumber(double upperBound)
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
	MazeGenerator::setDiscovered();
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
	if (MazeGenerator::canMoveWest()) {
		tempVector.push_back(WEST);
	}
	if (MazeGenerator::canMoveEast()) {
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
	this->maze[this->position.xPos]
		[this->position.yPos].northConnection = true;
	this->maze[this->position.xPos]
		[this->position.yPos-1].southConnection = true;
}

void MazeGenerator::connectSouth()
{
	this->maze[this->position.xPos]
		[this->position.yPos].southConnection = true;
	this->maze[this->position.xPos]
		[this->position.yPos+1].northConnection = true;
}

void MazeGenerator::connectWest()
{
	this->maze[this->position.xPos]
		[this->position.yPos].westConnection = true;
	this->maze[this->position.xPos-1]
		[this->position.yPos].eastConnection = true;
}

void MazeGenerator::connectEast()
{
	this->maze[this->position.xPos]
		[this->position.yPos].eastConnection = true;
	this->maze[this->position.xPos+1]
		[this->position.yPos].westConnection = true;
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

void MazeGenerator::setDiscovered()
{
	this->maze[this->position.xPos]
		[this->position.yPos].discovered = true;
}

	// walk mode

void MazeGenerator::walkMode()
{
	DIRECTION direction = MazeGenerator::decideDirection();
	switch (direction)
	{
	case NORTH:
		MazeGenerator::connectNorth();
		MazeGenerator::walkNorth();
		MazeGenerator::setDiscovered();
		MazeGenerator::walkMode();
		break;
	case SOUTH:
		MazeGenerator::connectSouth();
		MazeGenerator::walkSouth();
		MazeGenerator::setDiscovered();
		MazeGenerator::walkMode();
		break;
	case WEST:
		MazeGenerator::connectWest();
		MazeGenerator::walkWest();
		MazeGenerator::setDiscovered();
		MazeGenerator::walkMode();
		break;
	case EAST:
		MazeGenerator::connectEast();
		MazeGenerator::walkEast();
		MazeGenerator::setDiscovered();
		MazeGenerator::walkMode();
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
	MazeGenerator::setPosition(i, j);
	if (!MazeGenerator::checkNorthBound())
	{

		if (MazeGenerator::checkNorth())
		{
			MazeGenerator::connectNorth();
			MazeGenerator::setDiscovered();
			MazeGenerator::walkMode();
		}
	}
	if (!MazeGenerator::checkSouthBound())
	{
		if (MazeGenerator::checkSouth())
		{
			MazeGenerator::connectSouth();
			MazeGenerator::setDiscovered();
			MazeGenerator::walkMode();
		}
	}
	if (!MazeGenerator::checkWestBound())
	{
		if (MazeGenerator::checkWest())
		{
			MazeGenerator::connectWest();
			MazeGenerator::setDiscovered();
			MazeGenerator::walkMode();
		}
	}
	if (!MazeGenerator::checkEastBound())
	{
		if (MazeGenerator::checkEast())
		{
			MazeGenerator::connectEast();
			MazeGenerator::setDiscovered();
			MazeGenerator::walkMode();
		}
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
	this->binFile.open("binFile.bin", std::ios::binary | 
		std::ios::in | std::ios::out | std::ios::trunc);
}

double MazeGenerator::countEdges()
{
	double count = 0;
	for (int j = 0; j < (this->mazeHeight); j++)
	{
		for (int i = 0; i < (this->mazeWidth); i++)
		{
			if (this->maze[i][j].eastConnection == false)
			{
				count++;
			}
		}
	}
	for (int i = 0; i < (this->mazeWidth); i++)
	{
		for (int j = 0; j < (this->mazeWidth); j++)
		{
			if (this->maze[i][j].southConnection == false)
			{
				count++;
			}
		}
	}
	return count;
}

void MazeGenerator::setFirstThreeNumbers()
{
	MazeGenerator::binFileEditor(MazeGenerator::intToBin(this->mazeWidth));
	MazeGenerator::binFileEditor(MazeGenerator::intToBin(this->mazeWidth));
	MazeGenerator::binFileEditor(MazeGenerator::intToBin
		(MazeGenerator::countEdges()));
}

coords MazeGenerator::setSouthWallA(int i, int j)
{
	coords a;
	a.xPos = i;
	a.yPos = j;
	return a;
}

coords MazeGenerator::setSouthWallB(int i, int j)
{
	coords b;
	b.xPos = i;
	b.yPos = j + 1;
	return b;
}

coords MazeGenerator::setEastWallA(int i, int j)
{
	coords a;
	a.xPos = i;
	a.yPos = j;
	return a;
}

coords MazeGenerator::setEastWallB(int i, int j)
{
	coords b;
	b.xPos = i + 1;
	b.yPos = j;
	return b;
}

void MazeGenerator::mazeConnectionChecker()
{
	for (int j = 0; j < (this->mazeHeight); j++)
	{
		for (int i = 0; i < (this->mazeWidth); i++)
		{
			if (this->maze[i][j].eastConnection == false)
			{
				coords a = MazeGenerator::setEastWallA(i, j);
				coords b = MazeGenerator::setEastWallB(i, j);
				MazeGenerator::setEdge(a,b);
			}
		}
	}
	for (int i = 0; i < (this->mazeWidth); i++)
	{
		for (int j = 0; j < (this->mazeWidth); j++)
		{
			if (this->maze[i][j].southConnection == false)
			{
				coords a = MazeGenerator::setSouthWallA(i, j);
				coords b = MazeGenerator::setSouthWallB(i, j);
				MazeGenerator::setEdge(a,b);
			}
		}
	}
}

void MazeGenerator::setEdge(coords a, coords b)
{
	MazeGenerator::binFileEditor(MazeGenerator::intToBin(a.xPos));
	MazeGenerator::binFileEditor(MazeGenerator::intToBin(a.yPos));
	MazeGenerator::binFileEditor(MazeGenerator::intToBin(b.xPos));
	MazeGenerator::binFileEditor(MazeGenerator::intToBin(b.yPos));
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

void MazeGenerator::binFileEditor(std::string input)
{
	for (int counter = 0; counter <= input.size(); counter++) {
		this->binFile.put(input[counter]);
	}
}

void MazeGenerator::closeBinFile()
{
	this->binFile.close();
}