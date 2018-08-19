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

	double binToDecimal(std::string a);

	// Read binFileVector

	void readBinFileVector();

	// Creating a edditing SVG Files

	void startSVG();
	void addEdge(point a, point b);
	void endSVG();
};

