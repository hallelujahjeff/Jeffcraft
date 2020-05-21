//储存一个chunk的mesh，支持将方块的一个面加入mesh，绑定model以及访问mesh的model
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

	void bufferMesh();	//将Mesh数据加入缓冲

	const Model& getModel() const;
private:
	Model mModel;
	Mesh mMesh;
	GLuint indexIndex = 0;
};