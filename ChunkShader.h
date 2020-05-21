#pragma once
#include"BasicShader.h"
class ChunkShader	: public BasicShader 
{
public:
	ChunkShader();

private:
	void getUniforms() override;
};