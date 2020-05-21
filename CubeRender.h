#pragma once
#include"Model.h"
#include"BasicShader.h"
#include"BasicTexture.h"
#include"SpriteTexture.h"
#include"Camera.h"
#include<vector>

class CubeRender
{
public:
	CubeRender();
	void add(const glm::vec3& pos);
	void renderCubes(const Camera& camera);
private:
	std::vector<glm::vec3>	mCubes;
	Model mCubeModel;
	BasicShader mCubeShader;
	SpriteTexture mSpriteTexture;
};