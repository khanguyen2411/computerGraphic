#pragma once
#include "Angel.h"
#include "stdio.h"
#define NumPoints 36
typedef vec4 point4;
typedef vec4 color4;

class Cube{
protected:
	GLfloat R, G, B;
	int Index = 0;
	point4 points[NumPoints]; 
	color4 colors[NumPoints]; 
	vec3 normals[NumPoints];

	point4 vertices[8];
	color4 vertex_colors[8];

public:
	Cube(){}

	Cube(GLfloat r, GLfloat g, GLfloat b) {
		this->R = r;
		this->G = g;
		this->B = b;
	}

	void initVertices() {
		vertices[0] = point4(-0.5, -0.5, 0.5, 1.0);
		vertices[1] = point4(-0.5, 0.5, 0.5, 1.0);
		vertices[2] = point4(0.5, 0.5, 0.5, 1.0);
		vertices[3] = point4(0.5, -0.5, 0.5, 1.0);
		vertices[4] = point4(-0.5, -0.5, -0.5, 1.0);
		vertices[5] = point4(-0.5, 0.5, -0.5, 1.0);
		vertices[6] = point4(0.5, 0.5, -0.5, 1.0);
		vertices[7] = point4(0.5, -0.5, -0.5, 1.0);
	}

	void initVertexColor() {
		for (int i = 0; i < 8; i++) {
			vertex_colors[i] = color4(R, G, B, 1.0);
		}
	}

	void quad(int a, int b, int c, int d) {
		vec4 u = vertices[b] - vertices[a];
		vec4 v = vertices[c] - vertices[b];
		vec3 normal = normalize(cross(u, v));

		normals[Index] = normal; colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
		normals[Index] = normal; colors[Index] = vertex_colors[b]; points[Index] = vertices[b]; Index++;
		normals[Index] = normal; colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
		normals[Index] = normal; colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
		normals[Index] = normal; colors[Index] = vertex_colors[b]; points[Index] = vertices[c]; Index++;
		normals[Index] = normal; colors[Index] = vertex_colors[c]; points[Index] = vertices[d]; Index++;
	}

	void makeCube(void) {
		initVertices();
		initVertexColor();
		quad(1, 0, 3, 2);
		quad(2, 3, 7, 6);
		quad(3, 0, 4, 7);
		quad(6, 5, 1, 2);
		quad(4, 5, 6, 7);
		quad(5, 4, 0, 1);
	}

	point4* getPoints() {
		return points;
	}

	color4* getColors() {
		return colors;
	}

	vec3* getNormals() {
		return normals;
	}
};

