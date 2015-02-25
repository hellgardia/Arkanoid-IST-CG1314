#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <stdlib.h>
#include <gl/glut.h>

class Camera{
public:
	Camera();
	Camera(float eX,float eY, float eZ, float cX, float cY, float cZ);
	virtual void displayCamera(GLsizei w, GLsizei h) = 0;
	virtual void displayCamera(GLsizei w, GLsizei h, float x, float y, int camera) = 0;
	virtual void displayCamera(GLsizei w, GLsizei h, float x, float y, float xangle, float yangle, int camera) = 0;	
	~Camera(){}

protected:
	float eyeX;
	float eyeY;
	float eyeZ;
	float centerX;
	float centerY;
	float centerZ;



};

#endif