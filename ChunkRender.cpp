#include "ChunkRender.h"
#include"MatrixCalc.h"
#include<vector>
void ChunkRender::add(const ChunkMesh& mesh)
{
	mMeshs.push_back(&mesh);
}

void ChunkRender::renderChunks(const Camera& camera)
{
	if (mMeshs.empty())	return;
	mChunkShader.use();
	BlockDatabase::get().spTexture.bindTexture();
	//mChunkShader.setProjViewMatrix(camera.GetViewProjMatrix());
	mChunkShader.setMat4("viewMatrix", camera.GetViewMatrix());
	mChunkShader.setMat4("projMatrix", camera.GetPorjMatrix());
	for (const ChunkMesh *mesh : mMeshs)
	{
		const ChunkMesh& m = *mesh;
		(m.getModel()).bindVAO();
		mChunkShader.setModelMatrix(makeModelMatrix({ 0,0,0 }, { 0,0,0 }));
		glDrawElements(GL_TRIANGLES, m.getModel().getIndicesCount(), GL_UNSIGNED_INT, NULL);
	}
	mMeshs.clear();
}
