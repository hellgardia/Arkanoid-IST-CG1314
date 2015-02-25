#include "Boundaries.h"
#include <stdlib.h>
#include <stdio.h>

Boundaries::Boundaries(){}


void Boundaries::drawBounds(){
    GLfloat mat[4];
		glPushMatrix();
				mat[0] = 0.25;
				mat[1] = 0.25;
				mat[2] = 0.25;
				mat[3] = 1.0;
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
				mat[0] = 0.4;
				mat[1] = 0.4;
				mat[2] = 0.4;
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
				mat[0] = 0.774597;
				mat[1] = 0.774597;
				mat[2] = 0.774597;
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
				glMaterialf(GL_FRONT, GL_SHININESS, 0.16 * 128.0);
	glPushMatrix();
		glTranslatef(-19.5, -3.0f, 0.0f);
		glScalef(1.0f,44.0f,1.00f);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(+19.5, -3.0f, 0.0f);
		glScalef(1.0f,44.0f,1.00f);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0, 19.5f, 0.0f);
		glScalef(40.5f,1.0f,1.00f);
		glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glFlush();

}




