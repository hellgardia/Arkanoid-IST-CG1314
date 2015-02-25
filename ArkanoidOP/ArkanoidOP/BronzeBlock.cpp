#include "BronzeBlock.h"
#include <stdlib.h>
#include <stdio.h>

void BronzeBlock::drawBlock(){
	GLfloat mat[4];
	glPushMatrix();
			mat[0] = 0.2125;
			mat[1] = 0.1275;
			mat[2] = 0.054;
			mat[3] = 1.0;
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
			mat[0] = 0.714;
			mat[1] = 0.4284;
			mat[2] = 0.18144;
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
			mat[0] = 0.393548;
			mat[1] = 0.271906;
			mat[2] = 0.166721;
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
			glMaterialf(GL_FRONT, GL_SHININESS, 0.2*128.0);
		glPushMatrix();
		glTranslatef(blockX, blockY, blockZ);
		glScalef(1.60f,0.90f,0.50f);
		glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();
	glFlush();

}

