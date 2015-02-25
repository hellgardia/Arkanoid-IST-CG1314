#ifndef __BLUEBLOCK_H__
#define __BLUEBLOCK_H__

#include <stdlib.h>
#include <GL/glut.h>
#include "Block.h"

class BlueBlock : public Block{


public:
	
	BlueBlock(float x, float y, float z) : Block(x,y,z) {}
	~BlueBlock(){}


	void drawBlock();
};

#endif
