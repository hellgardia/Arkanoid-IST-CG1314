#ifndef __SpaceInvaders__Material__
#define __SpaceInvaders__Material__

#include <iostream>
#if defined(__APPLE__) || defined(MACOSX) 
 #include <GLUT/glut.h> 
#else 
 #include <GL/glut.h> 
#endif 

class Material{
	GLfloat _amb[4];
	GLfloat _dif[3];
	GLfloat _spc[3];
	GLfloat _shininess;
	GLfloat _emissive[3];
public:
	Material(GLfloat ambr, GLfloat ambg, GLfloat ambb, GLfloat difr, GLfloat difg, GLfloat difb, GLfloat spcr, GLfloat spcg, GLfloat spcb, GLfloat shininess){
		_amb[0] = ambr;
		_amb[1] = ambg;
		_amb[2] = ambb;
		_amb[3] = 1.0;
		_dif[0] = difr;
		_dif[1] = difg;
		_dif[2] = difb;
		_spc[0] = spcr;
		_spc[1] = spcg;
		_spc[2] = spcb;
		_shininess = shininess;
		_emissive[0] = _emissive[1] = _emissive[2] = 0.;
		_emissive[3] = 1.;
	}
	Material(GLfloat ambr, GLfloat ambg, GLfloat ambb, GLfloat difr, GLfloat difg, GLfloat difb, GLfloat spcr, GLfloat spcg, GLfloat spcb, GLfloat shininess, GLfloat emissive){
			_amb[0] = ambr;
			_amb[1] = ambg;
			_amb[2] = ambb;
			_amb[3] = 1.0;
			_dif[0] = difr;
			_dif[1] = difg;
			_dif[2] = difb;
			_spc[0] = spcr;
			_spc[1] = spcg;
			_spc[2] = spcb;
			_shininess = shininess;
			_emissive[0] = _emissive[1] = _emissive[2] = emissive;
					_emissive[3] = 1.;
		}

	void apply(){
		glMaterialfv(GL_FRONT, GL_AMBIENT, _amb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, _dif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, _spc);
		glMaterialfv(GL_FRONT, GL_EMISSION, _emissive);
		glMaterialf(GL_FRONT, GL_SHININESS, _shininess * 128.0);
	}
};

#endif
