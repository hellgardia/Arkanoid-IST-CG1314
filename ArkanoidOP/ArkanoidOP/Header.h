#ifndef __BLUE_BLOCK_H__
#define __BLUE_BLOCK_H__

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

class RedBlock{
	float blockX;
	float blockY;
	float blockZ;


public:
	
	RedBlock(float x, float y, float z);
	~RedBlock(){}


	void drawBlock();
};

#endif
