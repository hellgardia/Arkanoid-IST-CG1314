#ifndef __VIOLETBLOCK_H__
#define __VIOLETBLOCK_H__

#include <stdlib.h>
#include <GL/glut.h>
#include "Block.h"

class VioletBlock : public Block{


public:
	
	VioletBlock(float x, float y, float z) : Block(x,y,z) {}
	~VioletBlock(){}


	void drawBlock();
};

#endif
