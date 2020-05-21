#include "BlockDatabase.h"
#include <iostream>
#pragma once

BlockDatabase::BlockDatabase()	:spTexture("DefaultPack")
{
	//��ʼ���������ݿ⣬make_unique�����ö�Ӧ��BlockData���캯��
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
	// TODO: �ڴ˴����� return ���
}

const BlockData& BlockDatabase::getData(BlockId id) const
{
	return *mBlocks[(int)id];
}
