#include "Baserender.h"
#include"GUI.h"

void Baserender::drawQuad(const glm::vec3& pos)
{
	mQuadRender.add(pos);
}

void Baserender::drawCube(const glm::vec3& pos)
{
	mCubeRender.add(pos);
}

void Baserender::drawChunk(const ChunkMesh& mesh)
{
	mChunkRender.add(mesh);
}


void Baserender::finishRender(GLFWwindow* window, Camera &camera)
{
	//开启面剔除
	glEnable(GL_CULL_FACE);
	//开启深度测试
	glEnable(GL_DEPTH_TEST);
	//开启混合
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0.6f, 0.6f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//mQuadRender.renderQuads(camera);
	mCubeRender.renderCubes(camera);
	mChunkRender.renderChunks(camera);
	mQuadRender.renderQuads();
	glfwSwapBuffers(window);
}
