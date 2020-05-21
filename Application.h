#pragma once
//定义程序窗口

#include"Camera.h"
#include"State.h"
#include"Context.h"
#include"Context.h"

class Application
{
public:
	Application();
	void runLoop();
	GLFWwindow	 *getWindow() { return context.window; }
	Camera* getCamera() { return &state.myPlayer.camera; }

private:
	Context context;
	State state;
	Baserender mBaserender;
	GLFWwindow* window;
	Camera* camera;
};