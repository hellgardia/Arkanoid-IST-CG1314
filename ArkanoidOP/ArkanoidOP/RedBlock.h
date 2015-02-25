#ifndef __REDBLOCK_H__
#define __REDBLOCK_H__

#include <stdlib.h>
#include <GL/glut.h>
#include "Block.h"

class RedBlock : public Block{


public:
	
	RedBlock(float x, float y, float z) : Block(x,y,z) {}
	~RedBlock(){}


	void drawBlock();
};

#endif
