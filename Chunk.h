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
	ChunkSection& getSection(int index);	//返回第index个ChunkSection(下标从下往上排列)

	void drawChunks(Baserender& render);		//绘制Chunk
	void tryAddSection(int y);	//动态申请Section

private:
	bool outOfBounds(int x,int y,int z);
	std::vector<ChunkSection>	mChunks;		//一个地图Chunk存储多个chunks（垂直排列）
	mvec2i		mLocation;		

	bool isLoaded = false;
	World* mpWorld;

};

