#include "BlockData.h"
#include<fstream>

BlockData::BlockData(const std::string& filename)
{
	std::ifstream inFile("res\\Blocks\\" + filename + ".block");
	if (!inFile.is_open())
		throw std::runtime_error("Unable to open block file: " + filename + "!");

	std::string line;
	//一行行读取
    while (std::getline(inFile, line))
    {
        if (line == "TexTop")
        {
            int x, y;
            inFile >> x >> y;
            mData.texTopCoord = { x, y };
        }
        else if (line == "TexSide")
        {
            int x, y;
            inFile >> x >> y;
            mData.texSideCoord = { x, y };
        }
        else if (line == "TexBottom")
        {
            int x, y;
            inFile >> x >> y;
            mData.texBottomCoord = { x, y };
        }
        else if (line == "TexAll")
        {
            int x, y;
            inFile >> x >> y;
            mData.texTopCoord = { x, y };
            mData.texSideCoord = { x, y };
            mData.texBottomCoord = { x, y };
        }
    }

}
