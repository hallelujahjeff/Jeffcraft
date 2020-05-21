//处理摄像机相关操作

#ifndef CAMERA_H
#define CAMERA_H
#include<glm/glm.hpp>

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

	glm::mat4 viewMatrix;
	glm::mat4 projMatrix;


	//Euler Angles
	float Yaw;
	float Pitch;

	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));
	const glm::mat4 GetViewMatrix() const;
	const glm::mat4 GetPorjMatrix() const; 
	const glm::mat4 GetViewProjMatrix() const;

	void updateCameraVectors();

};


#endif // !CAMERA_H
