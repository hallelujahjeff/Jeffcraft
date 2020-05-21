#include "Chunk.h"
#include"ChunkMeshBuilder.h"
#include"Baserender.h"
#include"Random.h"
#include"NoiseGenerator.h"
#include"TerrainGen.h"
#include<queue>
#include<time.h>


Chunk::Chunk(World& world, const mvec2i& location)
	: mpWorld(&world), mLocation(location)
{
	
}

bool Chunk::makeMesh()
{
	for (auto& chunk : mChunks)
	{
		if (!chunk.hasMesh())
		{
			ChunkMeshBuilder(chunk, chunk.mesh).buildMesh();
			chunk.mesh.bufferMesh();
			chunk.setHasMesh(true);
			return true;
		}
	}
		return false;
}

void Chunk::load()
{
	if (isLoaded)		return;
	TerrainGenerator gen;
	gen.generatorFor(*this);
	isLoaded = true;
	return;
}

bool Chunk::hasLoaded()
{
	return isLoaded;
}

void Chunk::setBlock(int x, int y, int z, ChunkBlock block)
{
	tryAddSection(y);
	if (outOfBounds(x, y, z))	return;
	int blockY = y % CHUNK_SIZE;
	mChunks.at(y / CHUNK_SIZE).setBlock(x, blockY, z, block);
}

void Chunk::setBlock(mvec3i location, ChunkBlock block)
{
	setBlock(location.x, location.y, location.z, block);
}

ChunkBlock Chunk::getBlock(int x, int y, int z)
{
	if (outOfBounds(x, y, z))	return BlockId::Air;
	int blockY = y % CHUNK_SIZE;
	return mChunks.at(y / CHUNK_SIZE).getBlock(x, blockY, z);
}

ChunkBlock Chunk::getBlock(mvec3i location)
{
	return getBlock(location.x, location.y, location.z);
}

mvec2i_xz Chunk::getLocation()
{
	return mvec2i_xz{ mLocation.x,mLocation.y };
}

ChunkSection& Chunk::getSection(int index)
{
	static ChunkSection errorSection(*mpWorld, {444,444,444});
	while (index >= (int)mChunks.size() || index < 0)
		return errorSection;
		//mChunks.emplace_back(*mpWorld, mvec3i{ mLocation.x,(int)mChunks.size(),mLocation.y });
	return mChunks.at(index);
}

void Chunk::drawChunks(Baserender& render)
{
	for (auto &chunk : mChunks)
	{
		if (chunk.hasMesh())
			render.drawChunk(chunk.mesh);
	}
}

//给定一个方块的y坐标，若当前Chunk的ChunkSection中没有包含这个y坐标的Section，则动态省请到足够为止
void Chunk::tryAddSection(int y)
{
	int index = y / CHUNK_SIZE;
	while ((int)mChunks.size() < index + 1)
		mChunks.emplace_back(*mpWorld, mvec3i{ mLocation.x, (int)mChunks.size(), mLocation.y });
}

bool Chunk::outOfBounds(int x, int y, int z)
{
	if (x > CHUNK_SIZE	|| z > CHUNK_SIZE)	return true;
	if (x < 0 || y < 0 || z < 0)	return true;
	if (y >= CHUNK_SIZE * mChunks.size())	return true;
	return false;
}



