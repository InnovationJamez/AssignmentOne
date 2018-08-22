#include "MazeLoader.h"

	// Enter files names

void MazeLoader::enterBinName()
{
	std::string name;
	std::cout << "Enter the file name and extension: " << std::endl;
	std::cin >> name;
	std::cout << "\nYou entered " << name << std::endl;
	std::cout << "Is this correct y: yes n: no" << std::endl;
	std::string answer;
	std::cin >> answer;
	std::cout << "\n";
	if (answer == "y" || answer == "Y")
	{
		std::cout << "thank you" << std::endl;
	}
	else
	{
		MazeLoader::enterBinName();
	}

	if (!MazeLoader::checkExten(name))
	{
		MazeLoader::enterBinName();
	}

	this->binFile.open(name.c_str());
	this->svgFile.open("generatedMaze.svg", std::ios::binary |
		std::ios::in | std::ios::out | std::ios::trunc);

	if (!MazeLoader::checkFile())
	{
		MazeLoader::enterBinName();
	}
	if (!MazeLoader::checkFileSize())
	{
		MazeLoader::enterBinName();
	}
}

	// check if file is open and valid

bool MazeLoader::checkFile()
{
	if (this->binFile.is_open())
	{
		return true;

	}
	else
	{
		std::cout << "file did not open" << std::endl;
		return false;
	}
}

	// check the file extension

bool MazeLoader::checkExten(std::string name)
{
	bool x = false;
	std::string tempString;
	for (int i = 0; i < name.size(); i++)
	{
		if (x == false)
		{
			if (name[i] == '.')
			{
				x = true;
			}
		}
		else 
		{
			tempString += name[i];
		}
	}
	if (tempString == "bin")
	{
		return true;
	}
	else
	{
		std::cout << "file type is invalid" << std::endl;
		return false;
	}
}

	// check file size

bool MazeLoader::checkFileSize()
{
	this->binFile.seekg(0, std::ios::end);
	std::string tempString;
	this->fileSize = (int)this->binFile.tellg();
	if (this->fileSize <= 0)
	{
		std::cout << "file is empty" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

	// start files

void MazeLoader::readLines()
{
	char ch;
	this->binFile.seekg(0, std::ios::beg);
	std::string tempString;
	std::string newTempString;
	while (this->binFile.tellg() < this->fileSize)
	{
		this->binFile.get(ch);
		tempString = ch + tempString;
		if (tempString.size() == 33)
		{
			newTempString = tempString.substr(1, tempString.size() - 2);
			this->binFileVector.push_back(newTempString);
			tempString.clear();
		}
	}
	this->binFile.close();
}

	// binary to decimal

double MazeLoader::binToDecimal(std::string a)
{
	double tempInt=0;
	for (int i = 0; i< a.size(); ++i)
	{
		if (a[i] == '1')
		{
			tempInt += pow(2,i);
		}
	}
	return tempInt;
}

	// Read binFileVector

void MazeLoader::readBinFileVector()
{
	this->mazeWidth = MazeLoader::binToDecimal(this->binFileVector[0]);
	this->mazeHeight = MazeLoader::binToDecimal(this->binFileVector[1]);
	this->noOfEdges = MazeLoader::binToDecimal(this->binFileVector[2]);

	for (int i = 3; i < (this->binFileVector.size() - 1); ++i)
	{
		if (i % 4 == 3) 
		{
			this->a.x = MazeLoader::binToDecimal(this->binFileVector[i]);
		}
		if (i % 4 == 0) 
		{
			this->a.y = MazeLoader::binToDecimal(this->binFileVector[i]);
		}
		if (i % 4 == 1)
		{
			this->b.x = MazeLoader::binToDecimal(this->binFileVector[i]);
		}
		if (i % 4 == 2) 
		{
			this->b.y = MazeLoader::binToDecimal(this->binFileVector[i]);
			MazeLoader::addEdge();
		}
	}
}

	// Creating Edditing and closing SVG File 

void MazeLoader::startSVG()
{
	this->svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' ";
	this->svgFile << "xmlns='http://www.w3.org/2000/svg'>\n";
	this->svgFile << "<rect width='1' height='1' style='fill: white' />\n";

	// Draw border
	MazeLoader::lineDefine();
	this->svgFile << "x1='0' y1='0' x2='1' y2='0'/>\n";

	MazeLoader::lineDefine();
	this->svgFile << "x1='1' y1='0' x2='1' y2='1'/>\n";

	MazeLoader::lineDefine();
	this->svgFile << "x1='1' y1='1' x2='0' y2='1'/>\n";

	MazeLoader::lineDefine();
	this->svgFile << "x1='0' y1='1' x2='0' y2='0'/>\n";
}

void MazeLoader::lineDefine()
{
	this->svgFile << "<line stroke='black' stroke-width='";
	this->svgFile << 0.01;
	this->svgFile << "' ";
}

void MazeLoader::addEdge()
{
	double wallWidth = 1 / this->mazeWidth;
	double wallHeight = 1 / this->mazeHeight;
	this->a.x++;
	this->a.y++;
	this->b.x++;
	this->b.y++;

	if (this->a.y == this->b.y)
	{
		MazeLoader::lineDefine();
		this->svgFile << " x1='";
		this->svgFile << wallWidth * this->a.x;
		this->svgFile << "' y1='";
		this->svgFile << wallHeight * this->a.y;
		this->svgFile << "' x2='";
		this->svgFile << wallWidth * this->a.x;
		this->svgFile << "' y2='";
		this->svgFile << wallHeight * this->a.y - wallHeight;
		this->svgFile << "'/>\n";
	}
	else
	{
		MazeLoader::lineDefine();
		this->svgFile << " x1='";
		this->svgFile << wallWidth * this->a.x;
		this->svgFile << "' y1='";
		this->svgFile << wallHeight * this->a.y;
		this->svgFile << "' x2='";
		this->svgFile << wallWidth * this->a.x - wallWidth;
		this->svgFile << "' y2='";
		this->svgFile << wallHeight * this->a.y;
		this->svgFile << "'/>\n";
	}
}

void MazeLoader::endSVG()
{
	this->svgFile << "</svg>\n";
	this->svgFile.close();
}
