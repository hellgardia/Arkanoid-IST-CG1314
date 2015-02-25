#ifndef __LAUNCHER_H__
#define __LAUNCHER_H__

#include <stdlib.h>
#include "GameManager.h"
#include <GL/glut.h>

void myReshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay(void) {
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (-1, -1);
	glutCreateWindow("ARKANOID OP 2014");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glEnd();
	glFlush();
}


#endif