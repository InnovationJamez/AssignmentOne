#include<iostream>
#include<vector>
#include<random>
#include<fstream>

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
	std::fstream binFile;
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

	/*
	Binary Files creation
	*/

	void openBinFile();

	void setFirstThreeNumbers();

	void mazeConnectionChecker();

	void setSouthWall(int i, int j);

	void setEastWall(int i, int j);

	std::string intToBin(int num);

	void binFileEditor();

	void closeBinFile();

};

