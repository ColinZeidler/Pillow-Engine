#include <GL/glew.h>

#ifdef __APPLE__
#include <GLUT/glut.h> //allows crossplatform with apple
#else
#include <GL/glut.h>
#endif

void renderScene(void);
void changeSize(int, int);
float angle = 0.0f;

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

	//begin event processing cycle
	glutMainLoop();

	return 1;
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//reset transformations
	glLoadIdentity();
	//set the camera
	gluLookAt(	0.0f, 0.0f, 10.0f,
				0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f);

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLES);
		glVertex3f(-2.0f,-2.0f, 0.0f);
		glVertex3f( 2.0f, 0.0f, 0.0);
		glVertex3f( 0.0f, 2.0f, 0.0);
	glEnd();

	angle +=0.5f;

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