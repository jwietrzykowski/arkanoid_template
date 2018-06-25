#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define NDEBUG
#include <GL/freeglut.h>

#include "Rectangle.h"
#include "Circle.h"

const int GAME_LOGIC_REFRESH_TIME = 10;

/* GLUT callback Handlers */
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 45, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void gameLogic(int value)
{
	if (value == 0)
	{

	}
	else
	{

	}

	glutTimerFunc(GAME_LOGIC_REFRESH_TIME, gameLogic, 1);
}

void idle()
{
	glutPostRedisplay();
}

void display()
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		/*paddle.Draw();
		ball.Draw();*/
	}
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key_pressed, int mouse_x, int mouse_y)
{
	if (key_pressed == 'a') {

	}
}

/* helper functions for settings options and parameters */
void initGLUTScene(const char* window_name)
{
	glutInitWindowSize(1200, 1000);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void setCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(GAME_LOGIC_REFRESH_TIME, gameLogic, 0);
}

void setObjectsPositions()
{
}

int main(int argc, char *argv[])
{
	srand(time(NULL));

	glutInit(&argc, argv);
	initGLUTScene("Arkanoid");

	setCallbackFunctions();
	setObjectsPositions();

	glutMainLoop();

	return 0;
}