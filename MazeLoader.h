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
	int mazeWidth;
	int mazeHeight;
	int noOfEdges;
	std::fstream binFile;
	std::ofstream svgFile;
	std::vector<std::string>binFileVector;
public:
	void startFiles();
	void readLines();

	// binary to decimal

	int binToDecimal(std::string a);

	// Creating a edditing SVG Files

	void startSVG();
	void addEdge(point a, point b);
	void endSVG();
};

