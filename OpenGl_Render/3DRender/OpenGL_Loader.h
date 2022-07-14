#pragma once
#include "Vertex.h"
#include "vector"
#include <glad/glad.h>

/*
tells OpenGL to work with verteiciesand the elements, returns them as DrawDetails.
Basicly makes a matrix where VAO is rows and VBO and EBO is colums.
Feeds data to OpenGL libary, that handles drawing
*/
static DrawDetails UploadMesh(const std::vector<Vertex>& verts, const std::vector<uint32_t>elem) {

	//prevents empty uploads to gpu
	if (verts.empty() || elem.empty())
		throw("No vectors here!");

	uint32_t VAO, VBO, EBO;

	//Vertex Aray Object
	glGenVertexArrays(1, &VAO); //assigns VAO as num 1
	glBindVertexArray(VAO); // bind = work with selected vertex array

	//Vertex Buffer Object
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//sends data to gpu          number of verts * memory of verts           draw verts static.. not gonna change data once uploaded
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(Vertex), verts.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, pos));
	glEnableVertexAttribArray(false);

	//Element Buffer Object  AKA Vertex Indexes
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ARRAY_BUFFER, EBO);
	glBufferData(GL_ARRAY_BUFFER, elem.size() * sizeof(uint32_t), elem.data(), GL_STATIC_DRAW);

	glBindVertexArray(false);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	return DrawDetails(VAO, elem.size());
}

static void UnloadMesh(std::vector<DrawDetails>& details) {
	for (auto& d : details) {
		glDeleteBuffers(1, &d.VAO);
	}
	details.clear();
}