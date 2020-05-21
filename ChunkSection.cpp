#include "ChunkSection.h"
#include"ChunkMeshBuilder.h"
#include"World.h"

ChunkSection::ChunkSection(World& world, const mvec3i& location)	
	: mpWorld(&world), mLocation(location)
{

}

void ChunkSection::setBlock(int x, int y, int z, const ChunkBlock& block)
{
	if (outOfBounds(x)
		|| outOfBounds(y)
		|| outOfBounds(z))
	{
		mvec3i location = toWorldPosition(x, y, z);
		mpWorld->setBlock(location, block);
		return;
	}

	mLayers[y].update(mBlocks[getIndex(x, y, z)],block);
	mBlocks[getIndex(x, y, z)] = block;
}

void ChunkSection::setBlock(const mvec3i& pos, const ChunkBlock& block)
{
	setBlock(pos.x, pos.y, pos.z, block);
}

ChunkBlock ChunkSection::getBlock(int x, int y, int z)
{
	//如果越过了这个Chunk的界，可以转到世界坐标中去查询与该Chunk相邻Chunk位置有无方块
	//这样可以解决两个Chunk之间的遮挡问题
	if (outOfBounds(x)
		|| outOfBounds(y)
		|| outOfBounds(z))
	{
		mvec3i location = toWorldPosition(x, y, z);
		return mpWorld->getBlock(location);
	}
	return mBlocks[getIndex(x, y, z)];
}

ChunkBlock ChunkSection::getBlock(const mvec3i& pos)
{
	return	getBlock(pos.x, pos.y, pos.z);
}

ChunkSection::Layer& ChunkSection::getLayer(int y)
{
	if (y == -1)
		return mpWorld->mChunkManager
		.getChunk(mLocation.x, mLocation.z)
		.getSection(mLocation.y - 1)
		.getLayer(CHUNK_SIZE - 1);

	else if (y == CHUNK_SIZE)
		return mpWorld->mChunkManager
		.getChunk(mLocation.x, mLocation.z)
		.getSection(mLocation.y + 1)
		.getLayer(0);

	else return mLayers[y];
}

ChunkSection& ChunkSection::getAdjacent(int dx, int dz)
{
	int nx = mLocation.x + dx;
	int nz = mLocation.z + dz;
	return mpWorld->mChunkManager
		.getChunk(nx, nz)
		.getSection(mLocation.y);
}



void ChunkSection::setLocation(int x, int y, int z)
{
	this->mLocation = { x,y,z };
}

void ChunkSection::setLocation(const mvec3i& pos)
{
	this->mLocation = pos;
}

const mvec3i ChunkSection::getLocation()
{
	return mLocation;
}

bool ChunkSection::hasMesh()
{
	return mHasMesh;
}

void ChunkSection::makeMesh()
{
	ChunkMeshBuilder(*this, mesh).buildMesh();
	mesh.bufferMesh();
	setHasMesh(true);
}

void ChunkSection::setHasMesh(bool val)
{
	mHasMesh = val;
}

mvec3i ChunkSection::toWorldPosition(int x, int y, int z) const
{
	return 
	{ 
		CHUNK_SIZE * mLocation.x + x,
		CHUNK_SIZE * mLocation.y + y,
		CHUNK_SIZE * mLocation.z + z 
	};
}

bool ChunkSection::outOfBounds(int val)
{
	//范围： 0 ~ CHUNK_SIZE - 1
	return val >= CHUNK_SIZE || val < 0;
}

int ChunkSection::getIndex(int x, int y, int z)
{
	//取出一个CHUNK中的方块
	//一个CHUNK为16 * 16 * 16，可以看作16 * 16的正方形叠了16层
	//这里y指的是层数，下标为0 ~ 15
	//x和z是在一个16 * 16的正方形中的坐标，方块的位置是第z + 1行的第x + 1个（注意x和z都从0开始）
	return y * CHUNK_AREA + z * CHUNK_SIZE + x;
}



