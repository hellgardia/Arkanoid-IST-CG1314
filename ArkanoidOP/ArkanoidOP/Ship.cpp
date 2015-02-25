#include "Ship.h"

Ship::Ship(){	
	HP = 3;
	X=0.0f; Y=-18.0f; Z=0.0f;
	_points = 0;
	_alive = true;
}


float Ship::getX(){
	return X;
}

float Ship::getY(){
	return Y;
}

float Ship::getZ(){
	return Z;
}

int Ship::getHP(){
	return HP;
}

void Ship::setHP(int newHP){
	HP = newHP;
}

float Ship::getLeftX(){
	return X - 2.4f;
}

float Ship::getRightX(){
	return X + 2.4f;
}

int Ship::getPoints(){
	return _points;
}

void Ship::addPoints(int points){
	_points = _points + points;
}



void Ship::moveleft(){ 
	if(X > -16.0 )
		X = X-1.0f;
}

void Ship::moveright(){ 
	if(X < 16.0 )
		X = X+1.0f;
}

void Ship::drawSpaceship(){
	GLfloat mat[4];
		glPushMatrix();
				//glColor3f(1.0f, 0.0f, 0.0f);
				mat[0] = 0.19225;
				mat[1] = 0.19225;
				mat[2] = 0.19225;
				mat[3] = 1.0;
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
				mat[0] = 0.50754;
				mat[1] = 0.50754;
				mat[2] =  0.50754;
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
				mat[0] = 0.508273;
				mat[1] = 0.508273;
				mat[2] = 0.508273;
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
				glMaterialf(GL_FRONT, GL_SHININESS, 0.4 * 128.0);
					glPushMatrix();
						glTranslatef(X,Y,0);
//_____________________________________________________________________________________________________________________
						glBegin(GL_QUADS); //face superior
						glNormal3f(-0.0273f,-0.156f, 0.46875f);
							glVertex3f(-1.00f, -0.25f, 0.50f); //B1
						glNormal3f(0.0273f, -0.156f, 0.46875f);
							glVertex3f(1.00f, -0.25f, 0.50f);  //C1
						glNormal3f(0.0273f, 0.156f, 0.46875f);
							glVertex3f(1.00f, 0.25, 0.50f);  //C8
						glNormal3f(-0.0273f,0.156f, 0.46875f);
							glVertex3f(-1.00f, 0.25f, 0.50f); //B8
						glEnd();
						glBegin(GL_QUADS); //face inferior
						glNormal3f(-0.0273f,-0.156f, -0.46875f);
							glVertex3f(-1.00f, -0.25f, -0.50f); //B4
						glNormal3f(0.0273f, -0.156f, -0.46875f);
							glVertex3f(1.00f, -0.25f, -0.50f);  //C4
						glNormal3f(0.0273f, 0.156f, -0.46875f);
							glVertex3f(1.00f, 0.25, -0.50f);  //C5
						glNormal3f(-0.0273f,0.156f, -0.46875f);
							glVertex3f(-1.00f, 0.25f, -0.50f); //B5
						glEnd();
//_____________________________________________________________________________________________________________________
						glBegin(GL_QUADS); //face traseira
						glNormal3f(-0.0273f,-0.46875f, 0.15625f);
							glVertex3f(-1.00f, -0.5f, 0.25f); //B2
						glNormal3f(0.0273f,-0.46875f, 0.15625f);
							glVertex3f(1.00f, -0.5f, 0.25f);  //C2
						glNormal3f(0.0273f,-0.46875f, -0.15625f);
							glVertex3f(1.00f, -0.5, -0.25f);  //C3
						glNormal3f(-0.0273f,-0.46875f, -0.15625f);
							glVertex3f(-1.00f, -0.5f, -0.25f); //B3
						glEnd();
						glBegin(GL_QUADS); //face dianteira
						glNormal3f(-0.0273f,0.46875f, 0.15625f);
							glVertex3f(-1.00f, 0.5f, 0.25f); //B7
						glNormal3f(0.0273f,0.46875f, 0.15625f);
							glVertex3f(1.00f, 0.5f, 0.25f);  //C7
						glNormal3f(0.0273f,0.46875f, -0.15625f);
							glVertex3f(1.00f, 0.5, -0.25f);  //C6
						glNormal3f(-0.0273f,0.46875f, -0.15625f);
							glVertex3f(-1.00f, 0.5f, -0.25f); //B6
						glEnd();
//_____________________________________________________________________________________________________________________
						glBegin(GL_QUADS); //face traseira-superior
						glNormal3f(-0.0273f,-0.156f, 0.46875f);
							glVertex3f(-1.00f, -0.25f, 0.50f); //B1
						glNormal3f(0.0273f, -0.156f, 0.46875f);
							glVertex3f(1.00f, -0.25f, 0.50f);  //C1
						glNormal3f(0.0273f,-0.46875f, 0.15625f);
							glVertex3f(1.00f, -0.5f, 0.25f);  //C2
						glNormal3f(-0.0273f,-0.46875f, 0.15625f);
							glVertex3f(-1.00f, -0.5f, 0.25f); //B2
						glEnd();
						glBegin(GL_QUADS); //face inferior-dianteira
						glNormal3f(0.0273f, 0.156f, -0.46875f);
							glVertex3f(1.00f, 0.25, -0.50f);  //C5
						glNormal3f(-0.0273f,0.156f, -0.46875f);
							glVertex3f(-1.00f, 0.25f, -0.50f); //B5
						glNormal3f(-0.0273f,0.46875f, -0.15625f);
							glVertex3f(-1.00f, 0.5f, -0.25f); //B6
						glNormal3f(0.0273f,0.46875f, -0.15625f);
							glVertex3f(1.00f, 0.5, -0.25f);  //C6
						glEnd();
//____________________________________________________________________________________________________________________
						glBegin(GL_QUADS); //face traseira-inferior
						glNormal3f(-0.0273f,-0.156f, -0.46875f);
							glVertex3f(-1.00f, -0.25f, -0.50f); //B4
						glNormal3f(0.0273f, -0.156f, -0.46875f);
							glVertex3f(1.00f, -0.25f, -0.50f);  //C4
						glNormal3f(0.0273f,-0.46875f, -0.15625f);
							glVertex3f(1.00f, -0.5, -0.25f);  //C3
						glNormal3f(-0.0273f,-0.46875f, -0.15625f);
							glVertex3f(-1.00f, -0.5f, -0.25f); //B3
						glEnd();
						glBegin(GL_QUADS); //face superior-dianteira
							glNormal3f(-0.0273f,0.46875f, 0.15625f);
							glVertex3f(-1.00f, 0.5f, 0.25f); //B7
						glNormal3f(0.0273f,0.46875f, 0.15625f);
							glVertex3f(1.00f, 0.5f, 0.25f);  //C7
						glNormal3f(0.0273f, 0.156f, 0.46875f);
							glVertex3f(1.00f, 0.25, 0.50f);  //C8
						glNormal3f(-0.0273f,0.156f, 0.46875f);
							glVertex3f(-1.00f, 0.25f, 0.50f); //B8
						glEnd();
//___________________________________________________________________________________________________________________
					glPopMatrix();
					glPushMatrix();
				mat[0] = 0.1745;
				mat[1] = 0.01175;
				mat[2] = 0.01175;
				mat[3] = 1.0;
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
				mat[0] = 0.61424;
				mat[1] = 0.04136;
				mat[2] = 0.04136;
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
				mat[0] = 0.727811;
				mat[1] = 0.626959;
				mat[2] = 0.626959;
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
				glMaterialf(GL_FRONT, GL_SHININESS, 0.6 * 128.0);

//_______________________________________________________________________________________________
						glTranslatef(X,Y,0);
						glBegin(GL_TRIANGLES);
							glNormal3f(-1, 0, 0); //Centro
								glVertex3f(-2.00f, 0.00f, 0.00f); //A0
							glNormal3f(-0.36979f, -0.0417f, 0.125f);
								glVertex3f(-2.00f, -0.125f, 0.250f); //A1
							glNormal3f(-0.36979f, -0.125f, 0.0417f);
								glVertex3f(-2.00f, -0.25, 0.125f); //A2
							glNormal3f(-1, 0, 0); //Centro
								glVertex3f(-2.00f, 0.00f, 0.00f); //A0
							glNormal3f(-0.36979f, -0.125f, 0.0417f);
								glVertex3f(-2.00f, -0.25, 0.125f); //A2
							glNormal3f(-0.36979f, -0.125f, -0.0417f);
								glVertex3f(-2.00f, -0.25f, -0.125f); //A3
							glNormal3f(-1, 0, 0); //Centro
								glVertex3f(-2.00f, 0.00f, 0.00f); //A0
							glNormal3f(-0.36979f, -0.125f, -0.0417f);
								glVertex3f(-2.00f, -0.25f, -0.125f); //A3
							glNormal3f(-0.36979f, -0.0417f, -0.125f);
								glVertex3f(-2.00f, -0.125f, -0.250f); //A4
							glNormal3f(-1, 0, 0); //Centro
								glVertex3f(-2.00f, 0.00f, 0.00f); //A0
							glNormal3f(-0.36979f, -0.0417f, -0.125f);
								glVertex3f(-2.00f, -0.125f, -0.250f); //A4
							glNormal3f(-0.36979f, 0.0417f, -0.125f);
								glVertex3f(-2.00f, 0.125f, -0.250f); //A5
							glNormal3f(-1, 0, 0); //Centro
								glVertex3f(-2.00f, 0.00f, 0.00f); //A0
							glNormal3f(-0.36979f, 0.0417f, -0.125f);
								glVertex3f(-2.00f, 0.125f, -0.250f); //A5
							glNormal3f(-0.36979f, 0.125f, -0.0417f);
								glVertex3f(-2.00f, 0.250f, -0.125f); //A6
							glNormal3f(-1, 0, 0); //Centro
								glVertex3f(-2.00f, 0.00f, 0.00f); //A0
							glNormal3f(-0.36979f, 0.125f, -0.0417f);
								glVertex3f(-2.00f, 0.250f, -0.125f); //A6
							glNormal3f(-0.36979f, 0.125f, 0.0417f);
								glVertex3f(-2.00f, 0.250f, 0.125f); //A7
							glNormal3f(-1, 0, 0); //Centro
								glVertex3f(-2.00f, 0.00f, 0.00f); //A0
							glNormal3f(-0.36979f, 0.125f, 0.0417f);
								glVertex3f(-2.00f, 0.250f, 0.125f); //A7
							glNormal3f(-0.36979f, 0.0417f, 0.125f);
								glVertex3f(-2.00f, 0.125f, 0.250f); //A8
							glNormal3f(-1, 0, 0); //Centro
								glVertex3f(-2.00f, 0.00f, 0.00f); //A0
							glNormal3f(-0.36979f, -0.0417f, 0.125f);
								glVertex3f(-2.00f, -0.125f, 0.250f); //A1
							glNormal3f(-0.36979f, 0.0417f, 0.125f);
								glVertex3f(-2.00f, 0.125f, 0.250f); //A8
					glEnd();
//_______________________________________________________________________________________________
						glBegin(GL_TRIANGLES);
							glNormal3f(1, 0, 0); //Centro
								glVertex3f(2.00f, 0.00f, 0.00f); //D0
							glNormal3f(0.36979f, -0.0417f, 0.125f);
								glVertex3f(2.00f, -0.125f, 0.250f); //D1
							glNormal3f(0.36979f, -0.125f, 0.0417f);
								glVertex3f(2.00f, -0.25, 0.125f); //D2
							glNormal3f(1, 0, 0); //Centro
								glVertex3f(2.00f, 0.00f, 0.00f); //D0
							glNormal3f(0.36979f, -0.125f, 0.0417f);
								glVertex3f(2.00f, -0.25, 0.125f); //D2
							glNormal3f(0.36979f, -0.125f, -0.0417f);
								glVertex3f(2.00f, -0.25f, -0.125f); //D3
							glNormal3f(1, 0, 0); //Centro
								glVertex3f(2.00f, 0.00f, 0.00f); //D0
							glNormal3f(0.36979f, -0.125f, -0.0417f);
								glVertex3f(2.00f, -0.25f, -0.125f); //D3
							glNormal3f(0.36979f, -0.0417f, -0.125f);
								glVertex3f(2.00f, -0.125f, -0.250f); //D4
							glNormal3f(1, 0, 0); //Centro
								glVertex3f(2.00f, 0.00f, 0.00f); //D0
							glNormal3f(0.36979f, -0.0417f, -0.125f);
								glVertex3f(2.00f, -0.125f, -0.250f); //D4
							glNormal3f(0.36979f, 0.0417f, -0.125f);
								glVertex3f(2.00f, 0.125f, -0.250f); //D5
							glNormal3f(1, 0, 0); //Centro
								glVertex3f(2.00f, 0.00f, 0.00f); //D0
							glNormal3f(0.36979f, 0.0417f, -0.125f);
								glVertex3f(2.00f, 0.125f, -0.250f); //D5
							glNormal3f(0.36979f, 0.125f, -0.0417f);
								glVertex3f(2.00f, 0.250f, -0.125f); //D6
							glNormal3f(1, 0, 0); //Centro
								glVertex3f(2.00f, 0.00f, 0.00f); //D0
							glNormal3f(0.36979f, 0.125f, -0.0417f);
								glVertex3f(2.00f, 0.250f, -0.125f); //D6
							glNormal3f(0.36979f, 0.125f, 0.0417f);
								glVertex3f(2.00f, 0.250f, 0.125f); //D7
							glNormal3f(1, 0, 0); //Centro
								glVertex3f(2.00f, 0.00f, 0.00f); //D0
							glNormal3f(0.36979f, 0.125f, 0.0417f);
								glVertex3f(2.00f, 0.250f, 0.125f); //D7
							glNormal3f(0.36979f, 0.0417f, 0.125f);
								glVertex3f(2.00f, 0.125f, 0.250f); //D8
							glNormal3f(1, 0, 0); //Centro
								glVertex3f(2.00f, 0.00f, 0.00f); //D0
							glNormal3f(0.36979f, -0.0417f, 0.125f);
								glVertex3f(2.00f, -0.125f, 0.250f); //D1
							glNormal3f(0.36979f, 0.0417f, 0.125f);
								glVertex3f(2.00f, 0.125f, 0.250f); //D8
					glEnd();

//_____________________________________________________________________________________________________________
							glBegin(GL_QUADS);
							glNormal3f(-0.36979f, -0.0417f, 0.125f);
								glVertex3f(-2.00f, -0.125f, 0.250f); //A1
							glNormal3f(-0.0273f,-0.156f, 0.46875f);
								glVertex3f(-1.00f, -0.25f, 0.50f); //B1
							glNormal3f(-0.0273f,-0.46875f, 0.15625f);
								glVertex3f(-1.00f, -0.5f, 0.25f); //B2
							glNormal3f(-0.36979f, -0.125f, 0.0417f);
								glVertex3f(-2.00f, -0.25, 0.125f); //A2
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(-0.36979f, -0.125f, 0.0417f);
								glVertex3f(-2.00f, -0.25, 0.125f); //A2
							glNormal3f(-0.0273f,-0.46875f, 0.15625f);
								glVertex3f(-1.00f, -0.5f, 0.25f); //B2
							glNormal3f(-0.0273f,-0.46875f, -0.15625f);
								glVertex3f(-1.00f, -0.5f, -0.25f); //B3
							glNormal3f(-0.36979f, -0.125f, -0.0417f);
								glVertex3f(-2.00f, -0.25f, -0.125f); //A3
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(-0.36979f, -0.125f, -0.0417f);
								glVertex3f(-2.00f, -0.25f, -0.125f); //A3
							glNormal3f(-0.0273f,-0.46875f, -0.15625f);
								glVertex3f(-1.00f, -0.5f, -0.25f); //B3
							glNormal3f(-0.0273f,-0.156f, -0.46875f);
								glVertex3f(-1.00f, -0.25f, -0.50f); //B4
							glNormal3f(-0.36979f, -0.0417f, -0.125f);
								glVertex3f(-2.00f, -0.125f, -0.250f); //A4
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(-0.36979f, -0.0417f, -0.125f);
								glVertex3f(-2.00f, -0.125f, -0.250f); //A4
							glNormal3f(-0.0273f,-0.156f, -0.46875f);
								glVertex3f(-1.00f, -0.25f, -0.50f); //B4
							glNormal3f(-0.0273f,0.156f, -0.46875f);
								glVertex3f(-1.00f, 0.25f, -0.50f); //B5
							glNormal3f(-0.36979f, 0.0417f, -0.125f);
								glVertex3f(-2.00f, 0.125f, -0.250f); //A5
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(-0.36979f, 0.0417f, -0.125f);
								glVertex3f(-2.00f, 0.125f, -0.250f); //A5
							glNormal3f(-0.0273f,0.156f, -0.46875f);
								glVertex3f(-1.00f, 0.25f, -0.50f); //B5
							glNormal3f(-0.0273f,0.46875f, -0.15625f);
								glVertex3f(-1.00f, 0.5f, -0.25f); //B6
							glNormal3f(-0.36979f, 0.125f, -0.0417f);
								glVertex3f(-2.00f, 0.250f, -0.125f); //A6
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(-0.36979f, 0.125f, -0.0417f);
								glVertex3f(-2.00f, 0.250f, -0.125f); //A6
							glNormal3f(-0.0273f,0.46875f, -0.15625f);
								glVertex3f(-1.00f, 0.5f, -0.25f); //B6
							glNormal3f(-0.0273f,0.46875f, 0.15625f);
								glVertex3f(-1.00f, 0.5f, 0.25f); //B7
							glNormal3f(-0.36979f, 0.125f, 0.0417f);
								glVertex3f(-2.00f, 0.250f, 0.125f); //A7
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(-0.36979f, 0.125f, 0.0417f);
								glVertex3f(-2.00f, 0.250f, 0.125f); //A7
							glNormal3f(-0.0273f,0.46875f, 0.15625f);
								glVertex3f(-1.00f, 0.5f, 0.25f); //B7
							glNormal3f(-0.0273f,0.156f, 0.46875f);
								glVertex3f(-1.00f, 0.25f, 0.50f); //B8
							glNormal3f(-0.36979f, 0.0417f, 0.125f);
								glVertex3f(-2.00f, 0.125f, 0.250f); //A8
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(-0.36979f, 0.0417f, 0.125f);
								glVertex3f(-2.00f, 0.125f, 0.250f); //A8
							glNormal3f(-0.0273f,0.156f, 0.46875f);
								glVertex3f(-1.00f, 0.25f, 0.50f); //B8
							glNormal3f(-0.0273f,-0.156f, 0.46875f);
								glVertex3f(-1.00f, -0.25f, 0.50f); //B1
							glNormal3f(-0.36979f, -0.0417f, 0.125f);
								glVertex3f(-2.00f, -0.125f, 0.250f); //A1
							glEnd();
//_____________________________________________________________________________________________________________

							glBegin(GL_QUADS);
							glNormal3f(0.0273f, -0.156f, 0.46875f);
								glVertex3f(1.00f, -0.25f, 0.50f);  //C1
							glNormal3f(0.36979f, -0.0417f, 0.125f);
								glVertex3f(2.00f, -0.125f, 0.250f); //D1
							glNormal3f(0.36979f, -0.125f, 0.0417f);
								glVertex3f(2.00f, -0.25, 0.125f); //D2
							glNormal3f(0.0273f,-0.46875f, 0.15625f);
								glVertex3f(1.00f, -0.5f, 0.25f);  //C2
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(0.0273f,-0.46875f, 0.15625f);
								glVertex3f(1.00f, -0.5f, 0.25f);  //C2
							glNormal3f(0.36979f, -0.125f, 0.0417f);
								glVertex3f(2.00f, -0.25, 0.125f); //D2
							glNormal3f(0.36979f, -0.125f, -0.0417f);
								glVertex3f(2.00f, -0.25f, -0.125f); //D3
							glNormal3f(0.0273f,-0.46875f, -0.15625f);
								glVertex3f(1.00f, -0.5, -0.25f);  //C3
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(0.0273f,-0.46875f, -0.15625f);
								glVertex3f(1.00f, -0.5, -0.25f);  //C3
							glNormal3f(0.36979f, -0.125f, -0.0417f);
								glVertex3f(2.00f, -0.25f, -0.125f); //D3
							glNormal3f(0.36979f, -0.0417f, -0.125f);
								glVertex3f(2.00f, -0.125f, -0.250f); //D4
							glNormal3f(0.0273f, -0.156f, -0.46875f);
								glVertex3f(1.00f, -0.25f, -0.50f);  //C4
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(0.0273f, -0.156f, -0.46875f);
								glVertex3f(1.00f, -0.25f, -0.50f);  //C4
							glNormal3f(0.36979f, -0.0417f, -0.125f);
								glVertex3f(2.00f, -0.125f, -0.250f); //D4
							glNormal3f(0.36979f, 0.0417f, -0.125f);
								glVertex3f(2.00f, 0.125f, -0.250f); //D5
							glNormal3f(0.0273f, 0.156f, -0.46875f);
								glVertex3f(1.00f, 0.25, -0.50f);  //C5
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(0.0273f, 0.156f, -0.46875f);
								glVertex3f(1.00f, 0.25, -0.50f);  //C5
							glNormal3f(0.36979f, 0.0417f, -0.125f);
								glVertex3f(2.00f, 0.125f, -0.250f); //D5
							glNormal3f(0.36979f, 0.125f, -0.0417f);
								glVertex3f(2.00f, 0.250f, -0.125f); //D6
							glNormal3f(0.0273f,0.46875f, -0.15625f);
								glVertex3f(1.00f, 0.5, -0.25f);  //C6
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(0.0273f,0.46875f, -0.15625f);
								glVertex3f(1.00f, 0.5, -0.25f);  //C6
							glNormal3f(0.36979f, 0.125f, -0.0417f);
								glVertex3f(2.00f, 0.250f, -0.125f); //D6
							glNormal3f(0.36979f, 0.125f, 0.0417f);
								glVertex3f(2.00f, 0.250f, 0.125f); //D7
							glNormal3f(0.0273f,0.46875f, 0.15625f);
								glVertex3f(1.00f, 0.5f, 0.25f);  //C7
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(0.0273f,0.46875f, 0.15625f);
								glVertex3f(1.00f, 0.5f, 0.25f);  //C7
							glNormal3f(0.36979f, 0.125f, 0.0417f);
								glVertex3f(2.00f, 0.250f, 0.125f); //D7
							glNormal3f(0.36979f, 0.0417f, 0.125f);
								glVertex3f(2.00f, 0.125f, 0.250f); //D8
							glNormal3f(0.0273f, 0.156f, 0.46875f);
								glVertex3f(1.00f, 0.25, 0.50f);  //C8
							glEnd();
							glBegin(GL_QUADS);
							glNormal3f(0.0273f, 0.156f, 0.46875f);
								glVertex3f(1.00f, 0.25, 0.50f);  //C8
							glNormal3f(0.36979f, 0.0417f, 0.125f);
								glVertex3f(2.00f, 0.125f, 0.250f); //D8
							glNormal3f(0.36979f, -0.0417f, 0.125f);
								glVertex3f(2.00f, -0.125f, 0.250f); //D1
							glNormal3f(0.0273f, -0.156f, 0.46875f);
								glVertex3f(1.00f, -0.25f, 0.50f);  //C1
							glEnd();
					glPopMatrix();
		glPopMatrix();
		glFlush();
		}




