#include<iostream>
#include<vector>
#include<random>

struct Cell
{
	bool northConnection = false;
	bool southConnection = false;
	bool eastConnection = false;
	bool westConnection = false;
	bool discovered = false;
};

struct coords
{
	int xPos, yPos;
};

enum DIRECTION{
	NORTH = 1,
	SOUTH = 2,
	WEST = 3,
	EAST = 4,
	NONE = 5
};

class MazeGenerator
{
private:
	coords position;
	int mazeWidth;
	int mazeHeight;
	std::vector<std::vector<Cell>>maze;
public:

	// set the width and height
	void setDimensions(int a, int b);

	// set position
	void setPosition(int i, int j);

	// get input for dimensions of maze
	void takeVallues();

	// fill in the maze
	
	void boardBuilder();

	// checkBoundries

	bool checkNorthBound();

	bool checkSouthBound();

	bool checkWestBound();

	bool checkEastBound();

	// check surounding spaces
	bool checkNorth();

	bool checkSouth();

	bool checkWest();

	bool checkEast();

	// check canMove

	bool canMoveNorth();

	bool canMoveSouth();

	bool canMoveWest();

	bool canMoveEast();

	// hunt check

	void huntChecker(int i, int j);

	/*
	This part of the program will be filling the
	maze. It will start at a random location. 
	Then it will start the walk. Then go into 
	hunt mode
	*/

	// Generates a random number

	int randomNumber(int upperbound);

	// placeStart

	void placeStart();

	// decine direction

	DIRECTION decideDirection();

	// walk in direction

	void walkNorth();

	void walkSouth();

	void walkWest();

	void walkEast();

	// connect prieces

	void connectNorth();

	void connectSouth();

	void connectWest();

	void connectEast();

	// walk mode

	void walkMode();

	// hunt mode

	void huntMode();
};

