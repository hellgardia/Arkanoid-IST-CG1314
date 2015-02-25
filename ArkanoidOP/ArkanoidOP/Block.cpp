#include "Block.h"

Block::Block(float x, float y, float z){	
	blockX = x;
	blockY = y;
	blockZ = z;
	_alive = true;
}

float Block::getX(){
	return blockX;
}

float Block::getY(){
	return blockY;
}


bool Block::alive(){
	return _alive;
}

void Block::kill(){
	_alive = false;
	
}

