#include "Ball.h"

Ball::Ball(){	
	X=0.0f; Y=0.0f; Z=0.0f; HP = 3;
	isInShip = true;
	dir = 0;
}

float Ball::getX(){
	return X;
}

float Ball::getY(){
	return Y;
}


float Ball::getZ(){
	return Z;
}

bool Ball::getIsInShip(){
	return isInShip;
}

void Ball::setX(float newX){
	X = newX;
}

void Ball::setY(float newY){
	Y = newY;
}

void Ball::moveUp(float step){
	Y = Y+step;
}

void Ball::moveDown(float step){
	Y = Y-step;
}

void Ball::moveRight(float step){
	X = X+step;
}

void Ball::moveLeft(float step){
	X = X-step;
}



void Ball::drawBall(){ 
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
				glMaterialf(GL_FRONT, GL_SHININESS, 0.6 * 128.0);
				glPushMatrix();
			glTranslatef(X,Y,Z);
			glutSolidSphere(0.25,20,20);
		glPopMatrix();
		glPopMatrix();
		glFlush();

}

