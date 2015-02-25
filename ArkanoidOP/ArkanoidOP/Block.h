#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "Material.h"


class Block{
protected:
	float blockX;
	float blockY;
	float blockZ;
	bool _alive;


public:
	
	Block(float x, float y, float z);
	~Block(){}


	virtual void drawBlock() = 0;

	
	bool alive();
	void kill();
	float getX();
	float getY();
};

#endif
