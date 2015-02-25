#ifndef __WHITEBLOCK_H__
#define __WHITEBLOCK_H__

#include <stdlib.h>
#include <GL/glut.h>
#include "Block.h"

class WhiteBlock : public Block{


public:
	
	WhiteBlock(float x, float y, float z) : Block(x,y,z) {}
	~WhiteBlock(){}


	void drawBlock();
};

#endif
