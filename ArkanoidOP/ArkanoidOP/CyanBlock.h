#ifndef __CYANBLOCK_H__
#define __CYANBLOCK_H__

#include <stdlib.h>
#include <GL/glut.h>
#include "Block.h"

class CyanBlock : public Block{


public:
	
	CyanBlock(float x, float y, float z) : Block(x,y,z) {}
	~CyanBlock(){}


	void drawBlock();
};

#endif
