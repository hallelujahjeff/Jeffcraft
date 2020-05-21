//储存一个chunk的方块数据，支持读写其中的方块
#pragma once
#include"Tools.h"
#include"ChunkBlock.h"
#include "ChunkMesh.h"
#include"Tools.h"
#include"config.h"

class World;

class ChunkSection
{
	//记录一个Chunk中一层的信息，判断这一层是否全部为实体方块
	class Layer
	{
	public:
		void update(const ChunkBlock prevBlock,const ChunkBlock &nowBlock)
		{
			mSolidCount += (prevBlock != BlockId::Air ? -1 : 0);
			mSolidCount += (nowBlock != BlockId::Air ? 1 : 0);
		}
		bool isAllSolid()
		{
			return mSolidCount == CHUNK_AREA;
		}
	private:
		int mSolidCount = 0;
	};

public:
	ChunkSection(World& world, const mvec3i& location);
	
	void setBlock(int x, int y, int z, const ChunkBlock& block);
	void setBlock(const mvec3i& pos, const ChunkBlock& block);

	ChunkBlock getBlock(int x, int y, int z);
	ChunkBlock getBlock(const mvec3i &pos);

	Layer & getLayer(int y);	//得到第y层的Layer
	ChunkSection& getAdjacent(int dx, int dz);	//得到相邻的ChunkSection

	void setLocation(int x, int y, int z);
	void setLocation(const mvec3i& pos);

	const mvec3i getLocation();
	bool hasMesh();
	void makeMesh();
	void setHasMesh(bool val);
	ChunkMesh mesh;

private:
	mvec3i toWorldPosition(int x, int y, int z)	const;
	static bool outOfBounds(int val);
	static int getIndex(int x, int y, int z);

	std::array<ChunkBlock, CHUNK_VOLUME>	mBlocks;
	std::array<Layer, CHUNK_SIZE>	mLayers;

	mvec3i mLocation;
	World* mpWorld;
	bool mHasMesh = false;
};