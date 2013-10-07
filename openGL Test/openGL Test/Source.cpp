#include <GL/glew.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "readOBJ.h"
#include <iostream>
#include <vector>

#ifdef __APPLE__
#include <GLUT/glut.h> //allows crossplatform with apple
#else
#include <GL/glut.h>
#endif

void renderScene(void);
void drawSnowMan(void);
void changeSize(int, int);
void normalKeys(unsigned char, int, int);
void pressKey(int, int, int);
void releaseKey(int, int, int);

void computePos(float);
void computeDir(float);

// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z=5.0f;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
float cameraHeight = 1.0f;

//Struct Definitions
struct models{
	std::vector<float> vertexs;
	std::vector<std::vector<int>> faces;
};

int main(int argc, char **argv) {

	//init glut and create window
	glutInit(&argc, argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(720, 720);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); //color mode(rgb, rgba) | BUffer mode (single or double) | more buffers
	glutCreateWindow("openGL Test");

	// callback for rendering
	glutDisplayFunc(renderScene);

	glutReshapeFunc(changeSize);

	glutIdleFunc(renderScene);
	glutKeyboardFunc(normalKeys);
	glutSpecialFunc(pressKey);

	
	// here are the new entries
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);
	
	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	//load tank
	struct models tank;
	read("C:\\Users\\Colin\\Pictures\\Game designs\\Tank2.obj", &tank);

	//begin event processing cycle
	glutMainLoop();

	return 1;
}

void renderScene(void) {

	if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	x, cameraHeight, z,
			x+lx, 1.0f+(0.5f*cameraHeight),  z+lz,
			0.0f, 1.0f,  0.0f);

        // Draw ground
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

        // Draw 36 SnowMen
	for(int i = -3; i < 3; i++)
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0,0,j * 10.0);
			drawSnowMan();
			glPopMatrix();
		}

	glutSwapBuffers();
}

void changeSize(int width, int height) {
	//prevent divide by zero when window is too short
	//you can't make a zero width window
	if (height == 0)
		height = 1;

	float ratio = 1.0* width / height;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, width, height);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,100);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void normalKeys(unsigned char key, int xx, int yy) {
	if (key == 27)	//excape is pressed
		exit(0);
	switch (key)
	{
	case '1':cameraHeight = 2.0f;break;
	case '2':cameraHeight = 4.0f;break;
	case '3':cameraHeight = 8.0f;break;
	case '4':cameraHeight = 10.0f;break;
	case '5':cameraHeight = 15.0f;break;
	case '6':cameraHeight = 20.0f;break;
	case '7':cameraHeight = 40.0f;break;
	case '8':cameraHeight = 60.0f;break;
	case '9':cameraHeight = 80.0f;break;
	case '0':cameraHeight = 100.0f;break;
	default:
		break;
	}
	std::cout << key <<std::endl;
}

void drawSnowMan() {

	glColor3f(1.0f, 1.0f, 1.0f);

// Draw Body
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);

// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);

// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

// Draw Nose
	glColor3f(1.0f, 0.5f , 0.5f);
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f,0.5f,10,2);
}

void computePos(float deltaMove) {
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) {
	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void pressKey(int key, int xx, int yy) {
	switch (key) {
		case GLUT_KEY_LEFT : deltaAngle = -0.01f; break;	
		case GLUT_KEY_RIGHT : deltaAngle = 0.01f; break;
		case GLUT_KEY_UP : deltaMove = 0.5f; break;
		case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
	}
}

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAngle = 0.0f;break;
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaMove = 0;break;
	}
}