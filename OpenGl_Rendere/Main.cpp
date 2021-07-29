#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {

	//init glfw
	glfwInit();

	//fort�ller glfw hvilke verion den skal bruge
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//kordinater til alle vertices... trekanter og matematik. alle kordinater virker, s� l�nge det er mellem 1, og -1.
	GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
	};

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

	//Fort�ller GPU at behandle shader data med en vertex shader. Compiler data til MachineLangues, der GPU ikke taler menneske kode hehe.
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	//Fort�ller GPU at behandle shader data med en fragment shader.
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	
	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//Sender data i store pakker, igennem en buffer. Dette data skal "bind" s� det g�r vi her
	GLuint VAO, VBO;

	//VAO skal f�r VBO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	//Angiver farve
	glClearColor(0.61f, 0.07f, 0.12f, 1.0f);

	//Putter farven ind i back buffer
	glClear(GL_COLOR_BUFFER_BIT); 

	//bytter front og back buffer.
	glfwSwapBuffers(window); 

	//Fort�ller glfw at den skal updatere events, n�r de er klar.
	while(!glfwWindowShouldClose(window)) {

		//Tegner 2D primitiven
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}