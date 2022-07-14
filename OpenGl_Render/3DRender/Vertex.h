#pragma once

struct Vertex {
//store x,y,z cords in an array
	float pos[3] = {0.f,0.f,0.f};

	Vertex(float x, float y, float z) {
		pos[0] = x;
		pos[0] = y;
		pos[0] = z;
	}
 };

struct DrawDetails {

	uint32_t VAO = 0; //vertex array object
	uint32_t numElements = 0; //nuumber of elemts
	DrawDetails(uint32_t v, uint32_t e) {
		VAO = v;
		numElements = e;
	}
};