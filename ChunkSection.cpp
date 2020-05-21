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
	//���Խ�������Chunk�Ľ磬����ת������������ȥ��ѯ���Chunk����Chunkλ�����޷���
	//�������Խ������Chunk֮����ڵ�����
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
	//��Χ�� 0 ~ CHUNK_SIZE - 1
	return val >= CHUNK_SIZE || val < 0;
}

int ChunkSection::getIndex(int x, int y, int z)
{
	//ȡ��һ��CHUNK�еķ���
	//һ��CHUNKΪ16 * 16 * 16�����Կ���16 * 16�������ε���16��
	//����yָ���ǲ������±�Ϊ0 ~ 15
	//x��z����һ��16 * 16���������е����꣬�����λ���ǵ�z + 1�еĵ�x + 1����ע��x��z����0��ʼ��
	return y * CHUNK_AREA + z * CHUNK_SIZE + x;
}



