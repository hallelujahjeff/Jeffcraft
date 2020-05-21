#include "ChunkShader.h"

ChunkShader::ChunkShader()	:	BasicShader("ChunkVer.glsl","ChunkFrag.glsl")
{
	getUniforms();
}

void ChunkShader::getUniforms()
{
	BasicShader::getUniforms();
}
