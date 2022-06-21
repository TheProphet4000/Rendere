#include "GLFW/glfw3.h"
#include "iostream"
#include "Coordinates.h"

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(900, 800, "Render", NULL, NULL);
	float R = 0.5f, G = 0.5f, B = 1.0f;

	if (window == NULL) { 
		std::cout << "GLFW window couldn't be created... no window for you :'( " << std::endl;
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);

	//Loop until the user closes the window
	while (!glfwWindowShouldClose(window))
	{
		//Render here
		glClear(GL_COLOR_BUFFER_BIT);

		//Swap front and back buffers
		glfwSwapBuffers(window);

		//Poll for and process events
		glfwPollEvents();

		glClearColor(R, G, B, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glfwTerminate();
	return 0;


}