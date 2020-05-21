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

	//һ�������ĸ���������
	//ÿ�����������λ���� : CHUNK��λ�� * CHUNK�ı߳� + �����λ�� + �����λ��
	for (int i = 0,index = 0; i < 4; i++)
	{
		vertices.push_back(blockFace[index++] + chunkPosition.x * CHUNK_SIZE+  blockPositon.x);	// x
		vertices.push_back(blockFace[index++] + chunkPosition.y * CHUNK_SIZE + blockPositon.y);	// y
		vertices.push_back(blockFace[index++] + chunkPosition.z * CHUNK_SIZE + blockPositon.z);	// z
	}

	//������������ʱ������
	indices.insert(indices.end(),
		{	indexIndex + 0,
			indexIndex + 1,
			indexIndex + 2,

			indexIndex + 2,
			indexIndex + 3,
			indexIndex + 0 });

	indexIndex += 4;		//������ĸ����㣬�����±�+4
}

void ChunkMesh::bufferMesh()
{
	//std::cout << "Buffered"
	//	<< "\nVertex: " << mMesh.vertexPositions.size()
	//	<< "\nTextures: " << mMesh.texCoords.size()
	//	<< "\nIndices: " << mMesh.indices.size()
	//	<< std::endl;

	mModel.addData(mMesh);

	//�ͷ�mesh��vector�ڴ�
	mMesh.vertexPositions.clear();
	mMesh.texCoords.clear();
	mMesh.indices.clear();
	mMesh.vertexPositions.shrink_to_fit();
	mMesh.texCoords.shrink_to_fit();
	mMesh.indices.shrink_to_fit();

	//�����±���0
	indexIndex = 0;
}

const Model& ChunkMesh::getModel() const
{
	return mModel;
	// TODO: �ڴ˴����� return ���
}





