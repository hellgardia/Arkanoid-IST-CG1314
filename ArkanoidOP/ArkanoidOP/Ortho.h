#ifndef __ORTHO_H__
#define __ORTHO_H__

#include <iostream>
#include <GL/glut.h>
#include "Camera.h"


class Ortho : public Camera{


public:
	Ortho(float eX,float eY, float eZ, float cX, float cY, float cZ) : Camera(eX, eY, eZ, cX, cY, cZ){}
	~Ortho();

	void displayCamera(GLsizei w, GLsizei h);
	void displayCamera(GLsizei w, GLsizei h, float x, float y, int camera){}
	void displayCamera(GLsizei w, GLsizei h, float x, float y, float xangle, float yangle, int camera){}
};


#endif
