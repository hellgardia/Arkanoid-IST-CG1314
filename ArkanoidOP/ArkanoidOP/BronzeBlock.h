#ifndef __BRONZEBLOCK_H__
#define __BRONZEBLOCK_H__

#include <stdlib.h>
#include <GL/glut.h>
#include "Block.h"

class BronzeBlock : public Block{


public:
	
	BronzeBlock(float x, float y, float z) : Block(x,y,z) {}
	~BronzeBlock(){}


	void drawBlock();
};

#endif
