#include<iostream>
#include<vector>
#include<chrono>
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

class MazeGenerator
{
private:
	coords position;
	int mazeWidth;
	int mazeHeight;
	std::vector<std::vector<Cell>>maze;
public:

	// set the valles
	void setMazeWidth(int a);
	void setMazeHeight(int a);

	// get input for dimensions of maze
	void takeVallues();

	// fill in the maze
	
	void boardBuilder();

	// check position
	bool checkNorth();

	bool checkSouth();

	bool checkWest();

	bool checkEast();

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

	void decideDirection();

	// walk in direction

	void walkNorth();

	void walkSouth();

	void walkWest();

	void walkEast();

	// hunt mode

	void huntMode();
};

