#pragma once
#include<GLFW/glfw3.h>
#include "QuadRender.h"
#include "CubeRender.h"
#include "ChunkRender.h"

class Baserender
{
public:
	void drawQuad(const glm::vec3& pos);
	void drawCube(const glm::vec3& pos);
	void drawChunk(const ChunkMesh& mesh);
	void finishRender(GLFWwindow* window, Camera &camera); 

private:
	QuadRender mQuadRender;
	CubeRender mCubeRender;
	ChunkRender mChunkRender;
};