//����һ��chunk��mesh��֧�ֽ������һ�������mesh����model�Լ�����mesh��model
#pragma once
#include<glm/glm.hpp>
#include"Model.h"
#include"Mesh.h"
#include"Tools.h"

class ChunkMesh {
public:
	ChunkMesh();
	void addFace(const std::vector<GLfloat>& blockFace,
		const std::vector<GLfloat>& texCoords,
		const mvec3i& chunkPosition,
		const mvec3i& blockPositon);

	void bufferMesh();	//��Mesh���ݼ��뻺��

	const Model& getModel() const;
private:
	Model mModel;
	Mesh mMesh;
	GLuint indexIndex = 0;
};