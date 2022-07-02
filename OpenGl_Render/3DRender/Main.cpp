#include <stdio.h>
#include <glad/glad.h> 
#include "GLFW/glfw3.h"
#include "Coordinates.h"
#include "Callbacks.h"

int main(int argc, char** argv) {
	glfwInit(); // initialize glfw
	glfwSetErrorCallback(glfw_error_callback); //creates a callback function that reports errors

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(900, 800, "RenderMaster", nullptr, nullptr);

	glfwMakeContextCurrent(window); //render window
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); //get glad working
	glfwSetWindowCloseCallback(window, glfw_window_close_callback); //call close window

	//this need to be fixed, should call terminate and not a loop!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	while (!true) {
		glfwSwapBuffers(window); //swap back and front buffer screens
		glfwPollEvents(); //add commands to the render pool
	}

	glfwTerminate(); //Terminate Jhon Conner... glfw....
	return 0; // return null so nothing crash when closing
}