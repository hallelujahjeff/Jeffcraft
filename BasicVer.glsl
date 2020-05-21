#version 330 core
layout ( location = 0 ) in vec3 aPos;
layout ( location = 1 ) in vec2 aTexCoords;

out vec2 TexCoords;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;
//uniform mat4 projViewMatrix;

void main()
{
	//gl_Position = vec4(aPos,1.0);
	gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(aPos,1.0);
	//gl_Position = projViewMatrix * modelMatrix * vec4(aPos,1.0);
	TexCoords = aTexCoords;
}