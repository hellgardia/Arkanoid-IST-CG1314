#ifndef __YELLOWBLOCK_H__
#define __YELLOWBLOCK_H__

#include <stdlib.h>
#include <GL/glut.h>
#include "Block.h"

class YellowBlock : public Block{


public:
	
	YellowBlock(float x, float y, float z) : Block(x,y,z) {}
	~YellowBlock(){}


	void drawBlock();
};

#endif
