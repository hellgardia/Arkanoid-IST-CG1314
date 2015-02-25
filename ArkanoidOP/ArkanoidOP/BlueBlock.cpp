#include "BlueBlock.h"
#include <stdlib.h>
#include <stdio.h>


void BlueBlock::drawBlock(){
	GLfloat mat[4];
	glPushMatrix();
	//glColor3f(0.0f,0.0f,1.0f);
			mat[0] = 0.0;
			mat[1] = 0.1;
			mat[2] = 0.06;
			mat[3] = 1.0;
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
			mat[0] = 0.0;
			mat[1] = 0.50980392;
			mat[2] = 0.50980392;
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
			mat[0] = 0.50196078;
			mat[1] = 0.50196078;
			mat[2] = 0.50196078;
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
			glMaterialf(GL_FRONT, GL_SHININESS, 0.25 * 128.0);
		glPushMatrix();
		glTranslatef(blockX, blockY, blockZ);
		glScalef(1.60f,0.90f,0.50f);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
	glFlush();

}




