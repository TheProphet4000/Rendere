#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	glfwInit(); //init glfw

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Render", NULL, NULL);
	if (window == NULL) { //hvis window ikke kan laves, returnere den fejl.. i stedet for at fortsætte, og crashe.
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); //Fortæller Context at lave "window"
	gladLoadGL(); //init openGL

	glViewport(0, 0, 800, 800); //Fortæller glad, hvormeget den stal tegne på.

	glClearColor(0.61f, 0.07f, 0.12f, 1.0f); //Angiver farve

	glClear(GL_COLOR_BUFFER_BIT); //Putter farven ind i back buffer
	glfwSwapBuffers(window); //bytter front og back buffer.

	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents(); //Fortæller glfw at den skal updatere events, når de er klar.
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}