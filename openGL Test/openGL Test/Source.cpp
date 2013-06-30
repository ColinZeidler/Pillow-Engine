#include <GL/glew.h>

#ifdef __APPLE__
#include <GLUT/glut.h> //allows crossplatform with apple
#else
#include <GL/glut.h>
#endif

void renderScene(void);

int main(int argc, char **argv) {

	//init glut and create window
	glutInit(&argc, argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1280, 720);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); //color mode(rgb, rgba) | BUffer mode (single or double) | more buffers
	glutCreateWindow("openGL Test");

	// callback for rendering
	glutDisplayFunc(renderScene);

	//begin event processing cycle
	glutMainLoop();

	return 1;
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
		glVertex3f(0.0,0.5,0.0);
	glEnd();

	glutSwapBuffers();
}