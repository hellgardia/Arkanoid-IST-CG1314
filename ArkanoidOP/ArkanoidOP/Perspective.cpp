#include "Perspective.h"

void Perspective::displayCamera(GLsizei w, GLsizei h, float x , float y, int camera){
	GLfloat aspect_ratio = w/h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(115, aspect_ratio, 1.0, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
		gluLookAt(x,eyeY,eyeZ,x,centerY,centerZ,0.0,0.0,1.0);

	
}

void Perspective::displayCamera(GLsizei w, GLsizei h, float x , float y, float xangle, float yangle, int camera){
	GLfloat aspect_ratio = w/h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(115, aspect_ratio, 1.0, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	
		gluLookAt(x,eyeY,eyeZ,xangle,centerY,centerZ,0.0,0.0,1.0);

	
}

void Perspective::displayCamera(GLsizei w, GLsizei h){
	GLfloat aspect_ratio = w/h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(115, aspect_ratio, 1.0, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(eyeX,eyeY,eyeZ,centerX,centerY,centerZ,0.0,0.0,1.0);
}

