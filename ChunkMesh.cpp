#include "ChunkMesh.h"
#include"config.h"
#include<iostream>

ChunkMesh::ChunkMesh()
{
	
}

void ChunkMesh::addFace(const std::vector<GLfloat>& blockFace, 
	const std::vector<GLfloat>& texCoords, 
	const mvec3i& chunkPosition,
	const mvec3i& blockPositon)
{
	auto& vertices = mMesh.vertexPositions;
	auto& texcoords = mMesh.texCoords;
	auto& indices = mMesh.indices;

	texcoords.insert(texcoords.end(), texCoords.begin(), texCoords.end());	

	//一个面有四个顶点坐标
	//每个顶点坐标的位置是 : CHUNK的位置 * CHUNK的边长 + 方块的位置 + 顶点的位置
	for (int i = 0,index = 0; i < 4; i++)
	{
		vertices.push_back(blockFace[index++] + chunkPosition.x * CHUNK_SIZE+  blockPositon.x);	// x
		vertices.push_back(blockFace[index++] + chunkPosition.y * CHUNK_SIZE + blockPositon.y);	// y
		vertices.push_back(blockFace[index++] + chunkPosition.z * CHUNK_SIZE + blockPositon.z);	// z
	}

	//两组索引，逆时针排列
	indices.insert(indices.end(),
		{	indexIndex + 0,
			indexIndex + 1,
			indexIndex + 2,

			indexIndex + 2,
			indexIndex + 3,
			indexIndex + 0 });

	indexIndex += 4;		//添加了四个顶点，索引下标+4
}

void ChunkMesh::bufferMesh()
{
	//std::cout << "Buffered"
	//	<< "\nVertex: " << mMesh.vertexPositions.size()
	//	<< "\nTextures: " << mMesh.texCoords.size()
	//	<< "\nIndices: " << mMesh.indices.size()
	//	<< std::endl;

	mModel.addData(mMesh);

	//释放mesh的vector内存
	mMesh.vertexPositions.clear();
	mMesh.texCoords.clear();
	mMesh.indices.clear();
	mMesh.vertexPositions.shrink_to_fit();
	mMesh.texCoords.shrink_to_fit();
	mMesh.indices.shrink_to_fit();

	//索引下标置0
	indexIndex = 0;
}

const Model& ChunkMesh::getModel() const
{
	return mModel;
	// TODO: 在此处插入 return 语句
}





