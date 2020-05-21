#pragma once

#include"ChunkSection.h"
#include"ChunkShader.h"
#include"BlockId.h"
#include"Tools.h"
#include"Camera.h"


class ChunkRender
{
public:
	void add(const ChunkMesh& mesh);
	void renderChunks(const Camera& camera);
private:
	std::vector<const ChunkMesh*> mMeshs;
	ChunkShader mChunkShader;
};