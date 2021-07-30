#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 color;

uniform float scale; //skalere trekanterne i uniform... 0.5 er 50% st�rre. OpenGL fjerner ubrugte variabler SMART!!

void main(){
	gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y  * scale, aPos.z + aPos.z * scale, 1.0);
	color = aColor;
}