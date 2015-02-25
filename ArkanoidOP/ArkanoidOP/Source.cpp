#include "BlueBlock.h"

BlueBlock::BlueBlock(float x, float y, float z){	
	blockX = x;
	blockY = y;
	blockZ = z;
}

void BlueBlock::drawBlock(){
	glColor3f(1.0f,0.0f,0.0f);
	glPushMatrix();
		glTranslatef(blockX, blockY, blockZ);
		glScalef(1.60f,0.70f,0.10f);
		glutSolidCube(1);
	glPopMatrix();
	glFlush();

}




