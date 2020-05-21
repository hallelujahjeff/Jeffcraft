#pragma once
#include<map>
#include<unordered_map>
#include"Tools.h"

class Chunk;
class World;

struct myHashFuc
{
	std::size_t operator()(const mvec2i_xz key) const
	{
		auto hash1 = std::hash<int>()(key.x);
		auto hash2 = std::hash<int>()(key.z);
		return std::hash<decltype(key.x)>{}((hash1 ^ hash2) >> 2);
	}
};

class ChunkManager
{
public:
	ChunkManager(World &world);

	//ͨ�������xz����ȡ�ö�Ӧ��Chunk
	Chunk& getChunk(int x, int z);
	Chunk& getChunk(const mvec2i_xz &location);


	//ͨ������xz���괴����ӦChunk��Mesh
	bool makeMesh(int x, int z);
	bool makeMesh(const mvec2i_xz& location);

	void queueChunk(int x, int z);
	void update();	


	std::unordered_map<mvec2i_xz, Chunk,myHashFuc>	mChunks;

	World* mpWorld;
};