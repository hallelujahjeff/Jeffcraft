#pragma once
#include"BlockId.h"
#include	"BlockData.h"
#include "BlockDatabase.h"

class ChunkBlock
{
public:
	ChunkBlock() = default;
	ChunkBlock(BlockId);

	const BlockData& getData() const;


	bool operator ==(ChunkBlock other)
	{
		return id == other.id;
	}

	bool operator != (ChunkBlock other)
	{
		return id != other.id;
	}

	const bool operator != (ChunkBlock other) const
	{
		return id != other.id;
	}
private:
	Block_t id = 0;
};