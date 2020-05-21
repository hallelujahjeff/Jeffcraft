#include "ChunkBlock.h"


ChunkBlock::ChunkBlock(BlockId id)
{
	this->id = (Block_t)id;
}

const BlockData& ChunkBlock::getData() const
{
	return BlockDatabase::get().getData((BlockId)id);
	// TODO: 在此处插入 return 语句
}


