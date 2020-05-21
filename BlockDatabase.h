#pragma once
#include"BlockId.h"
#include"BlockData.h"
#include"SpriteTexture.h"
#include <memory>
#include <array>


class BlockDatabase 
{
public:
	BlockDatabase();
	static BlockDatabase& get();
	const BlockData& getData(BlockId id)	const;
	SpriteTexture spTexture;

private:
	//��¼Block���ݵ�����ָ��
	
	std::array<std::unique_ptr<BlockData>, (unsigned)BlockId::NUM_TYPES>	mBlocks;

};
