#pragma once
#include "Angel.h"
#include "stdio.h"
#define SpherePoints 5110
typedef vec4 point4;
typedef vec4 color4;

class Sphere {
private:
	point4 spherePoints[5110];
	color4 sphereColors[5110];
    vec3 sphereNormal[5110];

	GLfloat R, G, B;

public:

    Sphere(){}

    Sphere(GLfloat r, GLfloat g, GLfloat b) {
        this->R = r;
        this->G = g;
        this->B = b;
    }

    void initSphere() {
        GLfloat c = M_PI / 180;
        GLfloat phir, phir5, theta, thetar;
        GLfloat radius = 0.5;
        GLfloat x, y, z;
        GLfloat angle = 5;

        //chạy từ vĩ tuyến cao nhất đến vĩ tuyến thấp nhất
        int e = 0;
        vec4 v(R, G, B, 1.0);
        for (float phi = -90 + angle; phi <= 90 - angle; phi += angle) {
            phir = c * phi;
            phir5 = c * (phi + angle);
            //với 1 vĩ tuyến thì tính các điểm theo đường kinh tuyến
            for (float theta = -180; theta <= 180; theta += angle) {
                thetar = c * theta;
                GLfloat x1 = radius * sin(thetar) * cos(phir);
                GLfloat z1 = radius * cos(thetar) * cos(phir);
                GLfloat y1 = radius * sin(phir);
                vec4 v1(x1, y1, z1, 1.0);
                spherePoints[e] = v1;
                sphereColors[e] = v;
                e++;

                GLfloat x2 = radius * sin(thetar) * cos(phir5);
                GLfloat z2 = radius * cos(thetar) * cos(phir5);
                GLfloat y2 = radius * sin(phir5);
                vec4 v2(x2, y2, z2, 1.0);
                spherePoints[e] = v2;
                sphereColors[e] = v;
                e++;
            }
        }

        for (int i = 0; i < 5110; i+=1) {
            int a = i, b = i + 1, c = i + 2;
            vec4 u = spherePoints[b] - spherePoints[a];
            vec4 v = spherePoints[c] - spherePoints[b];
            vec3 normal = normalize(cross(u, v));
            sphereNormal[a] = normal;
            sphereNormal[b] = normal;
            sphereNormal[c] = normal;
        }
    }

    point4* getPoints() {
        return spherePoints;
    }

    color4* getColors() {
        return sphereColors;
    }

    vec3* getNormals() {
        return sphereNormal;
    }
};


