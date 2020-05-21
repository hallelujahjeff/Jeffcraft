#include<iostream>
#include "Application.h"
#include<iostream>
Application::Application() :state(getWindow())
{
	std::cout << "Application() has been called. " << std::endl;
	window = getWindow();
	camera = getCamera();
}

void Application::runLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		state.process_input();
		state.update();
		state.render(mBaserender);
		
		mBaserender.finishRender(window, *camera);
	
		glfwPollEvents();
		
	}
}
