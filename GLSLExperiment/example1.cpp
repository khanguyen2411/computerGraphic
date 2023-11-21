//Chương trình vẽ 1 hình lập phương đơn vị theo mô hình lập trình OpenGL hiện đại

// Tác giả: Nguyễn Văn Trọng Khá (Tác giả tự code nhưng cô giáo bảo là đi copy :( 

#include "Angel.h"  /* Angel.h là file tự phát triển (tác giả Prof. Angel), có chứa cả khai báo includes glew và freeglut*/
#include "Cube.h"
#include "stdio.h"
#include "vector"
#include "math.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Prismatic.h"

using namespace std;
// remember to prototype
void generateGeometry(void);
void initGPUBuffers(void);
void shaderSetup(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void Timer(int);
void Timer2(int);
typedef vec4 point4;
typedef vec4 color4;
using namespace std;

//road cube
Cube roadCube = Cube(0.658, 0.662, 0.678);
point4 roadPoint[NumPoints];
color4 roadColor[NumPoints];
vec3 roadNormal[NumPoints];

//yellow cube
Cube yellowCube = Cube(0.933, 0.913, 0.247);
point4 yellowPoint[NumPoints];
color4 yellowColor[NumPoints];
vec3 yellowNormal[NumPoints];

//bin cube
Cube bodyTruckCube = Cube(0.698, 0.666, 0.639);
point4 bodyTruckPoint[NumPoints];
color4 bodyTruckColor[NumPoints];
vec3 bodyTruckNormal[NumPoints];

//line cube
Cube lineCube = Cube(1, 1, 1);
point4 linePoint[NumPoints];
color4 lineColor[NumPoints];
vec3 lineNormal[NumPoints];

//pavement cube
Cube pavementCube = Cube(0.792, 0.701, 0.568);
point4 pavementPoint[NumPoints];
color4 pavementColor[NumPoints];
vec3 pavementNormal[NumPoints];

//grass cube
Cube grassCube = Cube(0.572, 0.815, 0.313);
point4 grassPoint[NumPoints];
color4 grassColor[NumPoints];
vec3 grassNormal[NumPoints];

//brick cube
Cube brickCube = Cube(0.941, 0.898, 0.113);
point4 brickPoint[NumPoints];
color4 brickColor[NumPoints];
vec3 brickNormal[NumPoints];

//blue cube
Cube blueCube = Cube(0.188, 0.650, 0.839);
point4 bluePoint[NumPoints];
color4 blueColor[NumPoints];
vec3 blueNormal[NumPoints];

//bus body cube
Cube busBodyCube = Cube(0.815, 0.196, 0.019);
point4 busBodyPoint[NumPoints];
color4 busBodyColor[NumPoints];
vec3 busBodyNormal[NumPoints];

//car body cube
Cube carBodyCube = Cube(0.803, 0.039, 0.094);
point4 carBodyPoint[NumPoints];
color4 carBodyColor[NumPoints];
vec3 carBodyNormal[NumPoints];

//black cube
Cube blackCube = Cube(0.160, 0.160, 0.160);
point4 blackPoint[NumPoints];
color4 blackColor[NumPoints];
vec3 blackNormal[NumPoints];

// hair cube
Cube hairCube = Cube(0.156, 0.125, 0.125);
point4 hairPoint[NumPoints];
color4 hairColor[NumPoints];
vec3 hairNormal[NumPoints];

//skin cube
Cube skinCube = Cube(0.890, 0.729, 0.592);
point4 skinPoint[NumPoints];
color4 skinColor[NumPoints];
vec3 skinNormal[NumPoints];

//shirt cube
Cube shirtCube = Cube(0.509, 0.596, 0.729);
point4 shirtPoint[NumPoints];
color4 shirtColor[NumPoints];
vec3 shirtNormal[NumPoints];

//bus body cube
Cube carGlassCube = Cube(0.498, 0.019, 0.066);
point4 carGlassPoint[NumPoints];
color4 carGlassColor[NumPoints];
vec3 carGlassNormal[NumPoints];

//jacket cube
Cube jacketCube = Cube(0.098, 0.247, 0.258);
point4 jacketPoint[NumPoints];
color4 jacketColor[NumPoints];
vec3 jacketNormal[NumPoints];

//trouser cube
Cube trouserCube = Cube(0.690, 0.458, 0.372);
point4 trouserPoint[NumPoints];
color4 trouserColor[NumPoints];
vec3 trouserNormal[NumPoints];

//shoes cube
Cube shoesCube = Cube(0.811, 0.890, 0.933);
point4 shoesPoint[NumPoints];
color4 shoesColor[NumPoints];
vec3 shoesNormal[NumPoints];

//shoes cube
Cube brownCube = Cube(0.207, 0.133, 0.074);
point4 brownPoint[NumPoints];
color4 brownColor[NumPoints];
vec3 brownNormal[NumPoints];

//traffic light cylinder
Cylinder trafficLightCylinder = Cylinder(0.388, 0.388, 0.388);
point4 trafficLightCylinderPoint[CylinderPoints];
color4 trafficLightCylinderColor[CylinderPoints];
vec3 trafficLightCylinderNormal[CylinderPoints];

//black cylinder
Cylinder blackCylinder = Cylinder(0, 0, 0);
point4 blackCylinderPoint[CylinderPoints];
color4 blackCylinderColor[CylinderPoints];
vec3 blackCylinderNormal[CylinderPoints];

//white cylinder
Cylinder whiteCylinder = Cylinder(1, 1, 1);
point4 whiteCylinderPoint[CylinderPoints];
color4 whiteCylinderColor[CylinderPoints];
vec3 whiteCylinderNormal[CylinderPoints];

//yellow cylinder
Cylinder yellowCylinder = Cylinder(0.949, 0.913, 0);
point4 yellowCylinderPoint[CylinderPoints];
color4 yellowCylinderColor[CylinderPoints];
vec3 yellowCylinderNormal[CylinderPoints];

//red cylinder
Cylinder redCylinder = Cylinder(1, 0, 0);
point4 redCylinderPoint[CylinderPoints];
color4 redCylinderColor[CylinderPoints];
vec3 redCylinderNormal[CylinderPoints];

//green cylinder
Cylinder greenCylinder = Cylinder(0, 1, 0);
point4 greenCylinderPoint[CylinderPoints];
color4 greenCylinderColor[CylinderPoints];
vec3 greenCylinderNormal[CylinderPoints];

Cylinder trunkCylinder = Cylinder(0.380, 0.231, 0.086);
point4 trunkCylinderPoint[CylinderPoints];
color4 trunkCylinderColor[CylinderPoints];
vec3 trunkCylinderNormal[CylinderPoints];

Prismatic prismatic = Prismatic(0.803, 0.039, 0.094);
point4 prismaticPoint[PrismaticPoints];
color4 prismaticColor[PrismaticPoints];
vec3 prismaticNormal[PrismaticPoints];

//crown sphere
Sphere crownSphere = Sphere(0.047, 0.682, 0.356);
point4 crownSpherePoint[SpherePoints];
color4 crownSphereColor[SpherePoints];
vec3 crownSphereNormal[SpherePoints];

//control traffic light 1 1

GLuint program;

mat4 model_view;
GLuint loc_modelMatrix;

mat4 projection;
GLuint projection_loc;

mat4 view;
GLuint view_loc;

void pointerToArray(point4* points, color4* colors, vec3* normals, Cube cube) {
    vec4* p = cube.getPoints();
    vec4* c = cube.getColors();
    vec3* n = cube.getNormals();

    for (int i = 0; i < NumPoints; i++) {
        points[i] = p[i];
        colors[i] = c[i];
        normals[i] = n[i];
    }
}

void pointerToArray(point4* points, color4* colors, vec3* normals, Sphere sphere) {
    vec4* p = sphere.getPoints();
    vec4* c = sphere.getColors();
    vec3* n = sphere.getNormals();

    for (int i = 0; i < SpherePoints; i++) {
        points[i] = p[i];
        colors[i] = c[i];
        normals[i] = n[i];
    }
}

void pointerToArray(point4* points, color4* colors, vec3* normals, Cylinder cylinder) {
    vec4* p = cylinder.getPoints();
    vec4* c = cylinder.getColors();
    vec3* n = cylinder.getNormals();

    for (int i = 0; i < CylinderPoints; i++) {
        points[i] = p[i];
        colors[i] = c[i];
        normals[i] = n[i];
    }
}

void pointerToArray(point4* points, color4* colors, vec3* normals, Prismatic prismatic) {
    vec4* p = prismatic.getPoints();
    vec4* c = prismatic.getColors();
    vec3* n = prismatic.getNormals();

    for (int i = 0; i < PrismaticPoints; i++) {
        points[i] = p[i];
        colors[i] = c[i];
        normals[i] = n[i];
    }
}

void generateGeometry(void)
{
    carGlassCube.makeCube();
    pointerToArray(carGlassPoint, carGlassColor, carGlassNormal, carGlassCube);

    yellowCube.makeCube();
    pointerToArray(yellowPoint, yellowColor, yellowNormal, yellowCube);

    greenCylinder.initCylinder();
    pointerToArray(greenCylinderPoint, greenCylinderColor, greenCylinderNormal, greenCylinder);

    trunkCylinder.initCylinder();
    pointerToArray(trunkCylinderPoint, trunkCylinderColor, trunkCylinderNormal,trunkCylinder);

    redCylinder.initCylinder();
    pointerToArray(redCylinderPoint, redCylinderColor, redCylinderNormal,redCylinder);

    trafficLightCylinder.initCylinder();
    pointerToArray(trafficLightCylinderPoint, trafficLightCylinderColor, trafficLightCylinderNormal,trafficLightCylinder);;

    yellowCylinder.initCylinder();
    pointerToArray(yellowCylinderPoint, yellowCylinderColor, yellowCylinderNormal,yellowCylinder);

    blackCylinder.initCylinder();
    pointerToArray(blackCylinderPoint, blackCylinderColor, blackCylinderNormal, blackCylinder);

    whiteCylinder.initCylinder();
    pointerToArray(whiteCylinderPoint, whiteCylinderColor, whiteCylinderNormal, whiteCylinder);

    crownSphere.initSphere();
    pointerToArray(crownSpherePoint, crownSphereColor, crownSphereNormal,crownSphere);

    blackCube.makeCube();
    pointerToArray(blackPoint, blackColor, blackNormal, blackCube);

    busBodyCube.makeCube();
    pointerToArray(busBodyPoint, busBodyColor, busBodyNormal, busBodyCube);

    roadCube.makeCube();
    pointerToArray(roadPoint, roadColor, roadNormal, roadCube);

    lineCube.makeCube();
    pointerToArray(linePoint, lineColor, lineNormal, lineCube);

    pavementCube.makeCube();
    pointerToArray(pavementPoint, pavementColor, pavementNormal, pavementCube);

    grassCube.makeCube();
    pointerToArray(grassPoint, grassColor, grassNormal, grassCube);

    brickCube.makeCube();
    pointerToArray(brickPoint, brickColor, brickNormal, brickCube);

    blueCube.makeCube();
    pointerToArray(bluePoint, blueColor, blueNormal, blueCube);

    hairCube.makeCube();
    pointerToArray(hairPoint, hairColor, hairNormal, hairCube);

    skinCube.makeCube();
    pointerToArray(skinPoint, skinColor, skinNormal, skinCube);

    shirtCube.makeCube();
    pointerToArray(shirtPoint, shirtColor, shirtNormal, shirtCube);

    jacketCube.makeCube();
    pointerToArray(jacketPoint, jacketColor, jacketNormal, jacketCube);

    trouserCube.makeCube();
    pointerToArray(trouserPoint, trouserColor, trouserNormal, trouserCube);

    shoesCube.makeCube();
    pointerToArray(shoesPoint, shoesColor, shoesNormal, shoesCube);

    brownCube.makeCube();
    pointerToArray(brownPoint, brownColor, brownNormal, brownCube);

    bodyTruckCube.makeCube();
    pointerToArray(bodyTruckPoint, bodyTruckColor, bodyTruckNormal, bodyTruckCube);

    carBodyCube.makeCube();
    pointerToArray(carBodyPoint, carBodyColor, carBodyNormal, carBodyCube);

    prismatic.initPrismatic();
    pointerToArray(prismaticPoint, prismaticColor, prismaticNormal, prismatic);
}

GLuint vao;
GLuint buffer;

GLuint loc_vPosition;
GLuint loc_vColor;
GLuint loc_vNormal;

void puring(point4(&points)[NumPoints], color4(&colors)[NumPoints], vec3(&normals)[NumPoints]) {
    glBufferData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors) + sizeof(normals), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors), sizeof(normals), normals);

    glVertexAttribPointer(loc_vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(loc_vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points)));
    glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points) + sizeof(colors)));
}

void puring(point4(&points)[SpherePoints], color4(&colors)[SpherePoints], vec3(&normals)[SpherePoints]) {
    glBufferData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors) + sizeof(normals), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors), sizeof(normals), normals);

    glVertexAttribPointer(loc_vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(loc_vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(colors)));
    glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points) + sizeof(colors)));
   //material_shininess = 10;
    //glUniform1f(glGetUniformLocation(program, "Shininess"), material_shininess);
}

void puring(point4(&points)[CylinderPoints], color4(&colors)[CylinderPoints], vec3(&normals)[CylinderPoints]) {
    glBufferData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors) + sizeof(normals), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors), sizeof(normals), normals);

    glVertexAttribPointer(loc_vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(loc_vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(colors)));
    glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points) + sizeof(colors)));
}

void puring(point4(&points)[PrismaticPoints], color4(&colors)[PrismaticPoints], vec3(&normals)[PrismaticPoints]) {
    glBufferData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors) + sizeof(normals), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors), sizeof(normals), normals);

    glVertexAttribPointer(loc_vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(loc_vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(colors)));
    glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points) + sizeof(colors)));
}

void initGPUBuffers(void)
{
    // Tạo một VAO - vertex array object
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Tạo và khởi tạo một buffer object
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    //glBufferData(GL_ARRAY_BUFFER, sizeof(spherePoints) + sizeof(sphereColors), NULL, GL_STATIC_DRAW);
    //glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(spherePoints), spherePoints);
    //glBufferSubData(GL_ARRAY_BUFFER, sizeof(spherePoints), sizeof(sphereColors), sphereColors);
}

void shaderSetup(void)
{
    // Nạp các shader và sử dụng chương trình shader
    program = InitShader("vshader1.glsl", "fshader1.glsl");   // hàm InitShader khai báo trong Angel.h
    glUseProgram(program);

    // Khởi tạo thuộc tính vị trí đỉnh từ vertex shader
    loc_vPosition = glGetAttribLocation(program, "vPosition");
    glEnableVertexAttribArray(loc_vPosition);


    loc_vColor = glGetAttribLocation(program, "vColor");
    glEnableVertexAttribArray(loc_vColor);
    //glVertexAttribPointer(loc_vColor, 4, GL_FLOAT, GL_FALSE, sizeof(linePoint), BUFFER_OFFSET(sizeof(spherePoints)));

    loc_vNormal = glGetAttribLocation(program, "vNormal");
    glEnableVertexAttribArray(loc_vNormal);

    loc_modelMatrix = glGetUniformLocation(program, "modelMatrix");
    projection_loc = glGetUniformLocation(program, "projection");
    view_loc = glGetUniformLocation(program, "view");


    point4 light_position(0, 1, 1, 0.0);
    color4 light_ambient(0.1, 0.1, 0.1, 1.0);
    color4 light_diffuse(1, 1.0, 1.0, 1.0);
    color4 light_specular(1.0, 1.0, 1.0, 1.0);

    color4 material_ambient(0.5, 0.5, 0.5, 1.0);
    color4 material_diffuse(0.1, 0.1, 0.1, 1.0);
    color4 material_specular(0.5, 0.5, 0.5, 1.0);
    
    float material_shininess = 110;

    color4 ambient_product = light_ambient * material_ambient;
    color4 diffuse_product = light_diffuse * material_diffuse;
    color4 specular_product = light_specular * material_specular;

    glUniform4fv(glGetUniformLocation(program, "AmbientProduct"), 1, ambient_product);
    glUniform4fv(glGetUniformLocation(program, "DiffuseProduct"), 1, diffuse_product);
    glUniform4fv(glGetUniformLocation(program, "SpecularProduct"), 1, specular_product);
    glUniform4fv(glGetUniformLocation(program, "LightPosition"), 1, light_position);
    glUniform1f(glGetUniformLocation(program, "Shininess"), material_shininess);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glClearColor(1, 1, 1, 1.0);
    glClearColor(0.266, 0.537, 0.894, 1.0);        /* Thiết lập màu trắng là màu xóa màn hình*/
}

void flat() {
    puring(pavementPoint, pavementColor, pavementNormal);
    mat4 instance = Scale(2.0, 0.001, 2.0);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * instance);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_1_MarkingRight(mat4 line) {
    line = Translate(0.35, 0, 0) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0.17, 0, 0) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0.13, 0, 0) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0.13, 0, 0) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0.13, 0, 0) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_1_MarkingLeft(mat4 line) {
    line = Translate(-0.35, 0, 0) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(-0.17, 0, 0) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(-0.13, 0, 0) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(-0.13, 0, 0) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(-0.13, 0, 0) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_1_PassLineLeft(mat4 passLine) {
    passLine = Translate(-0.35, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, 0.065) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, 0.065) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, 0.065) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, -0.065) * Translate(-0.35, 0, 0) * Scale(0.2, 0.022, 0.025);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, -0.065) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, -0.065) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_1_PassLineRight(mat4 passLine) {
    passLine = Translate(0.35, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, 0.065) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, 0.065) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, 0.065) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, -0.065) * Translate(0.35, 0, 0) * Scale(0.2, 0.022, 0.025);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, -0.065) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0, 0, -0.065) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_1() {
    puring(roadPoint, roadColor, roadNormal);
    mat4 instance = Scale(2.0, 0.021, 0.5);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * instance);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 line;
    puring(linePoint, lineColor, lineNormal);
    line = Scale(0.1, 0.022, 0.015);
    road_1_MarkingRight(line);
    line = Scale(0.1, 0.022, 0.015);
    road_1_MarkingLeft(line);

    mat4 passLine;
    passLine = Scale(0.2, 0.022, 0.025);
    road_1_PassLineLeft(passLine);
    passLine = Scale(0.2, 0.022, 0.025);
    road_1_PassLineRight(passLine);
}

void road_2_MarkingRight(mat4 line) {
    line = Translate(0, 0, 0.35) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0, 0, 0.17) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0, 0, 0.13) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0, 0, 0.13) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0, 0, 0.13) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_2_MarkingLeft(mat4 line) {
    line = Translate(0, 0, -0.35) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0, 0, -0.17) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0, 0, -0.13) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0, 0, -0.13) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    line = Translate(0, 0, -0.13) * line;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * line);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_2_PassLineLeft(mat4 passLine) {
    passLine = Translate(0, 0, -0.35) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0.065, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0.065, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0.065, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(-0.065, 0, 0) * Translate(0, 0, -0.35) * Scale(0.025, 0.022, 0.2);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(-0.065, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(-0.065, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_2_PassLineRight(mat4 passLine) {
    passLine = Translate(0, 0, 0.35) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(-0.065, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(-0.065, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(-0.065, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0.065, 0, 0) * Translate(0, 0, 0.35) * Scale(0.025, 0.022, 0.2);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0.065, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    passLine = Translate(0.065, 0, 0) * passLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * passLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_2() {
    puring(roadPoint, roadColor, roadNormal);
    mat4 instance = Scale(0.5, 0.02, 2.0);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * instance);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 line;
    puring(linePoint, lineColor, lineNormal);
    line = Scale(0.015, 0.022, 0.1);
    road_2_MarkingRight(line);
    line = Scale(0.015, 0.022, 0.1);
    road_2_MarkingLeft(line);

    mat4 passLine;
    passLine = Scale(0.025, 0.022, 0.2);
    road_2_PassLineLeft(passLine);
    passLine = Scale(0.025, 0.022, 0.2);
    road_2_PassLineRight(passLine);
}

void grass() {
    puring(grassPoint, grassColor, grassNormal);
    mat4 grass = Translate(0.725, 0, 0.725) * Scale(0.55, 0.02, 0.55);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * grass);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    grass = Translate(-1.45, 0, 0) * grass;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * grass);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    grass = Translate(0, 0, -1.45) * grass;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * grass);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    grass = Translate(1.45, 0, 0) * grass;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * grass);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_1_Brick_Line(mat4 brickLine) {
    brickLine = Translate(-0.615, 0, 0.24) * brickLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * brickLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    brickLine = Translate(0, 0, -0.48) * brickLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * brickLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    brickLine = Translate(1.23, 0, 0) * brickLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * brickLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    brickLine = Translate(0, 0, 0.48) * brickLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * brickLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void road_2_Brick_Line(mat4 brickLine) {
    brickLine = Translate(0.24, 0, -0.625) * brickLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * brickLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    brickLine = Translate(-0.48, 0, 0) * brickLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * brickLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    brickLine = Translate(0, 0, 1.25) * brickLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * brickLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    brickLine = Translate(0.48, 0, 0) * brickLine;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, model_view * brickLine);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void brickLine() {
    puring(brickPoint, brickColor, brickNormal);
    mat4 brick = Scale(0.77, 0.022, 0.02);
    road_1_Brick_Line(brick);

    brick = Scale(0.02, 0.022, 0.75);
    road_2_Brick_Line(brick);
}

void bars(mat4 verticalBar, mat4 bus_model_view) {
    verticalBar = Translate(-0.05, 0, 0) * verticalBar;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * verticalBar);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    verticalBar = Translate(-0.05, 0, 0) * verticalBar;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * verticalBar);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    verticalBar = Translate(-0.05, 0, 0) * verticalBar;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * verticalBar);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    verticalBar = Translate(-0.05, 0, 0) * verticalBar;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * verticalBar);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    verticalBar = Translate(-0.05, 0, 0) * verticalBar;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * verticalBar);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    verticalBar = Translate(-0.045, 0, 0) * verticalBar;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * verticalBar);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void glasses(mat4 glass, mat4 bus_model_view) {
    puring(bluePoint, blueColor, blueNormal);
    glass = Translate(0, 0.095, 0.07) * glass;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * glass);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    glass = Translate(0, 0, -0.14) * glass;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * glass);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    glass = Translate(0.145, 0.095, 0) * Scale(0.002, 0.12, 0.15);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * glass);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    glass = Translate(-0.29, 0, 0) * glass;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * glass);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void fender(mat4 bus_model_view) {
    mat4 fender = Translate(0.15, -0.015, 0) * Scale(0.01, 0.04, 0.14);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(linePoint, lineColor, lineNormal);
    fender = Translate(0.16, -0.02, 0) * Scale(0.005, 0.01, 0.05);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0.15, 0.015, 0) * Scale(0.0025, 0.03, 0.0025);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, 0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, 0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, 0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, 0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, 0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, 0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, 0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, -0.08) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, -0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, -0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, -0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, -0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, -0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender = Translate(0, 0, -0.01) * fender;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * fender);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

}

void mirror(mat4 bus_model_view) {
    mat4 mirror = Translate(0.143, 0.1, 0.075) * Scale(0.005, 0.01, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * mirror);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mirror = Translate(0.143, 0.1, 0.09) * RotateY(-30) * Scale(0.005, 0.05, 0.015);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * mirror);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mirror = Translate(0.143, 0.1, -0.075) * Scale(0.005, 0.01, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * mirror);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mirror = Translate(0.143, 0.1, -0.09) * RotateY(30) * Scale(0.005, 0.05, 0.015);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * mirror);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void wheel(mat4 bus_model_view) {
    puring(blackCylinderPoint, blackCylinderColor, blackCylinderNormal);
    mat4 wheel = Translate(0.1, -0.035, 0.061) * RotateX(90) * Scale(0.05, 0.015, 0.05);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel = Translate(0, 0, -0.137) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel = Translate(-0.2, 0, 0) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel = Translate(0, 0, 0.137) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    puring(whiteCylinderPoint, whiteCylinderColor, whiteCylinderNormal);
    wheel = Translate(0.1, -0.035, 0.06105) * RotateX(90) * Scale(0.03, 0.015, 0.03);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel = Translate(0, 0, -0.13706) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel = Translate(-0.2, 0, 0) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel = Translate(0, 0, 0.13706) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
}

void light(mat4 bus_model_view) {
    puring(yellowCylinderPoint, yellowCylinderColor, yellowCylinderNormal);
    mat4 headlight = Translate(0.156, -0.02, 0.055) * RotateZ(90) * Scale(0.02, 0.02, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * headlight);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    headlight = Translate(0, 0, -0.11) * headlight;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * headlight);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
}

void plate(mat4 bus_model_view) {
    puring(linePoint, lineColor, lineNormal);
    mat4 plate = Translate(-0.15, -0.015, 0) * Scale(0.005, 0.02, 0.05);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * plate);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

GLfloat bus_1_wheel_rotate_Z = 0;
void tray(mat4 bus_model_view) {
    puring(blackPoint, blackColor, blackNormal);
    //base instance
    mat4 base_bar_1 = Scale(0.005, 0.03, 0.005);
    mat4 base_bar_2 = Scale(0.03, 0.005, 0.005);

    //left - front
    mat4 left_front_wheel = bus_model_view * Translate(0.1, -0.035, 0.074) * RotateZ(bus_1_wheel_rotate_Z) * Translate(-0.1, +0.035, -0.074);
    mat4 bar1 = Translate(0.1, -0.035, 0.074) * base_bar_1;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_front_wheel * bar1);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 bar2 = Translate(0.1, -0.035, 0.074) * base_bar_2;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_front_wheel * bar2);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);


    //right front
    mat4 right_front_wheel = bus_model_view * Translate(0.1, -0.035, -0.074) * RotateZ(bus_1_wheel_rotate_Z) * Translate(-0.1, 0.035, 0.074);
    bar1 = Translate(0.1, -0.035, -0.074) * base_bar_1;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_front_wheel * bar1);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    bar2 = Translate(0.1, -0.035, -0.074) * base_bar_2;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_front_wheel * bar2);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);


    //left back
    mat4 left_back_wheel = bus_model_view * Translate(-0.1, -0.035, 0.074) * RotateZ(bus_1_wheel_rotate_Z) * Translate(0.1, 0.035, -0.074);
    bar1 = Translate(-0.1, -0.035, 0.074) * base_bar_1;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_back_wheel * bar1);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    bar2 = Translate(-0.1, -0.035, 0.074) * base_bar_2;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_back_wheel * bar2);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    //right back
    mat4 right_back_wheel = bus_model_view * Translate(-0.1, -0.035, -0.074) * RotateZ(bus_1_wheel_rotate_Z) * Translate(0.1, 0.035, 0.074);
    bar1 = Translate(-0.1, -0.035, -0.074) * base_bar_1;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_back_wheel * bar1);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    bar2 = Translate(-0.1, -0.035, -0.074) * base_bar_2;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_back_wheel * bar2);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

GLfloat bus_rotate_y = 0;
GLfloat dx = 0, dy = 0, dz = 0;
GLfloat bus_translate_x = 0, ty = 0, bus_translate_z = 0;

void bus() {
    mat4 bus_model_view = model_view * Translate(bus_translate_x, 0, 0) * Translate(0, 0, bus_translate_z) * Translate(-0.85, 0.07, 0.13) * Translate(0.1, 0, 0) * RotateY(bus_rotate_y) * Translate(-0.1, 0, 0);
    puring(busBodyPoint, busBodyColor, busBodyNormal);
    mat4 body = Scale(0.3, 0.07, 0.15);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * body);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 verticalBarLeft = Translate(0.1475, 0.095, 0.0725) * Scale(0.005, 0.12, 0.005);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * verticalBarLeft);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
    bars(verticalBarLeft, bus_model_view);

    mat4 verticalBarRight = Translate(0, 0, -0.145) * verticalBarLeft;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * verticalBarRight);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
    bars(verticalBarRight, bus_model_view);

    mat4 ceiling = Translate(0, 0.16, 0) * Scale(0.3, 0.02, 0.15);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * ceiling);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(blackPoint, blackColor, blackNormal);
    mat4 ceiling1 = Translate(0, 0.17, 0) * Scale(0.28, 0.02, 0.13);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, bus_model_view * ceiling1);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    fender(bus_model_view);

    puring(bluePoint, blueColor, blueNormal);
    mat4 glass = Scale(0.3, 0.12, 0.002);
    glasses(glass, bus_model_view);

    puring(blackPoint, blackColor, blackNormal);
    mirror(bus_model_view);
    wheel(bus_model_view);
    light(bus_model_view);
    plate(bus_model_view);
    tray(bus_model_view);
}

void banhxe(mat4 truck_model_view) {
    puring(blackCylinderPoint, blackCylinderColor, blackCylinderNormal);
    mat4 banhxe = Translate(0.9, -0.035, 0.261) * RotateX(90) * Scale(0.05, 0.015, 0.05);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * banhxe);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
       
        
    banhxe = Translate(0, 0, -0.137) * banhxe;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * banhxe);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
       
      
    banhxe = Translate(0.25, 0, 0) * banhxe;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * banhxe);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
        
        
    banhxe = Translate(0, 0, 0.137) * banhxe;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * banhxe);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
       
       
    puring(whiteCylinderPoint, whiteCylinderColor, whiteCylinderNormal);
    banhxe = Translate(0.9, -0.035, 0.26105) * RotateX(90) * Scale(0.03, 0.015, 0.03);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * banhxe);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
        
        
    banhxe = Translate(0, 0, -0.13706) * banhxe;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * banhxe);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
        
        
    banhxe = Translate(0.25, 0, 0) * banhxe;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * banhxe);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
       
        
    banhxe = Translate(0, 0, 0.13706) * banhxe;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * banhxe);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
}

void guong_xe(mat4 truck_model_view) {
    //gong guong trai
    puring(blackPoint, blackColor, blackNormal);
    mat4 guong = Translate(0.856, 0.04, 0.275) * Scale(0.005, 0.01, 0.02) * RotateX(90);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * guong);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    //guong trai
    guong = Translate(0.856, 0.04, 0.29) * RotateY(30) * Scale(0.005, 0.05, 0.015);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * guong);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
    
    //gong guong phai
    guong = Translate(0.856, 0.04, 0.125) * Scale(0.005, 0.01, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * guong);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    //guong phai
    guong = Translate(0.856, 0.04, 0.11) * RotateY(-30) * Scale(0.005, 0.05, 0.015);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * guong);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void kinh_xe(mat4 truck_model_view) {
    //x la mong lai, y la thay doi chieu cao, z dai sang 2 ben
    puring(bluePoint, blueColor, blueNormal);
    mat4 kinhdau = Translate(0.849, 0.059, 0.1995) * Scale(0.001, 0.06, 0.138);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * kinhdau);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    //x la chieu dai y la chieu cao
    mat4 kinhbenphai = Translate(0.9, 0.065, 0.2718) * Scale(0.08, 0.05, 0.007);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * kinhbenphai);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 kinhbentrai = Translate(0.9, 0.065, 0.128) * Scale(0.08, 0.05, 0.007);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * kinhbentrai);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

}

void den_xe(mat4 truck_model_view) {
    puring(yellowCylinderPoint, yellowCylinderColor, yellowCylinderNormal);
    mat4 den = Translate(0.8685, -0.02, 0.16) * RotateZ(90) * Scale(0.02, 0.02, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * den);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    den = Translate(0, 0, 0.08) * den;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * den);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
    
    puring(yellowCylinderPoint, yellowCylinderColor, yellowCylinderNormal);
    mat4 densau = Translate(1.1912, -0.02, 0.16) * RotateZ(90) * Scale(0.02, 0.02, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * densau);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    densau = Translate(0, 0, 0.08) * densau;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * densau);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
}

GLfloat truck_translate_x = 0;
void truck() {
    puring(bodyTruckPoint, bodyTruckColor, bodyTruckNormal);
    mat4 truck_model_view = model_view * Translate(truck_translate_x, 0, 0) * Translate(0.05, 0.075, -0.325);
    mat4 than_xe = Scale(0.25, 0.2, 0.15) * Translate(4.3, 0.325, 1.335);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * than_xe);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(blackPoint, blackColor, blackNormal);
    mat4 dau_xe = Scale(0.1, 0.15, 0.15) * Translate(8.99, 0.25, 1.335) ;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, truck_model_view * dau_xe);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
    
    banhxe(truck_model_view);
    guong_xe(truck_model_view);
    kinh_xe(truck_model_view);
    den_xe(truck_model_view);
}

GLfloat car_translate_x = 0, car_translate_y = 0, car_translate_z = 0;
void car() {
    mat4 car_model_view = model_view * Translate(0, 0, car_translate_z) * Translate(-0.12, 0.05, -1) * RotateY(-90);
    puring(carBodyPoint, carBodyColor, carBodyNormal);
    mat4 body = Scale(0.25, 0.05, 0.12);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * body);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(bluePoint, blueColor, blueNormal);
    mat4 mirror = RotateZ(27) * Translate(0.05, 0.03, 0) * Scale(0.01, 0.07, 0.11);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * mirror);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(carBodyPoint, carBodyColor, carBodyNormal);
    mat4 mirror_border = RotateZ(27) * Translate(0.05, 0.03, 0) * Scale(0.009, 0.08, 0.12);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * mirror_border);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(carGlassPoint, carGlassColor, carGlassNormal);
    mat4 glass = Translate(0.035, 0.03, 0.065) * RotateY(-30) * Scale(0.005, 0.022, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * glass);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    glass = Translate(0.035, 0.03, -0.065) * RotateY(30) * Scale(0.005, 0.022, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * glass);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(bluePoint, blueColor, blueNormal);
    mat4 glass_mirror = Translate(0.0345, 0.029, 0.065) * RotateY(-30) * Scale(0.0048, 0.016, 0.018);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * glass_mirror);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
    glass_mirror = Translate(0.0345, 0.029, -0.065) * RotateY(30) * Scale(0.0048, 0.016, 0.018);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * glass_mirror);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(yellowCylinderPoint, yellowCylinderColor, yellowCylinderNormal);
    //left light
    mat4 light = Translate(0.13, -0.01, 0.04) * RotateZ(90) * Scale(0.02, 0.02, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * light);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
    //right light
    light = Translate(0, 0, -0.08) * light;

    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * light);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    //plate
    puring(linePoint, lineColor, lineNormal);
    mat4 plate = Translate(-0.126, -0.01, 0) * Scale(0.005, 0.02, 0.05);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * plate);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    //capo
    puring(prismaticPoint, prismaticColor, prismaticNormal);
    mat4 capo = RotateY(90) * RotateZ(90) * Translate(0.025, -0.06, 0.04) * Scale(0.015, 0.12, 0.085);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * capo);
    glDrawArrays(GL_TRIANGLES, 0, PrismaticPoints);

    mat4 capo2 = RotateY(-90) * RotateZ(90) * Translate(0.025, -0.06, 0.07) * Scale(0.015, 0.12, 0.05);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * capo2);
    glDrawArrays(GL_TRIANGLES, 0, PrismaticPoints);

    //chairs
    puring(blackPoint, blackColor, blackNormal);
    mat4 chairs = RotateZ(-90) * Translate(-0.025, 0, -0.0015) * Scale(0.009, 0.15, 0.11);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * chairs);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    //driver head
    puring(skinPoint, skinColor, skinNormal);
    mat4 driver_head = Translate(-0.005, 0.04, -0.035) * Scale(0.02, 0.02, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * driver_head);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(yellowPoint, yellowColor, yellowNormal);
    mat4 driver_hair = Translate(-0.0045, 0.05, -0.035) * Scale(0.025, 0.01, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * driver_hair);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    //front wheel
    puring(blackCylinderPoint, blackCylinderColor, blackCylinderNormal);
    mat4 wheel = Translate(0.08, -0.02, 0.0475) * RotateX(90) * Scale(0.04, 0.015, 0.04);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    mat4 wheel2 = Translate(0, 0, -0.108) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * wheel2);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel = Translate(-0.18, 0, 0) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel2 = Translate(0, 0, -0.108) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * wheel2);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    puring(whiteCylinderPoint, whiteCylinderColor, whiteCylinderNormal);
    wheel = Translate(0.08, -0.02, 0.0477) * RotateX(90) * Scale(0.02, 0.015, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel2 = Translate(0, 0, -0.11) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * wheel2);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel = Translate(-0.18, 0, 0) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * wheel);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    wheel2 = Translate(0, 0, -0.11) * wheel;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, car_model_view * wheel2);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
}

bool traffic_light_1[3] = { true, false, false };
bool traffic_light_2[3] = { false, false, true };
GLfloat traffic_light_1_timer[3] = { 0.0, 0.0, 0.0 };
GLfloat traffic_light_2_timer[3] = { 0.0, 0.0, 0.0 };

void trafficLight(bool(&control)[3], mat4 position) {
    mat4 traffic_light_model_view = model_view * position;

    puring(trafficLightCylinderPoint, trafficLightCylinderColor, trafficLightCylinderNormal);
    mat4 vertical_bar = Translate(-0.28, 0, 0.28) * Scale(0.01, 0.4, 0.01);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, traffic_light_model_view * vertical_bar);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    mat4 horizonal_bar = Translate(-0.28, 0.4, 0.08) * RotateX(90) * Scale(0.01, 0.2, 0.01);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, traffic_light_model_view * horizonal_bar);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    puring(blackPoint, blackColor, blackNormal);
    mat4 lightCube = Translate(-0.28, 0.4, 0.1) * Scale(0.025, 0.03, 0.08);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, traffic_light_model_view * lightCube);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 redLight = Translate(-0.275, 0.4, 0.074) * RotateZ(90) * Scale(0.02, 0.02, 0.02);
    if (control[0]) {
        puring(redCylinderPoint, redCylinderColor, redCylinderNormal);
        glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, traffic_light_model_view * redLight);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
    }
    else {
        puring(trafficLightCylinderPoint, trafficLightCylinderColor, trafficLightCylinderNormal);
        glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, traffic_light_model_view * redLight);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
    }
    

    mat4 yellowLight = Translate(0, 0, 0.025) * redLight;
    if (control[1]) {
        puring(yellowCylinderPoint, yellowCylinderColor, yellowCylinderNormal);
        glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, traffic_light_model_view * yellowLight);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
    }
    else {
        puring(trafficLightCylinderPoint, trafficLightCylinderColor, trafficLightCylinderNormal);
        glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, traffic_light_model_view * yellowLight);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
    }
    
    mat4 greenLight = Translate(0, 0, 0.025) * yellowLight;
    if (control[2]) {
        puring(greenCylinderPoint, greenCylinderColor, greenCylinderNormal);
        glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, traffic_light_model_view * greenLight);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
    }
    else {
        puring(trafficLightCylinderPoint, trafficLightCylinderColor, trafficLightCylinderNormal);
        glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, traffic_light_model_view * greenLight);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);
    }
}

void traffic() {
    mat4 traffic_light_model_view;
    trafficLight(traffic_light_1, traffic_light_model_view);

    traffic_light_model_view = traffic_light_model_view * RotateY(180);
    trafficLight(traffic_light_1, traffic_light_model_view);

    traffic_light_model_view = traffic_light_model_view * RotateY(90);
    trafficLight(traffic_light_2, traffic_light_model_view);

    traffic_light_model_view = traffic_light_model_view * RotateY(-180);
    trafficLight(traffic_light_2, traffic_light_model_view);
}

GLfloat human_1_right_leg_rotate = 0;
GLfloat human_1_left_leg_rotate = 0;
GLfloat human_1_translate = 0, human_1_rotate = 0, human_1_translate_x = 0;

GLfloat human_2_right_leg_rotate = 0;
GLfloat human_2_left_leg_rotate = 0;
GLfloat human_2_translate = 0, human_2_rotate = 0, human_2_translate_x = 0;

//projection - view
GLfloat l = -0.5, r = 0.5;
GLfloat bottom = -0.5, top = 0.5;
GLfloat zNear = -0.5, zFar = 1;


void human_1() {
    puring(skinPoint, skinColor, skinNormal);
    mat4 human_model_view = model_view * Translate(-1.0, 0, -0.35) * RotateY(-90) * Translate(human_1_translate_x, 0.025, human_1_translate) * RotateY(human_1_rotate) ;
    mat4 head = Translate(0, 0.15, 0) * Scale(0.04, 0.04, 0.04);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * head);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(hairPoint, hairColor, hairNormal);
    mat4 hair = Translate(0, 0.1775, 0) * Scale(0.04, 0.015, 0.04);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * hair);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(shirtPoint, shirtColor, shirtNormal);
    mat4 shirt = Translate(0, 0.095, 0) * Scale(0.02, 0.07, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * shirt);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(jacketPoint, jacketColor, jacketNormal);
    mat4 jacket = Translate(-0.015, 0.095, 0) * Scale(0.01, 0.07, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * jacket);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    jacket = Translate(0.03, 0, 0) * jacket;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * jacket);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 left_arm_model_view = human_model_view * Translate(-0.025, 0.135, 0) * RotateX(human_1_right_leg_rotate) * Translate(0.025, -0.135, 0);
    mat4 arm_left = Translate(-0.025, 0.1, 0) * Scale(0.015, 0.06, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_arm_model_view * arm_left);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 right_arm_model_view = human_model_view * Translate(0.025, 0.135, 0) * RotateX(human_1_left_leg_rotate) * Translate(-0.025, -0.135, 0);
    mat4 arm_right = Translate(0.025, 0.1, 0) * Scale(0.015, 0.06, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_arm_model_view * arm_right);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(skinPoint, skinColor, skinNormal);
    mat4 right_hand_model_view = human_model_view * Translate(0.025, 0.135, 0) * RotateX(human_1_left_leg_rotate) * Translate(-0.025, -0.135, 0);
    mat4 right_hand = Translate(0.025, 0.065, 0) * Scale(0.015, 0.01, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_hand_model_view * right_hand);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 left_hand_model_view = human_model_view * Translate(-0.025, 0.135, 0) * RotateX(human_1_right_leg_rotate) * Translate(0.025, -0.135, 0);
    mat4 left_hand = Translate(-0.025, 0.065, 0) * Scale(0.015, 0.01, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_hand_model_view * left_hand);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(trouserPoint, trouserColor, trouserNormal);

    mat4 right_leg_model_view = human_model_view * Translate(0.01, 0.06, 0) * RotateX(human_1_right_leg_rotate) * Translate(-0.01, -0.06, 0);
    mat4 right_leg = Translate(0.01, 0.03, 0) * Scale(0.02, 0.06, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_leg_model_view * right_leg);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 left_leg_model_view = human_model_view * Translate(-0.01, 0.06, 0) * RotateX(human_1_left_leg_rotate) * Translate(0.01, -0.06, 0);
    mat4 left_leg = Translate(-0.01, 0.03, 0) * Scale(0.02, 0.06, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_leg_model_view * left_leg);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(shoesPoint, shoesColor, shoesNormal);
    mat4 left_shoe_model_view = human_model_view * Translate(-0.01, 0.06, 0) * RotateX(human_1_left_leg_rotate) * Translate(0.01, -0.06, 0);
    mat4 left_shoe = Translate(-0.01, -0.0075, 0) * Scale(0.02, 0.015, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_shoe_model_view * left_shoe);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 right_shoe_model_view = human_model_view * Translate(0.01, 0.06, 0) * RotateX(human_1_right_leg_rotate) * Translate(-0.01, -0.06, 0);
    mat4 right_shoe = Translate(0.01, -0.0075, 0) * Scale(0.02, 0.015, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_shoe_model_view * right_shoe);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(brownPoint, brownColor, brownNormal);
    mat4 brownEye = Translate(0.0075, 0.155, -0.02) * Scale(0.005, 0.005, 0.005);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * brownEye);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    brownEye = Translate(-0.015, 0, 0) * brownEye;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * brownEye);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(linePoint, lineColor, lineNormal);
    mat4 whiteEye = Translate(-0.005, 0, 0) * brownEye;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * whiteEye);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    whiteEye = Translate(0.025, 0, 0) * whiteEye;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * whiteEye);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(hairPoint, hairColor, hairNormal);
    mat4 mouth = Translate(0, 0.14, -0.02) * Scale(0.01, 0.005, 0.005);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * mouth);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void human_2() {
    puring(skinPoint, skinColor, skinNormal);
    mat4 human_model_view = model_view * Translate(0.95, 0, 0.35) * RotateY(90) * Translate(human_2_translate_x, 0.025, human_2_translate) * RotateY(human_2_rotate);
    mat4 head = Translate(0, 0.15, 0) * Scale(0.04, 0.04, 0.04);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * head);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(hairPoint, hairColor, hairNormal);
    mat4 hair = Translate(0, 0.1775, 0) * Scale(0.04, 0.015, 0.04);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * hair);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(shirtPoint, shirtColor, shirtNormal);
    mat4 shirt = Translate(0, 0.095, 0) * Scale(0.02, 0.07, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * shirt);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(jacketPoint, jacketColor, jacketNormal);
    mat4 jacket = Translate(-0.015, 0.095, 0) * Scale(0.01, 0.07, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * jacket);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    jacket = Translate(0.03, 0, 0) * jacket;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * jacket);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 left_arm_model_view = human_model_view * Translate(-0.025, 0.135, 0) * RotateX(human_2_right_leg_rotate) * Translate(0.025, -0.135, 0);
    mat4 arm_left = Translate(-0.025, 0.1, 0) * Scale(0.015, 0.06, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_arm_model_view * arm_left);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 right_arm_model_view = human_model_view * Translate(0.025, 0.135, 0) * RotateX(human_2_left_leg_rotate) * Translate(-0.025, -0.135, 0);
    mat4 arm_right = Translate(0.025, 0.1, 0) * Scale(0.015, 0.06, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_arm_model_view * arm_right);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(skinPoint, skinColor, skinNormal);
    mat4 right_hand_model_view = human_model_view * Translate(0.025, 0.135, 0) * RotateX(human_2_left_leg_rotate) * Translate(-0.025, -0.135, 0);
    mat4 right_hand = Translate(0.025, 0.065, 0) * Scale(0.015, 0.01, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_hand_model_view * right_hand);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 left_hand_model_view = human_model_view * Translate(-0.025, 0.135, 0) * RotateX(human_2_right_leg_rotate) * Translate(0.025, -0.135, 0);
    mat4 left_hand = Translate(-0.025, 0.065, 0) * Scale(0.015, 0.01, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_hand_model_view * left_hand);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(trouserPoint, trouserColor, trouserNormal);

    mat4 right_leg_model_view = human_model_view * Translate(0.01, 0.06, 0) * RotateX(human_2_right_leg_rotate) * Translate(-0.01, -0.06, 0);
    mat4 right_leg = Translate(0.01, 0.03, 0) * Scale(0.02, 0.06, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_leg_model_view * right_leg);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 left_leg_model_view = human_model_view * Translate(-0.01, 0.06, 0) * RotateX(human_2_left_leg_rotate) * Translate(0.01, -0.06, 0);
    mat4 left_leg = Translate(-0.01, 0.03, 0) * Scale(0.02, 0.06, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_leg_model_view * left_leg);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(shoesPoint, shoesColor, shoesNormal);
    mat4 left_shoe_model_view = human_model_view * Translate(-0.01, 0.06, 0) * RotateX(human_2_left_leg_rotate) * Translate(0.01, -0.06, 0);
    mat4 left_shoe = Translate(-0.01, -0.0075, 0) * Scale(0.02, 0.015, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, left_shoe_model_view * left_shoe);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    mat4 right_shoe_model_view = human_model_view * Translate(0.01, 0.06, 0) * RotateX(human_2_right_leg_rotate) * Translate(-0.01, -0.06, 0);
    mat4 right_shoe = Translate(0.01, -0.0075, 0) * Scale(0.02, 0.015, 0.02);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, right_shoe_model_view * right_shoe);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(brownPoint, brownColor, brownNormal);
    mat4 brownEye = Translate(0.0075, 0.155, -0.02) * Scale(0.005, 0.005, 0.005);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * brownEye);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    brownEye = Translate(-0.015, 0, 0) * brownEye;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * brownEye);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(linePoint, lineColor, lineNormal);
    mat4 whiteEye = Translate(-0.005, 0, 0) * brownEye;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * whiteEye);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    whiteEye = Translate(0.025, 0, 0) * whiteEye;
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * whiteEye);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);

    puring(hairPoint, hairColor, hairNormal);
    mat4 mouth = Translate(0, 0.14, -0.02) * Scale(0.01, 0.005, 0.005);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, human_model_view * mouth);
    glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void tree(mat4 position) {
    puring(trunkCylinderPoint, trunkCylinderColor, trunkCylinderNormal);
    mat4 tree_model_view = model_view * position;
    mat4 trunk = Translate(0, 0.015, 0) * Scale(0.01, 0.03, 0.01);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, tree_model_view * trunk);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    puring(crownSpherePoint, crownSphereColor, crownSphereNormal);
    mat4 crown = Translate(0, 0.065, 0) * Scale(0.05, 0.07, 0.05);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, tree_model_view * crown);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, SpherePoints);

    GLfloat x = 0.1;
    for (int i = 0; i < 4; i++) {
        puring(trunkCylinderPoint, trunkCylinderColor, trunkCylinderNormal);
        trunk = Translate(x, 0, 0) * trunk;
        glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, tree_model_view * trunk);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

        puring(crownSpherePoint, crownSphereColor, crownSphereNormal);
        crown = Translate(x, 0, 0) * crown;
        glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, tree_model_view * crown);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, SpherePoints);
    }

    puring(trunkCylinderPoint, trunkCylinderColor, trunkCylinderNormal);
    trunk = Translate(0, 0.015, 0.1) * Scale(0.01, 0.03, 0.01);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, tree_model_view * trunk);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

    puring(crownSpherePoint, crownSphereColor, crownSphereNormal);
    crown = Translate(0, 0.065, 0.1) * Scale(0.05, 0.07, 0.05);
    glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, tree_model_view * crown);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, SpherePoints);

    GLfloat z = 0.1;
    for (int i = 0; i < 3; i++) {
        puring(trunkCylinderPoint, trunkCylinderColor, trunkCylinderNormal);
        trunk = Translate(0, 0, z) * trunk;
        glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, tree_model_view * trunk);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, CylinderPoints);

        puring(crownSpherePoint, crownSphereColor, crownSphereNormal);
        crown = Translate(0, 0, z) * crown;
        glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, tree_model_view * crown);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, SpherePoints);
    }

}
void scene() {
    flat();
    road_2();
    road_1();
    grass();
    brickLine();
    mat4 position = Translate(0.56, 0, 0.56);
    tree(position);

    position = Translate(0.56, 0, -0.56) * RotateY(90);
    tree(position);

    position = Translate(-0.56, 0, 0.56) * RotateY(-90);
    tree(position);

    position = Translate(-0.56, 0, -0.56) * RotateY(180);
    tree(position);
}

GLfloat radius = 1, theta = 0, phi = 0;
const GLfloat dr = 5.0 * DegreesToRadians;

bool car_disabled = false, human_2_disabled = false, human_1_disabled = false;
bool truck_disabled = false, bus_disabled = false;
GLfloat eyeX = 3.0, eyeY = 2, eyeZ = -2.5;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    model_view = RotateX(dx) * RotateY(dy) * RotateZ(dz);
    scene();
    human_1();
    human_2();
    bus();
    truck();
    car();
    traffic();


    vec4 eye(eyeX, eyeY, eyeZ, 1);
    vec4 at(0, 0, 0, 1);
    vec4 up(0, 1, 0, 1);

    view = LookAt(eye, at, up);
    glUniformMatrix4fv(view_loc, 1, GL_TRUE, view);

    projection = Frustum(-0.5, 0.5, -0.5, 0.5, 2, 10);
    glUniformMatrix4fv(projection_loc, 1, GL_TRUE, projection);

    //glViewport(0, 0, width, height);
    glutSwapBuffers();
}


void reshape(int width, int height)
{
    
}

bool mode_1 = false, mode_2 = false;

void keyboard(unsigned char key, int x, int y)
{
    // keyboard handler

    switch (key) {
    case 033:			// 033 is Escape key octal value
        exit(1);		// quit program
        break;

    case 'x':
        dx += 5;
        glutPostRedisplay();
        break;

    case 'y':
        dy += 5;
        glutPostRedisplay();
        break;

    case 'z':
        dz += 5;
        glutPostRedisplay();
        break;

    case 'w':
        eyeY += 0.1;
        glutPostRedisplay();
        break;

    case 's':
        eyeY -= 0.1;
        glutPostRedisplay();
        break;

    case 'a':
        eyeX += 0.1;
        glutPostRedisplay();
        break;

    case 'd':
        eyeX -= 0.1;
        glutPostRedisplay();
        break;

    case 'q':
        eyeZ += 0.1;
        glutPostRedisplay();
        break;

    case 'e':
        eyeZ -= 0.1;
        glutPostRedisplay();
        break;
 
    case '2': {
        mode_2 = true;
        traffic_light_1[0] = true;
        traffic_light_1[1] = false;
        traffic_light_1[2] = false;

        traffic_light_2[0] = false;
        traffic_light_2[1] = false;
        traffic_light_2[2] = true;

        for (int i = 0; i < 2; i++) {
            traffic_light_1_timer[i] = 0;
            traffic_light_2_timer[i] = 0;
        }
        Timer2(0);
        break;
    }
        
    case 'p': {
        mode_1 = false;
        
        if (mode_2) {
            mode_2 = false;
        }
        else {
            mode_2 = true;
        }
        break;
    }   

    }
}


GLfloat t_1 = 0, t_2 = 0;
void Timer(int value) {
    //control traffic light on the road 1
    if (traffic_light_1[0]) {
        traffic_light_1_timer[0] += 0.009;

        if (traffic_light_1_timer[0] >= 4) {
            traffic_light_1[0] = false;
            traffic_light_1[1] = false;
            traffic_light_1[2] = true;

            traffic_light_1_timer[0] = 0;
        }
    }
    else {
        if (traffic_light_1[2]) {
            traffic_light_1_timer[2] += 0.01;

            if (traffic_light_1_timer[2] >= 3.5) {
                traffic_light_1[0] = false;
                traffic_light_1[1] = true;
                traffic_light_1[2] = false;

                traffic_light_1_timer[2] = 0;
            }
        }
        else {
            if (traffic_light_1[1]) {
                traffic_light_1_timer[1] += 0.01;

                if (traffic_light_1_timer[1] >= 0.5) {
                    traffic_light_1[0] = true;
                    traffic_light_1[1] = false;
                    traffic_light_1[2] = false;

                    traffic_light_1_timer[1] = 0;
                }
            }
        }
    }

    //control traffic light on the road 2
    if (traffic_light_2[2]) {
        traffic_light_2_timer[2] += 0.009;

        if (traffic_light_2_timer[2] >= 3.5) {
            traffic_light_2[0] = false;
            traffic_light_2[1] = true;
            traffic_light_2[2] = false;

            traffic_light_2_timer[2] = 0;
        }
    }
    else {
        if (traffic_light_2[1]) {
            traffic_light_2_timer[1] += 0.009;

            if (traffic_light_2_timer[1] >= 0.5) {
                traffic_light_2[0] = true;
                traffic_light_2[1] = false;
                traffic_light_2[2] = false;

                traffic_light_2_timer[1] = 0;
            }
        }
        else {
            if (traffic_light_2[0]) {
                traffic_light_2_timer[0] += 0.01;

                if (traffic_light_2_timer[0] >= 4) {
                    traffic_light_2[0] = false;
                    traffic_light_2[1] = false;
                    traffic_light_2[2] = true;

                    traffic_light_2_timer[0] = 0;
                }
            }
        }
    }

    //control bus 1
    if (!bus_disabled) {
        if (!traffic_light_1[0] || bus_translate_x < 0.23 || bus_translate_x > 0.62) {
            bus_1_wheel_rotate_Z -= 15;
            if (bus_translate_x < 0.62) {
                bus_translate_x += 0.009;
            }
            
            if (bus_rotate_y > -90 && bus_translate_x > 0.62) {
                bus_rotate_y -= 3;
                bus_translate_z += 0.008;
            }

            if (bus_rotate_y <= -90) {
                bus_translate_z += 0.01;
                if (bus_translate_z >= 1.4) {
                    bus_rotate_y = 0;
                    bus_translate_x = -0.4;
                    bus_translate_z = 0;
                    bus_disabled = true;
                }
            }
        }

        if (bus_1_wheel_rotate_Z <= -360) {
            bus_1_wheel_rotate_Z = 0;
        }
    }

    //control human 1
    if (!human_1_disabled) {
        if (human_1_translate > -0.65) {
            human_1_translate -= 0.0025;
        }
        else {
            if (human_1_rotate > -90) {
                human_1_rotate -= 3;
            }
            else {
                if ((traffic_light_1[0] && traffic_light_1_timer[0] <= 2) || human_1_translate_x > 0.5) {

                    human_1_translate_x += 0.0025;
                    if (human_1_translate_x >= 1.4) {
                        human_1_rotate = 0;
                        human_1_translate = 0;
                        human_1_translate_x = 0;
                        human_1_disabled = true;
                    }
                }
            }
        }

        if ((!traffic_light_1[0] && human_1_translate <= -0.65)) {
            human_1_right_leg_rotate = 0;
            human_1_left_leg_rotate = 0;
            if (human_1_translate_x > 0.5) {
                human_1_right_leg_rotate = 25 * cos(2 * PI * t_1 + PI / 2);
                human_1_left_leg_rotate = -human_1_right_leg_rotate;
                t_1 = t_1 + 0.03;
                if (t_1 >= 1) {
                    t_1 == 0;
                }
            }
        }
        else {
            if ((traffic_light_1[0] && human_1_translate <= -0.65 && traffic_light_1_timer[0] > 2)) {
                if (human_1_translate_x < 0.1) {
                    human_1_right_leg_rotate = 0;
                    human_1_left_leg_rotate = 0;
                }
                else {
                    human_1_right_leg_rotate = 25 * cos(2 * PI * t_1 + PI / 2);
                    human_1_left_leg_rotate = -human_1_right_leg_rotate;
                    t_1 = t_1 + 0.03;
                    if (t_1 >= 1) {
                        t_1 == 0;
                    }
                }
            }
            else {
                human_1_right_leg_rotate = 25 * cos(2 * PI * t_1 + PI / 2);
                human_1_left_leg_rotate = -human_1_right_leg_rotate;
                t_1 = t_1 + 0.03;
                if (t_1 >= 1) {
                    t_1 == 0;
                }
            }
        }
    }

    //control human 2
    if (!human_2_disabled) {
        if (human_2_translate > -0.6) {
            human_2_translate -= 0.0025;
            human_2_right_leg_rotate = 25 * cos(2 * PI * t_2 + PI / 2);
            human_2_left_leg_rotate = -human_2_right_leg_rotate;
            t_2 = t_2 + 0.03;
            if (t_2 >= 1) {
                t_2 == 0;
            }
        }
        else {
            if (human_2_rotate < 90) {
                human_2_rotate += 3;
                human_2_right_leg_rotate = 0;
                human_2_left_leg_rotate = 0;
            }
            else {
                human_2_translate_x -= 0.0025;
                human_2_right_leg_rotate = 25 * cos(2 * PI * t_2 + PI / 2);
                human_2_left_leg_rotate = -human_2_right_leg_rotate;
                t_2 = t_2 + 0.03;
                if (t_2 >= 1) {
                    t_2 == 0;
                }
            }

            if (human_2_translate_x <= -0.8) {
                human_2_rotate = 0;
                human_2_translate = 0;
                human_2_translate_x = 0;
                human_2_disabled = true;
            }
        }
    }

    //control car
    if ((!traffic_light_2[0] || car_translate_z < 0.4 || car_translate_z > 0.6) && !car_disabled) {
        car_translate_z += 0.012;
    }

    if (car_translate_z >= 2.1) {
        car_translate_z = 0;
        car_disabled = true;
    }

    //controll truck
    if (!truck_disabled) {
        if (!traffic_light_1[0] || truck_translate_x >= -0.4 || car_translate_z <= -0.6) {
            truck_translate_x -= 0.01;
        }

        if (truck_translate_x <= -2) {
            truck_translate_x = 0;
            truck_disabled = true;
        }
    }
    
    if (mode_1) {
        glutTimerFunc(15, Timer, 0);
    }
    glutPostRedisplay();
}

void Timer2(int value) {
    if (mode_2) {
        //control traffic light on the road 1
        if (traffic_light_1[0]) {
            traffic_light_1_timer[0] += 0.009;

            if (traffic_light_1_timer[0] >= 4) {
                traffic_light_1[0] = false;
                traffic_light_1[1] = false;
                traffic_light_1[2] = true;

                traffic_light_1_timer[0] = 0;
            }
        }
        else {
            if (traffic_light_1[2]) {
                traffic_light_1_timer[2] += 0.01;

                if (traffic_light_1_timer[2] >= 3.5) {
                    traffic_light_1[0] = false;
                    traffic_light_1[1] = true;
                    traffic_light_1[2] = false;

                    traffic_light_1_timer[2] = 0;
                }
            }
            else {
                if (traffic_light_1[1]) {
                    traffic_light_1_timer[1] += 0.01;

                    if (traffic_light_1_timer[1] >= 0.5) {
                        traffic_light_1[0] = true;
                        traffic_light_1[1] = false;
                        traffic_light_1[2] = false;

                        traffic_light_1_timer[1] = 0;
                    }
                }
            }
        }

        //control traffic light on the road 2
        if (traffic_light_2[2]) {
            traffic_light_2_timer[2] += 0.009;

            if (traffic_light_2_timer[2] >= 3.5) {
                traffic_light_2[0] = false;
                traffic_light_2[1] = true;
                traffic_light_2[2] = false;

                traffic_light_2_timer[2] = 0;
            }
        }
        else {
            if (traffic_light_2[1]) {
                traffic_light_2_timer[1] += 0.009;

                if (traffic_light_2_timer[1] >= 0.5) {
                    traffic_light_2[0] = true;
                    traffic_light_2[1] = false;
                    traffic_light_2[2] = false;

                    traffic_light_2_timer[1] = 0;
                }
            }
            else {
                if (traffic_light_2[0]) {
                    traffic_light_2_timer[0] += 0.01;

                    if (traffic_light_2_timer[0] >= 4) {
                        traffic_light_2[0] = false;
                        traffic_light_2[1] = false;
                        traffic_light_2[2] = true;

                        traffic_light_2_timer[0] = 0;
                    }
                }
            }
        }

        //control bus 1
        if (!traffic_light_1[0] || bus_translate_x < 0.23 || bus_translate_x > 0.62) {
            bus_1_wheel_rotate_Z -= 15;
            if (bus_translate_x < 0.62) {
                bus_translate_x += 0.01;
            }

            if (bus_rotate_y > -90 && bus_translate_x > 0.62) {
                bus_rotate_y -= 3;
                bus_translate_z += 0.008;
            }

            if (bus_rotate_y <= -90) {
                bus_translate_z += 0.01;
                if (bus_translate_z >= 1.4) {
                    bus_rotate_y = 0;
                    bus_translate_x = -0.4;
                    bus_translate_z = 0;
                }
            }
        }

        if (bus_1_wheel_rotate_Z <= -360) {
            bus_1_wheel_rotate_Z = 0;
        }

        //control human 1
        if (human_1_translate > -0.65) {
            human_1_translate -= 0.0025;
        }
        else {
            if (human_1_rotate > -90) {
                human_1_rotate -= 3;
            }
            else {
                if ((traffic_light_1[0] && traffic_light_1_timer[0] <= 2) || human_1_translate_x > 0.5) {
                    human_1_translate_x += 0.0025;
                    if (human_1_translate_x >= 1.4) {
                        human_1_rotate = 0;
                        human_1_translate = -0.1;
                        human_1_translate_x = 0;
                    }
                }
            }
        }

        if ((!traffic_light_1[0] && human_1_translate <= -0.65)) {
            human_1_right_leg_rotate = 0;
            human_1_left_leg_rotate = 0;
            if (human_1_translate_x > 0.5) {
                human_1_right_leg_rotate = 25 * cos(2 * PI * t_1 + PI / 2);
                human_1_left_leg_rotate = -human_1_right_leg_rotate;
                t_1 = t_1 + 0.03;
                if (t_1 >= 1) {
                    t_1 == 0;
                }
            }
        }
        else {
            if ((traffic_light_1[0] && human_1_translate <= -0.65 && traffic_light_1_timer[0] > 2)) {
                if (human_1_translate_x < 0.1) {
                    human_1_right_leg_rotate = 0;
                    human_1_left_leg_rotate = 0;
                }
                else {
                    human_1_right_leg_rotate = 25 * cos(2 * PI * t_1 + PI / 2);
                    human_1_left_leg_rotate = -human_1_right_leg_rotate;
                    t_1 = t_1 + 0.03;
                    if (t_1 >= 1) {
                        t_1 == 0;
                    }
                }
            }
            else {
                human_1_right_leg_rotate = 25 * cos(2 * PI * t_1 + PI / 2);
                human_1_left_leg_rotate = -human_1_right_leg_rotate;
                t_1 = t_1 + 0.03;
                if (t_1 >= 1) {
                    t_1 == 0;
                }
            }
        }

        //control human 2
        if (human_2_translate > -0.6) {
            human_2_translate -= 0.0025;
            human_2_right_leg_rotate = 25 * cos(2 * PI * t_2 + PI / 2);
            human_2_left_leg_rotate = -human_2_right_leg_rotate;
            t_2 = t_2 + 0.03;
            if (t_2 >= 1) {
                t_2 == 0;
            }
        }
        else {
            if (human_2_rotate < 90) {
                human_2_rotate += 3;
                human_2_right_leg_rotate = 0;
                human_2_left_leg_rotate = 0;
            }
            else {
                human_2_translate_x -= 0.0025;
                human_2_right_leg_rotate = 25 * cos(2 * PI * t_2 + PI / 2);
                human_2_left_leg_rotate = -human_2_right_leg_rotate;
                t_2 = t_2 + 0.03;
                if (t_2 >= 1) {
                    t_2 == 0;
                }
            }

            if (human_2_translate_x <= -0.8) {
                human_2_rotate = 0;
                human_2_translate = 0;
                human_2_translate_x = 0;
            }
        }

        //control car
        if ((!traffic_light_2[0] || car_translate_z < 0.4 || car_translate_z > 0.6)) {
            car_translate_z += 0.011;
        }

        if (car_translate_z >= 2.7) {
            car_translate_z = 0;
        }

        //controll truck
        if (!traffic_light_1[0] || truck_translate_x >= -0.4 || car_translate_z <= -0.6) {
            truck_translate_x -= 0.01;
        }

        if (truck_translate_x <= -2) {
            truck_translate_x = 0;
        }

        glutTimerFunc(15, Timer2, 0);

    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    // main function: program starts here

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1080, 1080);
    //glutInitWindowSize(640, 640);
    glutInitWindowPosition(900, 0);
    glutCreateWindow("Drawing a Cube");

    glewInit();

    generateGeometry();
    initGPUBuffers();
    shaderSetup();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    //Timer(0);

    


    glutMainLoop();

    return 0;
}
