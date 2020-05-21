#pragma once
#include"ChunkSection.h"
#include"ChunkMesh.h"
#include"SpriteTexture.h"
#include"BlockData.h"
#include"BlockId.h"
#include"ChunkBlock.h"

class ChunkMeshBuilder
{
public:
	ChunkMeshBuilder(ChunkSection& chunk,ChunkMesh &mesh);		//传一个chunk来构建Chunk Mesh
	void buildMesh();

private:
	bool tryMakeMesh(const std::vector<GLfloat>& blockFace,
		const mvec2i& texturePos,
		const mvec3i& adjPos,
		const mvec3i& pos
	);
	bool shouldMakeMesh(const mvec3i& adjPos);
	bool shouldMakeLayer(int y);
	 
	ChunkSection* pChunk = nullptr;
	ChunkMesh* pMesh = nullptr;
	BlockData* pBlockData = nullptr;
};