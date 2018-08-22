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
	point a;
	point b;
	double mazeWidth;
	double mazeHeight;
	double noOfEdges;
	int fileSize;
	std::fstream binFile;
	std::ofstream svgFile;
	std::vector<std::string>binFileVector;
public:

	// Enter files names

	void enterBinName();

	// check if file is open and valid

	bool checkFile();

	// check the file extension

	bool checkExten(std::string name);

	// check file size

	bool checkFileSize();

	// start files

	void readLines();

	// binary to decimal

	double binToDecimal(std::string a);

	// Read binFileVector

	void readBinFileVector();

	// Creating a edditing SVG Files

	void startSVG();
	void addEdge();
	void endSVG();
};

