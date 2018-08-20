#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<math.h>
#include<cstring>

struct point {
	double x, y;
};

class MazeLoader
{
private:
	std::string name;
	double mazeWidth;
	double mazeHeight;
	double noOfEdges;
	std::fstream binFile;
	std::ofstream svgFile;
	std::vector<std::string>binFileVector;
public:

	// Enter files names

	void enterBinName();

	// start files

	void readLines();

	// binary to decimal

	double binToDecimal(std::string a);

	// Read binFileVector

	void readBinFileVector();

	// Creating a edditing SVG Files

	void startSVG();
	void addEdge(point a, point b);
	void endSVG();
};

