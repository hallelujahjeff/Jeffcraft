#include "BlockDatabase.h"
#include <iostream>
#pragma once

BlockDatabase::BlockDatabase()	:spTexture("DefaultPack")
{
	//初始化方块数据库，make_unique将调用对应的BlockData构造函数
	std::cout << "BDB has been constructed!" << std::endl;
	mBlocks[(int)BlockId::Air] = std::make_unique<BlockData>("Air");
	mBlocks[(int)BlockId::Grass] = std::make_unique<BlockData>("Grass");
	mBlocks[(int)BlockId::Dirt] = std::make_unique<BlockData>("Dirt");
	mBlocks[(int)BlockId::Stone] = std::make_unique<BlockData>("Stone");
	mBlocks[(int)BlockId::OakBark] = std::make_unique<BlockData>("OakBark");
	mBlocks[(int)BlockId::OakLeaf] = std::make_unique<BlockData>("OakLeaf");
	mBlocks[(int)BlockId::Sand] = std::make_unique<BlockData>("Sand");
	mBlocks[(int)BlockId::Water] = std::make_unique<BlockData>("Water");
}

BlockDatabase& BlockDatabase::get()
{
	static BlockDatabase BDB;
	return BDB;
	// TODO: 在此处插入 return 语句
}

const BlockData& BlockDatabase::getData(BlockId id) const
{
	return *mBlocks[(int)id];
}
