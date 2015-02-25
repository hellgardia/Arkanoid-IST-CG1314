#ifndef __SHIP_H__
#define __SHIP_H__

#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>

class Ship{
	int HP;
	int _points;
	bool _alive;
	float X;
	float Y;
	float Z;


	public:

	Ship();
	~Ship(){}

	int getHP();
	int getPoints();

	float getX();
	float getY();
	float getZ();

	float getLeftX();
	float getRightX();

	void setHP(int newHP);
	void kill();
	void drawSpaceship();
	void moveleft();
	void moveright();
	void addPoints(int points);
};

#endif