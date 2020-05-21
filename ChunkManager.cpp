#include "ChunkManager.h"
#include	"Chunk.h"
#include	"World.h"
#include <iostream>

ChunkManager::ChunkManager(World& world) : mpWorld(&world)
{
}

//���û�ж�Ӧ�����飬������һ��
Chunk& ChunkManager::getChunk(int x, int z)
{
	if (mChunks.find({ x,z }) == mChunks.end())
	{
		mvec2i_xz	location(x, z);
		Chunk	chunk(*mpWorld, mvec2i(x, z));
		mChunks.emplace(location, chunk);
	}
	return mChunks.at({ x,z });
}

Chunk& ChunkManager::getChunk(const mvec2i_xz& location)
{
	return getChunk(location.x, location.z);
}


bool ChunkManager::makeMesh(int x, int z)
{
	//��֤���������������Ѿ�������
	getChunk(std::max(0, x - 1), z).load();
	getChunk(x, std::max(0, z - 1)).load();
	getChunk(x + 1, z).load();
	getChunk(x, z + 1).load();

	//Ϊ���������mesh
	getChunk(x, z).load();
	//std::cout << "Chunk " << x << ' ' << z << " loaded." << std::endl;
	return getChunk(x, z).makeMesh();

}

bool ChunkManager::makeMesh(const mvec2i_xz& location)
{
	return makeMesh(location.x, location.z);
}

void ChunkManager::queueChunk(int x, int z)
{
}

void ChunkManager::update()
{
}
