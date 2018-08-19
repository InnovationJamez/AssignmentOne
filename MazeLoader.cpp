#include "MazeLoader.h"

void MazeLoader::startFiles()
{
	this->binFile.open("binFile.bin");
	this->svgFile.open("generatedMaze.svg");
}

void MazeLoader::readLines()
{
	char ch;
	std::string tempString;
	while (binFile.good())
	{
		binFile.get(ch);
		tempString = ch + tempString;
		if (tempString.size() == 32)
		{
			this->binFileVector.push_back(tempString);
			tempString.clear();
		}
	}
	this->binFile.close();
}

	// binary to decimal

int MazeLoader::binToDecimal(std::string a)
{
	int tempInt;
	for (int i = 0; i < (a.size() - 1); ++i)
	{
		if (a[i] == '1')
		{
			tempInt += pow(2, i);
		}
	}
	return tempInt;
}

	// Read binFileVector

void MazeLoader::readBinFileVector()
{
	this->mazeWidth = MazeLoader::binToDecimal(binFileVector[0]);
	this->mazeHeight = MazeLoader::binToDecimal(binFileVector[1]);
	this->noOfEdges = MazeLoader::binToDecimal(binFileVector[2]);

	for (int i = 3; i < (this->binFileVector.size() - 1); ++i)
	{
		point a, b;
		if (i % 4 == 3) 
		{
			a.x = MazeLoader::binToDecimal(binFileVector[i]);
		}
		if (i % 4 == 0) 
		{
			a.y = MazeLoader::binToDecimal(binFileVector[i]);
		}
		if (i % 4 == 1)
		{
			b.x = MazeLoader::binToDecimal(binFileVector[i]);
		}
		if (i % 4 == 2) 
		{
			b.y = MazeLoader::binToDecimal(binFileVector[i]);
			MazeLoader::addEdge(a,b);
		}
	}
}

	// Creating Edditing and closing SVG File 

void MazeLoader::startSVG()
{
	svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' ";
	svgFile << "xmlns='http://www.w3.org/2000/svg'>\n";
	svgFile << "<rect width='1' height='1' style='fill: white' />\n";
}

void MazeLoader::addEdge(point a, point b)
{
	double wallWidth = 1 / this->mazeWidth;
	double wallHeight = 1 / this->mazeHeight;
	if (a.x == b.x)
	{
		this->svgFile << "<line stroke='black' stroke-width='0.01' x1='";
		this->svgFile << wallWidth * a.x;
		this->svgFile << "' y1='";
		this->svgFile << wallHeight * a.y;
		this->svgFile << "' x2='";
		this->svgFile << wallWidth * a.x;
		this->svgFile << "' y2='";
		this->svgFile << wallHeight * a.y - wallHeight;
		this->svgFile << "'/>\n";
	}
	else
	{
		this->svgFile << "<line stroke='black' stroke-width='0.01' x1='";
		this->svgFile << wallWidth * a.x;
		this->svgFile << "' y1='";
		this->svgFile << wallHeight * a.y;
		this->svgFile << "' x2='";
		this->svgFile << wallWidth * a.x - wallWidth;
		this->svgFile << "' y2='";
		this->svgFile << wallHeight * a.y;
		this->svgFile << "'/>\n";
	}
}

void MazeLoader::endSVG()
{
	this->svgFile << "</svg>\n";
	this->svgFile.close();
}
