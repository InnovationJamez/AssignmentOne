#include "MazeGenerator.h"
#include "MazeLoader.h"

int main()
{
	int answer;
	std::cout << "1: Generate a maze\n2:Load Binary File\n";
	std::cin >> answer;
	std::cout << "You selected " << answer << std::endl;
	if (answer == 1)
	{
		MazeGenerator mazeOne;
		mazeOne.takeVallues();
		mazeOne.boardBuilder();
		mazeOne.walkMode();
	}
	if (answer == 2)
	{
		MazeLoader loaderOne;
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
	}
	
	return 0;
}