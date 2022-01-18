#pragma once
#include "Angel.h"
#include "stdio.h"
#define PrismaticPoints 24
typedef vec4 point4;
typedef vec4 color4;

class Prismatic{
private:
	GLfloat R, G, B;
	int index = 0;

	point4 vertices[6] = {
		vec4(0, 1, 0, 1),
		vec4(0, 1, 1, 1),
		vec4(1, 1, 0, 1),
		vec4(0, 0, 0, 1),
		vec4(0, 0, 1, 1),
		vec4(1, 0, 0, 1) 
	};

	color4 color;
	point4 points[PrismaticPoints];
	color4 colors[PrismaticPoints];
	vec3 normals[PrismaticPoints];

public:
	Prismatic(){}

	Prismatic(GLfloat r, GLfloat g, GLfloat b) {
		this->R = r;
		this->G = g;
		this->B = b;
		
	}

	void trip(int a, int b, int c) {
		vec4 u = vertices[b] - vertices[a];
		vec4 v = vertices[c] - vertices[b];
		vec3 normal = normalize(cross(u, v));

		normals[index] = normal;  points[index] = vertices[a]; colors[index] = color; index++;
		normals[index] = normal;  points[index] = vertices[b]; colors[index] = color; index++;
		normals[index] = normal;  points[index] = vertices[c]; colors[index] = color; index++;
	}

	void initPrismatic() {
		color = vec4(R, G, B, 1);
		trip(0, 1, 2);
		trip(0, 3, 1);
		trip(1, 3, 4);
		trip(1, 5, 2);
		trip(1, 4, 5);
		trip(0, 5, 2);
		trip(0, 3, 5);
		trip(3, 4, 5);
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

