#include "WhiteBlock.h"
#include <stdlib.h>
#include <stdio.h>


void WhiteBlock::drawBlock(){
	GLfloat mat[4];
	glPushMatrix();
			mat[0] = 1.0;
			mat[1] = 1.0;
			mat[2] = 1.0;
			mat[3] = 1.0;
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
			mat[0] = 0.55;
			mat[1] = 0.55;
			mat[2] = 0.55;
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
			mat[0] = 0.7;
			mat[1] = 0.7;
			mat[2] = 0.7;
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


//Using reflective materials
/*void WhiteBlock::drawBlock(){
	GLfloat mat[4];
	glPushMatrix();
			mat[0] = 1.0;
			mat[1] = 1.0;
			mat[2] = 1.0;
			mat[3] = 1.0;
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
			mat[0] = 0.55;
			mat[1] = 0.55;
			mat[2] = 0.55;
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
			mat[0] = 0.7;
			mat[1] = 0.7;
			mat[2] = 0.7;
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
			glMaterialf(GL_FRONT, GL_SHININESS, 0.25 * 128.0);
		glPushMatrix();
		glTranslatef(blockX, blockY, blockZ);
		glBegin(GL_QUADS);
		//top
		glNormal3f(-1/3, -1/3, 1/3);
				glVertex3f(-0.80, -0.45, 0.25); //A
		glNormal3f(-1/3, 1/3, 1/3);
				glVertex3f(-0.80, 0.45, 0.25); //B
		glNormal3f(1/3, 1/3, 1/3);
				glVertex3f(0.80, 0.45, 0.25); //C
		glNormal3f(1/3, -1/3, 1/3);
				glVertex3f(0.80, -0.45, 0.25); //D
		//bottom
		glNormal3f(-1/3, -1/3, -1/3);
				glVertex3f(-0.80, -0.45, -0.25); //E
		glNormal3f(-1/3, 1/3, -1/3);
				glVertex3f(-0.80, 0.45, -0.25); //F
		glNormal3f(1/3, 1/3, -1/3);
				glVertex3f(0.80, 0.45, -0.25); //G
		glNormal3f(1/3, -1/3, -1/3);
				glVertex3f(0.80, -0.45, -0.25); //H
		//front
		glNormal3f(-1/3, -1/3, 1/3);
				glVertex3f(-0.80, -0.45, 0.25); //A
		glNormal3f(1/3, -1/3, 1/3);
				glVertex3f(0.80, -0.45, 0.25); //D
		glNormal3f(1/3, -1/3, -1/3);
				glVertex3f(0.80, -0.45, -0.25); //H
		glNormal3f(-1/3, -1/3, -1/3);
				glVertex3f(-0.80, -0.45, -0.25); //E
		//back
		glNormal3f(-1/3, 1/3, 1/3);
				glVertex3f(-0.80, 0.45, 0.25); //A
		glNormal3f(1/3, 1/3, 1/3);
				glVertex3f(0.80, 0.45, 0.25); //D
		glNormal3f(1/3, 1/3, -1/3);
				glVertex3f(0.80, 0.45, -0.25); //H
		glNormal3f(-1/3, 1/3, -1/3);
				glVertex3f(-0.80, 0.45, -0.25); //E
		//left
		glNormal3f(-1/3, 1/3, 1/3);
				glVertex3f(-0.80, 0.45, 0.25); //A
		glNormal3f(-1/3, 1/3, 1/3);
				glVertex3f(-0.80, 0.45, 0.25); //B
		glNormal3f(-1/3, 1/3, -1/3);
				glVertex3f(-0.80, 0.45, -0.25); //F
		glNormal3f(-1/3, -1/3, -1/3);
				glVertex3f(-0.80, -0.45, -0.25); //E
		//right
		glNormal3f(1/3, 1/3, 1/3);
				glVertex3f(0.80, 0.45, 0.25); //A
		glNormal3f(1/3, 1/3, 1/3);
				glVertex3f(0.80, 0.45, 0.25); //B
		glNormal3f(1/3, 1/3, -1/3);
				glVertex3f(0.80, 0.45, -0.25); //F
		glNormal3f(1/3, -1/3, -1/3);
				glVertex3f(0.80, -0.45, -0.25); //E
		glEnd();
		glPopMatrix();
	glPopMatrix();
	glFlush();

}*/
