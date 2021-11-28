#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Andreasen Render", NULL, NULL);

	if (window == NULL) {
		std::cout << "GLFW window couldn't be created... no window for you :'( " << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
}