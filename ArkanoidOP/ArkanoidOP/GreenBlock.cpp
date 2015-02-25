#include "GreenBlock.h"
#include <stdlib.h>
#include <stdio.h>

void GreenBlock::drawBlock(){
	GLfloat mat[4];
	glPushMatrix();
			mat[0] = 0.0;
			mat[1] = 0.3;
			mat[2] = 0.0;
			mat[3] = 1.0;
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
			mat[0] = 0.1;
			mat[1] = 0.35;
			mat[2] = 0.1;
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
			mat[0] = 0.45;
			mat[1] = 0.55;
			mat[2] = 0.45;
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




