#pragma once
#include<cstdint>

using Block_t = uint8_t;

enum class BlockId : Block_t
{
	Air = 0,
	Grass,
	Dirt,
	Stone,
	OakBark,
	OakLeaf,
	Sand,
	Water,
	NUM_TYPES
};