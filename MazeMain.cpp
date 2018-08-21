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
		mazeOne.openBinFile();
		mazeOne.setFirstThreeNumbers();
		mazeOne.mazeConnectionChecker();
		mazeOne.closeBinFile();
	}
	if (answer == 2)
	{
		MazeLoader loaderOne;
		loaderOne.enterBinName();
		loaderOne.readLines();
		loaderOne.startSVG();
		loaderOne.readBinFileVector();
		loaderOne.endSVG();
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
	}
	
	return 0;
}