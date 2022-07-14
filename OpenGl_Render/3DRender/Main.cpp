#include <stdio.h>
#include <glad/glad.h> 
#include "GLFW/glfw3.h"
#include <cstdint>
#include <vector>

#include "Callbacks.h"
#include "Input.h"
#include "Vertex.h"


int main(int argc, char** argv) {
	glfwInit(); // initialize glfw
	glfwSetErrorCallback(glfw_error_callback); //creates a callback function that reports errors

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(900, 800, "RenderMaster", nullptr, nullptr);

	glfwMakeContextCurrent(window); //render window
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); //get glad working

	glfwSetWindowCloseCallback(window, glfw_window_close_callback); //call close window
	//glfwSetFramebufferSizeCallback(window, glfw_framebuffer_size_callback);

	glClearColor(.5f, .5f, .5f, 0.f); //draw background color

	std::vector<DrawDetails> standinMesh;
	{
		// replace this for an model importer in the future
		std::vector<Vertex> cords;

		//create a 2D triangle object (vetices)
		cords.emplace_back(.5f, -.5f, 0.f);
		cords.emplace_back(-.5f, -.5f, 0.f);
		cords.emplace_back(0.f, .5f, 0.f);

		//saves eatch verticy as a element so each one can be reused, less render data yeahhh
		std::vector<uint32_t> elem = { 0,1,2 };
		
		// upload cords to gpu
		standinMesh.push_back(UploadMesh(cords, elem));
	}

	//this need to be fixed, should call terminate and not a loop!!!!!
	while (true) {
		//ProcessInput(window);
		glClear(GL_COLOR_BUFFER_BIT);
		//Draw(standinMesh);
		glfwSwapBuffers(window); //swap back and front buffer screens
		glfwPollEvents(); //add commands to the render pool
	}

	glfwTerminate(); //Terminate Jhon Conner... glfw....
	return 0; // return null so nothing crash when closing
}