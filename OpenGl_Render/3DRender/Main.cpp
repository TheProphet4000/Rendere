#include <stdio.h>
#include <glad/glad.h> 
#include "GLFW/glfw3.h"
#include "Coordinates.h"
#include "Callbacks.h"

int main(int argc, char** argv) {
	glfwInit();
	glfwSetErrorCallback(glfw_error_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(900, 800, "RenderMaster", nullptr, nullptr);

	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSetWindowCloseCallback(window, glfw_window_close_callback);

	while (!glfwWindowShouldClose) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}