#pragma once
#include"ChunkSection.h"
#include<vector>
#include"Tools.h"

class Baserender;

class Chunk
{
public:
	Chunk(World& world, const mvec2i& location);

	bool makeMesh();	
	
	void load();
	bool hasLoaded();

	void setBlock(int x, int y, int z, ChunkBlock block);
	void setBlock(mvec3i location, ChunkBlock block);

	ChunkBlock getBlock(int x, int y, int z);
	ChunkBlock getBlock(mvec3i location);

	mvec2i_xz getLocation();
	ChunkSection& getSection(int index);	//���ص�index��ChunkSection(�±������������)

	void drawChunks(Baserender& render);		//����Chunk
	void tryAddSection(int y);	//��̬����Section

private:
	bool outOfBounds(int x,int y,int z);
	std::vector<ChunkSection>	mChunks;		//һ����ͼChunk�洢���chunks����ֱ���У�
	mvec2i		mLocation;		

	bool isLoaded = false;
	World* mpWorld;

};

