#version 330 core

//fort�ller programmet, hvor den skal finde vector kordinaterne. i GLfloat_verticies[]

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

out vec3 color;

out vec2 texCoord;

uniform float scale; //skalere trekanterne i uniform... 0.5 er 50% st�rre. OpenGL fjerner ubrugte variabler SMART!!

void main(){
	gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y  * scale, aPos.z + aPos.z * scale, 1.0);
	color = aColor;

	texCoord = aTex
}