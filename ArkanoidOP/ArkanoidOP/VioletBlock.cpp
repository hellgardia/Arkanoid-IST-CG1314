#include "VioletBlock.h"
#include <stdlib.h>
#include <stdio.h>


void VioletBlock::drawBlock(){
	glColor3f(0.62f, 0.20f, 0.8f);
	glPushMatrix();
		glTranslatef(blockX, blockY, blockZ);
		glScalef(1.60f,0.90f,0.50f);
		glutSolidCube(1);
	glPopMatrix();
	glFlush();

}



