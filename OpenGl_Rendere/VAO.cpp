#include "VAO.h"

VAO::VAO() {

	glGenVertexArrays(1, &ID);
}

//offset fort�ller hvorn�r RGB v�rdier begynder, og hvor XYZ v�rdier slutter i bytes
void VAO :: LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) { //variabler

	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset); // udfylder variabler
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void VAO::Bind() {

	glBindVertexArray(ID);
}

void VAO::Unbind() {

	glBindVertexArray(0);
}

void VAO::Delete() {

	glDeleteVertexArrays(1, &ID);
}