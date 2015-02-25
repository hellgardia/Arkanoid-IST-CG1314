#ifndef __GREENBLOCK_H__
#define __GREENBLOCK_H__

#include <stdlib.h>
#include <GL/glut.h>
#include "Block.h"

class GreenBlock : public Block{


public:
	
	GreenBlock(float x, float y, float z) : Block(x,y,z) {}
	~GreenBlock(){}


	void drawBlock();
};

#endif
