#pragma once
#include<glm/glm.hpp>
#include"Shader.h"

class BasicShader : public Shader
{
public:
	BasicShader(const char* vertexPath = "BasicVer.glsl", const char* fragmentPath = "BasicFrag.glsl", const char* geometryPath = nullptr);
	void setProjViewMatrix(const glm::mat4& pvMatrix);
	void setModelMatrix(const glm::mat4& mMatrix);

protected:
	virtual void getUniforms() override;
private:
	
	GLuint ProjViewMatrixLoc;
	GLuint ModelMatrixLoc;
};