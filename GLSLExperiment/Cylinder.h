#pragma once
#include "Angel.h"
#include "stdio.h"
#define CylinderPoints 385
#define PI 3.1415927
typedef vec4 point4;
typedef vec4 color4;


class Cylinder
{
public:
	point4 cylinderPoints[385];
	color4 cylinderColors[385];
    vec3 cylinderNormal[385];

	GLfloat R, G, B;

public:
    Cylinder(){}

    Cylinder(GLfloat r, GLfloat g, GLfloat b) {
        this->R = r;
        this->G = g;
        this->B = b;
    }

    void initCylinder() {
        GLfloat radius1 = 0.5;
        GLfloat height = 1.0;
        GLfloat x = 0.0;
        GLfloat z= 0.0;
        GLfloat angle = 0.0;
        GLfloat angle_stepsize = 0.1;
        int i = 0, j = 0;

        vec4 vColor = vec4(R, G, B, 1.0);
        

        //vẽ mặt xung quanh
        angle = 0.0;
        while (angle < 2 * PI) {
            x = radius1 * cos(angle);
            z = radius1 * sin(angle);

            //check.push_back(vec4(x, height, y, 1));
            vec4 v1(x, height, z, 1);
            cylinderPoints[i++] = v1;
            cylinderColors[j++] = vColor;
            //check.push_back(vec4(x, 0, y, 1));
            vec4 v2(x, 0, z, 1);
            cylinderPoints[i++] = v2;
            cylinderColors[j++] = vColor;

            angle = angle + angle_stepsize;
        }

        //check.push_back(vec4(radius1, height, 0, 1));
        vec4 v1(radius1, height, 0, 1);
        cylinderPoints[i++] = v1;
        cylinderColors[j++] = vColor;

        //check.push_back(vec4(radius1, 0.0, 0.0, 1));
        vec4 v2(radius1, 0.0, 0.0, 1.0);
        cylinderPoints[i++] = v2;
        cylinderColors[j++] = vColor;

        cylinderPoints[i++] = vec4(0, height, 0, 1);
        cylinderColors[j++] = vColor;

        for (int k = 0; k < 128; k += 2) {
            cylinderPoints[i++] = cylinderPoints[k];
            cylinderColors[j++] = vColor;
            cylinderPoints[i++] = vec4(0, height, 0, 1);
            cylinderColors[j++] = vColor;
        }

        cylinderPoints[i++] = vec4(0, 0, 0, 1);
        cylinderColors[j++] = vColor;
        for (int k = 1; k <= 128; k += 2) {
            cylinderPoints[i++] = cylinderPoints[k];
            cylinderColors[j++] = vColor;
            cylinderPoints[i++] = vec4(0, 0, 0, 1);
            cylinderColors[j++] = vColor;
        }
        cylinderPoints[i++] = vec4(0, 0, 0, 1);
        cylinderColors[j++] = vColor;

        cylinderColors[0] = vColor;
        cylinderColors[1] = vColor;


        for (int i = 0; i < 385; i += 1) {
            int a = i, b = i + 1, c = i + 2;
            vec4 u = cylinderPoints[b] - cylinderPoints[a];
            vec4 v = cylinderPoints[c] - cylinderPoints[b];
            vec3 normal = normalize(cross(u, v));
            cylinderNormal[a] = normal;
            cylinderNormal[b] = normal;
            cylinderNormal[c] = normal;
        }
    }

    point4* getPoints() {
        return cylinderPoints;
    }

    color4* getColors() {
        return cylinderColors;
    }

    vec3* getNormals() {
        return cylinderNormal;
    }
};

