#ifndef __ORANGEBLOCK_H__
#define __ORANGEBLOCK_H__

#include <stdlib.h>
#include <GL/glut.h>
#include "Block.h"

class OrangeBlock : public Block{


public:
	
	OrangeBlock(float x, float y, float z) : Block(x,y,z) {}
	~OrangeBlock(){}


	void drawBlock();
};

#endif
