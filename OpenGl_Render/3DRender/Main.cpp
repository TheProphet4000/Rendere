#include <stdio.h>
#include <glad/glad.h> 
#include "GLFW/glfw3.h"
#include "Coordinates.h"
#include "Callbacks.h"

int main(int argc, char** argv) {
	glfwSetErrorCallback(glfw_error_callback);
	glfwInit();

	GLFWwindow* window = glfwCreateWindow(900, 800, "RenderMaster", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}