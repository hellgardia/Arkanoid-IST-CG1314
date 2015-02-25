#ifndef __PERSPECTIVE_H__
#define __PERSPECTIVE_H__

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "Camera.h"
#include "Ship.h"

class Perspective : public Camera{


public:
	Perspective(float eX,float eY, float eZ, float cX, float cY, float cZ) : Camera(eX, eY, eZ, cX, cY, cZ){}
	~Perspective();

	void displayCamera(GLsizei w, GLsizei h);
	void displayCamera(GLsizei w, GLsizei h, float x, float y, int camera);
		void displayCamera(GLsizei w, GLsizei h, float x, float y, float xangle, float yangle, int camera);
	void update(Ship s);

};


#endif