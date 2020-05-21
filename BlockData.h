#pragma once
#include"Tools.h"
#include<string>
#include<vector>
#include<glm/glm.hpp>

struct Data
{
	mvec2i	texTopCoord;
	mvec2i	texSideCoord;
	mvec2i	texBottomCoord;
};

class BlockData
{
public:
	BlockData(const std::string& filename);
	Data mData;
};