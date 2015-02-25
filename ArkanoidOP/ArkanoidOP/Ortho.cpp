#include "Ortho.h"

void Ortho::displayCamera(GLsizei w, GLsizei h){

	GLfloat aspect_ratio = w/h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glOrtho(-20.0f, 20.0f, -20.0f / aspect_ratio, 20.0f / aspect_ratio, -20.0f, 20.0f);
	else
		glOrtho(-20.0f * aspect_ratio, 20.0f * aspect_ratio, -20.0f, 20.0f, -20.0f, 20.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}