#ifndef __BALL_H__
#define __BALL_H__

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

class Ball{
	float posx [10];
	float posy [10];
	float X;
	float Y;
	float Z;
	float dir_x;
	float dir_y;
	int dir;
	int HP;
	bool isInShip;


	public:

	Ball();
	~Ball(){}

	int getHP();

	float getX();
	float getY();
	float getZ();
	int getDir();
	bool getIsInShip();

	void setX(float newX);
	void setY(float newY);

	void drawBall();
	void move(float constant);
	void moveUp(float step);
	void moveDown(float step);
	void moveRight(float step);
	void moveLeft(float step);
};

#endif