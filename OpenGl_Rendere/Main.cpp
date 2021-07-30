#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "shaderClass.h" //Farver
#include "VAO.h"		//VertexArrayObject
#include "VBO.h"	   //VertexBufferObject
#include "EBO.h"	  //IndiciesBufferObject??


GLfloat vertices[] = {
//    -X-                  -Y-
	-0.5f,      -0.5f  * float(sqrt(3))     / 3,  0.0f,   //Bund venstre hj�rne
	 0.5f,      -0.5f  * float(sqrt(3))     / 3,  0.0f,  //Bund h�jer hj�rne
	 0.0f,       0.5f  * float(sqrt(3)) * 2 / 3,  0.0f, // Top Midt hj�rne

    -0.5f / 2,   0.5f  * float(sqrt(3))     / 6,  0.0f,  //Mid venstre hj�rne
	 0.5f / 2,   0.5f  * float(sqrt(3))     / 6,  0.0f, //Mid H�jer Hj�rne
	 0.0f,      -0.5f  * float(sqrt(3))     / 3,  0.0f // Mid Bund hj�rne
};

GLuint indices[] = { //WTF er dette

	0, 3, 5,  //Bund Venstre trekant
	3, 2, 4, //Bund H�jer trekant
	5, 4, 1 //Top trekant
};

int main() {

	//init glfw
	glfwInit();

	//fort�ller glfw hvilke verion den skal bruge
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//specifere indstillinger, af et vindue
	GLFWwindow* window = glfwCreateWindow(800, 800, "Render", NULL, NULL);

	//hvis window ikke kan laves, returnere den fejl.. i stedet for at forts�tte, og crashe.
	if (window == NULL) {
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Fort�ller Context at lave "window"
	glfwMakeContextCurrent(window);

	//init openGL
	gladLoadGL();

	//Fort�ller glad, hvormeget den stal tegne p�.
	glViewport(0, 0, 800, 800);

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkVBO(VBO1, 0);

	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	//Fort�ller glfw at den skal updatere events, n�r de er klar.
	while (!glfwWindowShouldClose(window)) {

		//tegner baggrunds farve
		glClearColor(0.01f, 0.13f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//fort�ller openGL hvilke shader der er i brug
		shaderProgram.Activate();

		//binder shaderen, s� den bliver brugt
		VAO1.Bind();

		//tegner trekanterne     hvor mange         index af indices
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		//Skifer usynlige, og synlige buffers
		glfwSwapBuffers(window);

		//Pooler events up, s� alt er tegnet inden det bliver vist
		glfwPollEvents();
	}

	//fjerner alt un�dvendige data, der er blevet forarbejdet, eller binded

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	//lukker vinduet
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}