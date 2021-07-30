#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>

#include "shaderClass.h" //Farver
#include "VAO.h"		//VertexArrayObject
#include "VBO.h"	   //VertexBufferObject
#include "EBO.h"	  //IndiciesBufferObject??


GLfloat vertices[] = {
//		 -Kordinater-	   |		  -Farver-			|		Textur Kordinater			 OpenGL blander gradiere farveværdierne
	-0.5f,	-0.5f,	0.0f,		1.0f,	0.0f,	0.0f,		0.0f, 0.0f,	   // bund højer
	-0.5f,	 0.5f,	0.0f,		0.0f,	1.0f,	0.0f,		0.0f, 1.0f,	  // top højer
	 0.5f,	 0.5f,	0.0f,		0.0f,	0.0f,	1.0f,		1.0f, 1.0f,	 // top venstre
	 0.5f,	-0.5f,	0.0f,		1.0f,	1.0f,	1.0f,		1.0f, 0.0f, // bund højer
};

GLuint indices[] = { //WTF er dette

	0,	2,	1,  //top trekant
	0,	3,	2, //bund trekant
};

int main() {

	//init glfw
	glfwInit();

	//fortæller glfw hvilke verion den skal bruge
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//specifere indstillinger, af et vindue
	GLFWwindow* window = glfwCreateWindow(800, 800, "Render", NULL, NULL);

	//hvis window ikke kan laves, returnere den fejl.. i stedet for at fortsætte, og crashe.
	if (window == NULL) {
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Fortæller Context at lave "window"
	glfwMakeContextCurrent(window);

	//init openGL
	gladLoadGL();

	//Fortæller glad, hvormeget den stal tegne på.
	glViewport(0, 0, 800, 800);

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	//Binder VBO, til VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));


	//unbind for ikke at ændre i unødvendige ting, ved fejl.
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	//Textures

	int width, hight, numColCh;

	stbi_set_flip_vertically_on_load(true); //vender billede, der stbi loader nedefra, og ikke oppefra.

	//loader billedet i en characther værdi
	unsigned char* bytes = stbi_load("blyat.png", &width, &hight, &numColCh, 0);

	//Indexer billedet, og aktivere det
	GLuint texture;
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //LINEAR blander pixels, NEAREST holder pixels orginalt.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, hight, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(bytes);
	glBindTexture(GL_TEXTURE_2D, 0);

	GLuint tex0 = glGetUniformLocation(shaderProgram.ID, "tex0");
	shaderProgram.Activate();
	glUniform1i(tex0, 0);

	//Fortæller glfw at den skal updatere events, når de er klar. MAIN while
	while (!glfwWindowShouldClose(window)) {

		//tegner baggrunds farve
		glClearColor(0.01f, 0.13f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//fortæller openGL hvilke shader der er i brug
		shaderProgram.Activate();


		glUniform1f(uniID, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texture);

		//binder shaderen, så den bliver brugt
		VAO1.Bind();

		//tegner trekanterne     hvor mange         index af indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		//Skifer usynlige, og synlige buffers
		glfwSwapBuffers(window);

		//Pooler events up, så alt er tegnet inden det bliver vist
		glfwPollEvents();
	}

	//fjerner alt unødvendige data, der er blevet forarbejdet, eller binded

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	glDeleteTextures(1, &texture);
	shaderProgram.Delete();

	//lukker vinduet
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}