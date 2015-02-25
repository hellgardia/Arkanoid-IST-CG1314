#include "RedBlock.h"
#include <stdlib.h>
#include <stdio.h>

void RedBlock::drawBlock(){
	GLfloat mat[4];
	glPushMatrix();
			mat[0] = 0.7;
			mat[1] = 0.00;
			mat[2] = 0.00;
			mat[3] = 1.0;
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
			mat[0] = 0.9;
			mat[1] = 0.4;
			mat[2] = 0.4;
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
			mat[0] = 0.9;
			mat[1] = 0.04;
			mat[2] = 0.04;
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
			glMaterialf(GL_FRONT, GL_SHININESS, 0.125 * 128.0);
		glPushMatrix();
		glTranslatef(blockX, blockY, blockZ);
		glScalef(1.60f,0.90f,0.50f);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
	glFlush();

}




