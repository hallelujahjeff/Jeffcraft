#include "CubeRender.h"
#include"MatrixCalc.h"
#include"BlockData.h"
#include"BlockDatabase.h"
#include"BlockId.h"
#include"Mesh.h"

CubeRender::CubeRender()	:   mSpriteTexture("DefaultPack")
{
    std::vector<GLfloat> vertexCoords
    {
        //Back
        1, 0, 0,
        0, 0, 0,
        0, 1, 0,
        1, 1, 0,

        //Front
        0, 0, 1,
        1, 0, 1,
        1, 1, 1,
        0, 1, 1,

        //Right
        1, 0, 1,
        1, 0, 0,
        1, 1, 0,
        1, 1, 1,

        //Left
        0, 0, 0,
        0, 0, 1,
        0, 1, 1,
        0, 1, 0,

        //Top
        0, 1, 1,
        1, 1, 1,
        1, 1, 0,
        0, 1, 0,

        //Bottom
        0, 0, 0,
        1, 0, 0,
        1, 0, 1,
        0, 0, 1.
    };

    //BlockData grass = BlockDatabase::get().getData(BlockId::Grass);

    //auto top = mSpriteTexture.getTexture(grass.mData.texTopCoord);
    //auto side = mSpriteTexture.getTexture(grass.mData.texSideCoord);
    //auto bottom = mSpriteTexture.getTexture(grass.mData.texBottomCoord);

    auto top = mSpriteTexture.getTexture({ 0,0 });
    auto side = mSpriteTexture.getTexture({ 1,0 });
    auto bottom = mSpriteTexture.getTexture({ 2,0 });

    std::vector<GLfloat> texCoords;
    texCoords.insert(texCoords.end(), side.begin(), side.end());
    texCoords.insert(texCoords.end(), side.begin(), side.end());
    texCoords.insert(texCoords.end(), side.begin(), side.end());
    texCoords.insert(texCoords.end(), side.begin(), side.end());
    texCoords.insert(texCoords.end(), top.begin(), top.end());
    texCoords.insert(texCoords.end(), bottom.begin(), bottom.end());

    std::vector<GLuint> indices
    {
        0, 1, 2,
        2, 3, 0,

        4, 5, 6,
        6, 7, 4,

        8, 9, 10,
        10, 11, 8,

        12, 13, 14,
        14, 15, 12,

        16, 17, 18,
        18, 19, 16,

        20, 21, 22,
        22, 23, 20
    };

    mCubeModel.addData({ vertexCoords, texCoords, indices });
}

void CubeRender::add(const glm::vec3& pos)
{
	mCubes.push_back(pos);
}

void CubeRender::renderCubes(const Camera& camera)
{
    if (mCubes.empty()) return;
    mCubeShader.use();
    mCubeModel.bindVAO();
    mSpriteTexture.bindTexture();

    mCubeShader.setMat4("viewMatrix", camera.GetViewMatrix());
    mCubeShader.setMat4("projMatrix", camera.GetPorjMatrix());

    for (auto quad : mCubes)
    {
        mCubeShader.setModelMatrix(makeModelMatrix(quad, { 0,0,0 }));
        glDrawElements(GL_TRIANGLES, mCubeModel.getIndicesCount(), GL_UNSIGNED_INT, 0);
    }
    mCubes.clear();

}
