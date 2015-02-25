#include "OrangeBlock.h"
#include <stdlib.h>
#include <stdio.h>

void OrangeBlock::drawBlock(){
	GLfloat mat[3];
	glPushMatrix();
			glColor3f(1.0f,0.5f,0.0f);
			mat[0] = 0.19125;
			mat[1] = 0.18725;
			mat[2] = 0.11745;
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
			mat[0] = 0.396;
			mat[1] = 0.74151;
			mat[2] = 0.69102;
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
			mat[0] = 0.297254;
			mat[1] = 0.30829;
			mat[2] = 0.306678;
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
			glMaterialf(GL_FRONT, GL_SHININESS, 0.1 * 128.0);
		glPushMatrix();
		glTranslatef(blockX, blockY, blockZ);
		glScalef(1.60f,0.90f,0.50f);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
	glFlush();

}

