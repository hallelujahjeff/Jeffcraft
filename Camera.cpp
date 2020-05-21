//处理摄像机相关操作
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<iostream>
#include "Camera.h"
#include"config.h"


/*Default camera values*/
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

glm::vec3 Position;
glm::vec3 Front;
glm::vec3 Up;
glm::vec3 Right;
glm::vec3 WorldUp;

//Euler Angles
float Yaw;
float Pitch;

Camera::Camera(glm::vec3 position , glm::vec3 up)
{
	Yaw = YAW;	
	Pitch = Pitch;
	Position = position;
	WorldUp = up;
	updateCameraVectors();
}

const glm::mat4 Camera::GetViewMatrix() const
{
	return viewMatrix;
}

const glm::mat4 Camera::GetPorjMatrix() const
{
	return projMatrix;
}

const glm::mat4 Camera::GetViewProjMatrix() const
{
	return projMatrix * viewMatrix;
}

void Camera::updateCameraVectors()
{
	// 更新摄像机的朝向
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);

	//std::cout << front.x << ' ' << front.y << ' ' << front.z << std::endl;

	// 更新摄像机的右向量和上向量
	Right = glm::normalize(glm::cross(Front, WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	Up = glm::normalize(glm::cross(Right, Front));

	//更新两个矩阵
	viewMatrix = glm::lookAt(Position, Position + Front, Up);
	projMatrix = glm::perspective(glm::radians(ZOOM), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
}

