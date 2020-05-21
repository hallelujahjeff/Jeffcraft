#include "ChunkMeshBuilder.h"
#include<iostream>

//六个面的顶点数据
//注意，顶点数据都是由面朝这个面时，左下角的那个点为起点

namespace
{
    const std::vector<GLfloat> frontFace
    {
        0, 0, 1,
        1, 0, 1,
        1, 1, 1,
        0, 1, 1,
    };

    const std::vector<GLfloat> backFace
    {
        1, 0, 0,
        0, 0, 0,
        0, 1, 0,
        1, 1, 0,
    };

    const std::vector<GLfloat> leftFace
    {
        0, 0, 0,
        0, 0, 1,
        0, 1, 1,
        0, 1, 0,
    };

    const std::vector<GLfloat> rightFace
    {
        1, 0, 1,
        1, 0, 0,
        1, 1, 0,
        1, 1, 1,
    };

    const std::vector<GLfloat> topFace
    {
        0, 1, 1,
        1, 1, 1,
        1, 1, 0,
        0, 1, 0,
    };

    const std::vector<GLfloat> bottomFace
    {
        0, 0, 0,
        1, 0, 0,
        1, 0, 1,
        0, 0, 1
    };

}

struct AdjacentPositions
{
    void update(int x, int y, int z)
    {
        up = { x,y + 1,z };
        down = { x,y - 1,z };
        left = { x - 1,y,z };
        right = { x + 1,y,z };
        back = { x,y,z - 1 };
        front = { x,y,z + 1 };
    }
    mvec3i up;
    mvec3i down;
    mvec3i left;
    mvec3i right;
    mvec3i back;
    mvec3i front;
};

ChunkMeshBuilder::ChunkMeshBuilder(ChunkSection& chunk ,ChunkMesh &mesh)
    :   pChunk(&chunk),pMesh(&mesh)
{

}

void ChunkMeshBuilder::buildMesh()
{
    int successCnt = 0;
    AdjacentPositions ap;
    for (int y = 0; y < CHUNK_SIZE; y++)
    {
        if (!shouldMakeLayer(y)) continue;

        for (int z = 0; z < CHUNK_SIZE; z++)
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                mvec3i position = { x,y,z };
                ChunkBlock block = pChunk->getBlock(x, y, z);
                if (block == BlockId::Air)   continue;

                BlockData data = block.getData();
                Data* texData = &data.mData;

                //尝试为一个方向添加面，若这个方向已经有实体方块，则无需添加
                bool isWater = (block == BlockId::Water);
                ap.update(x, y, z);
                if (pChunk->getLocation().y > 0 || y > 0)  tryMakeMesh(bottomFace, texData->texBottomCoord, ap.down, position);
                tryMakeMesh(topFace, texData->texTopCoord, ap.up, position);
                tryMakeMesh(leftFace, texData->texSideCoord, ap.left, position);
                tryMakeMesh(rightFace, texData->texSideCoord, ap.right, position);
                tryMakeMesh(frontFace, texData->texSideCoord, ap.front, position);
                tryMakeMesh(backFace, texData->texSideCoord, ap.back, position);
            }
    }
        
    //std::cout << "Successfully added " << successCnt << "faces!" << std::endl;
}

bool ChunkMeshBuilder::tryMakeMesh(const std::vector<GLfloat>& blockFace, const mvec2i& texturePos, const mvec3i& adjPos, const mvec3i& pos)
{
    if (shouldMakeMesh(adjPos))
    {
        std::vector<GLfloat> texCoords = BlockDatabase::get().spTexture.getTexture(texturePos);
        pMesh->addFace(blockFace, texCoords, pChunk->getLocation(), pos);
        return true;
    }
    return false;
}

bool ChunkMeshBuilder::shouldMakeMesh(const mvec3i& adjPos)
{
    if (pChunk->getBlock(adjPos) == BlockId::Air)    return true;
    return false;
}


bool ChunkMeshBuilder::shouldMakeLayer(int y)
{
    auto adjIsSolid = [&](int dx, int dz)
    {
        ChunkSection& sect = pChunk ->getAdjacent(dx, dz);
        return sect.getLayer(y).isAllSolid();
    };

    return  (!pChunk->getLayer(y).isAllSolid()) ||
        (!pChunk->getLayer(y + 1).isAllSolid()) ||
        (!pChunk->getLayer(y - 1).isAllSolid()) ||

        (!adjIsSolid(1, 0)) ||
        (!adjIsSolid(0, 1)) ||
        (!adjIsSolid(-1, 0)) ||
        (!adjIsSolid(0, -1));
}



