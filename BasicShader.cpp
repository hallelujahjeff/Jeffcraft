#include "BasicShader.h"

BasicShader::BasicShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath) :
	Shader(vertexPath, fragmentPath, geometryPath)
{
	getUniforms();
};


void BasicShader::setProjViewMatrix(const glm::mat4& pvMatrix)
{
	glUniformMatrix4fv(ProjViewMatrixLoc, 1, GL_FALSE, &pvMatrix[0][0]);
}

void BasicShader::setModelMatrix(const glm::mat4& mMatrix)
{
	glUniformMatrix4fv(ModelMatrixLoc, 1, GL_FALSE, &mMatrix[0][0]);
}

void BasicShader::getUniforms()
{
	use();
	ProjViewMatrixLoc = glGetUniformLocation(ID, "projViewMatrix");
	ModelMatrixLoc = glGetUniformLocation(ID, "modelMatrix");
}
