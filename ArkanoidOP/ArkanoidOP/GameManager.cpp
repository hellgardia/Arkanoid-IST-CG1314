#include "GameManager.h"



GameManager::GameManager(){
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);
		_texture = NULL;
		_numblocks = 0;
		_points = 0;
		_ball = new Ball();
		_ship = new Ship();
		_bounds = new Boundaries();
		_ballmoving = false;
		_goingUp=false;
		_goingRight=false;
		_ydir = stdvalueb;
		_xdir = stdvalueb;
		applyBackgroundTexture();
		for(float i = 17.0; i > -18.0; i=i-blockspace){
			_blocks.push_back(new WhiteBlock(i, backRow, 0.0f));
			_numblocks++;
		}
		for(float i = 17.0; i > -18.0; i=i-blockspace){
			_blocks.push_back(new RedBlock(i, firstRow, 0.0f));
			_numblocks++;
		}
		for(float i = 17.0; i > -18.0; i=i-blockspace){
			_blocks.push_back(new BronzeBlock(i, secondRow, 0.0f));
			_numblocks++;
		}
		for(float i = 17.0; i > -18.0;  i=i-blockspace){
			_blocks.push_back(new YellowBlock(i, thirdRow, 0.0f));
			_numblocks++;
		}
		for(float i = 17.0; i > -18.0;  i=i-blockspace){
			_blocks.push_back(new CyanBlock(i, fourthRow, 0.0f));
			_numblocks++;
		}
		for(float i = 17.0; i > -18.0; i=i-blockspace){
			_blocks.push_back(new GreenBlock(i, fifthRow, 0.0f));
			_numblocks++;
		}



		//creates camera
		_camera.push_back(new Ortho(0.0,0.0,0.0,0.0,0.0,0.0));		   //ortho
		_camera.push_back(new Perspective(0.0,-21.0,4.0,0.0,0.0,0.0)); //atras da nave
		_camera.push_back(new Perspective(0.0,-18.0,2.0,0.0,0.0,0.0)); //fps 
		_camera.push_back(new Perspective(0.0, -21.0,-10.0,0.0,0.0,0.0)); //teste
		 
		_nCamera=1;


}

void GameManager::pointlight(){
	float x = _ball->getX();
	float y = _ball->getY();
	GLfloat totaldarkness[] = {0.0,0.0,0.0,1.0};
	GLfloat DiffuseLight_color[] = {1.0,1.0,1.0,1.0}; 
	GLfloat AmbientLight_color[] = {1.,1.,1.,1.0};
	GLfloat SpecularLight_color[] = {1.0,1.0,1.0,1.0};
	//GLfloat light_position5[] = {x, y, 0.75f, 1.0f}; MODO DE AVALIACAO
	GLfloat light_position5[] = {x, y, 2.25f, 1.0f}; //para o caso de querermos mostrar melhor
	GLfloat direction5[] = {0.0 , 0.0, -1.0f};
	if(_ydir<0){
		glEnable(GL_LIGHT5);
		glLightfv(GL_LIGHT5, GL_DIFFUSE, DiffuseLight_color);
		glLightfv(GL_LIGHT5, GL_SPECULAR, SpecularLight_color);
		glLightfv(GL_LIGHT5, GL_POSITION, light_position5);
		// Defining pointlight attributes
		glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 60.0);
		glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 5.0);
		glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, direction5);
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, totaldarkness);
	}
	else {
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, totaldarkness);
		glDisable(GL_LIGHT5);
	}

}


void GameManager::spotlight(){

	GLfloat totaldarkness[] = {0.0,0.0,0.0,1.0};
	GLfloat DiffuseLight_color[] = {.5,.5,.5,1.0}; 
	GLfloat AmbientLight_color[] = {0.2,0.2,0.2,1.0};
	GLfloat SpecularLight_color[] = {.8,.8,.8,1.0};
	GLfloat light_position1[] = {20.5f, 22, 8.0f, 1.0f};
	GLfloat light_position2[] = {-20.5f, -22, 8.0f, 1.0f};
	GLfloat light_position3[] = {20.5f, -22, 8.0f, 1.0f};
	GLfloat light_position4[] = {-20.5f, 22, 8.0f, 1.0f};
	GLfloat direction1[] = {-1.0, -1.0f, 0.0f};
	GLfloat direction2[] = {1.0f, 1.0f, 0.0f};
	GLfloat direction3[] = {-1.0f, 1.0f, 0.0f};
	GLfloat direction4[] = {1.0f, -1.0f, 0.0f};

		glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight_color);
		glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight_color);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
		// Defining spotlight attributes
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45.0);
		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10.0);
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction1);
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, AmbientLight_color);

		glLightfv(GL_LIGHT2, GL_DIFFUSE, DiffuseLight_color);
		glLightfv(GL_LIGHT2, GL_SPECULAR, SpecularLight_color);
		glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
		// Defining spotlight attributes
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 45.0);
		glLightf(GL_LIGHT2, GL_SPOT_EXPONENT,10.0);
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, direction2);
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, AmbientLight_color);

		glLightfv(GL_LIGHT3, GL_DIFFUSE, DiffuseLight_color);
		glLightfv(GL_LIGHT3, GL_SPECULAR, SpecularLight_color);
		glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
		// Defining spotlight attributes
		glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 45.0);
		glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 10.0);
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, direction3);
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, AmbientLight_color);
		
		glLightfv(GL_LIGHT4, GL_DIFFUSE, DiffuseLight_color);
		glLightfv(GL_LIGHT4, GL_SPECULAR, SpecularLight_color);
		glLightfv(GL_LIGHT4, GL_POSITION, light_position4);
		// Defining spotlight attributes
		glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 45.0);
		glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 10.0);
		glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, direction4);
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, AmbientLight_color);

		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, totaldarkness);
}


void GameManager::drawBlocks(){
	float i;
		for(i=0; i<_blocks.size();i++){
			if(_blocks[i]->alive())
			_blocks[i]->drawBlock();
		}
}


void GameManager::SpecialKeyboard(int key, int x, int y){

	switch(key){
		case GLUT_KEY_LEFT:
			if(_ballmoving == true){
			if(_ball->getIsInShip())
			_ship->Ship::moveleft();
			}
			break;
		case GLUT_KEY_RIGHT:
			if(_ballmoving == true){
			if(_ball->getIsInShip())
			_ship->Ship::moveright();
			}
			break;
		case GLUT_KEY_UP:
			if(_ballmoving == true) _ballmoving = false;
			else _ballmoving = true;
			break;
	}
		
}


void GameManager::keyboard(unsigned char key, int x, int y){

	switch(key){
		case '1':
			_nCamera = 1;
			break;

		case '2':
			_nCamera = 2; 
			break;

		case '3':
			_nCamera = 3; 
			break;

		case '4':
			_nCamera = 4; 
			break;

		case 'l': //ambient
			_light = false;
			glDisable(GL_LIGHT0);
			glDisable(GL_LIGHT2);
			glDisable(GL_LIGHT3);
			glDisable(GL_LIGHT4);
			glDisable(GL_LIGHT5);
			glEnable(GL_LIGHT1);
			break;

		case 'c': //quadspot
			glDisable(GL_LIGHT1);
			glDisable(GL_LIGHT5);
			glEnable(GL_LIGHT0);
			glEnable(GL_LIGHT2);
			glEnable(GL_LIGHT3);
			glEnable(GL_LIGHT4);
			_light = true;
			spotlight();
			break;

		case 'o': //ambientoffspotlightoff
			glDisable(GL_LIGHT1);
			glDisable(GL_LIGHT0);
			glDisable(GL_LIGHT2);
			glDisable(GL_LIGHT3);
			glDisable(GL_LIGHT4);
			glDisable(GL_LIGHT5);
			_light = true;
			break;

		case 'b': //pointlight
			glDisable(GL_LIGHT1);
			glDisable(GL_LIGHT0);
			glDisable(GL_LIGHT2);
			glDisable(GL_LIGHT3);
			glDisable(GL_LIGHT4);
			glEnable(GL_LIGHT5);
			pointlight();
			break;


		case 'p':
			if(_ballmoving)
				_ballmoving = false;
			else
				_ballmoving = true;

	}
		
}

void GameManager::drawGame(){

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	startCamera(width,height);
	GenerateBoard();
	_ship->drawSpaceship();
	_ball->drawBall();
	_bounds->drawBounds();
	drawBlocks();
	drawHUD(_ship->getHP(), _ship->getPoints());
	glutSwapBuffers();
	if(_ballmoving){
	testCollisionWithBounds();
	testCollisionWithShip();
	for(int i = 0;  i<_blocks.size();i++){
		testCollisionWithBlocks(_blocks[i]);
		}
	moveBall();
	moveSideBall();
	}

	if(_light == true){spotlight();}

}

std::string GameManager::convertInt(int number)
{

   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

void GameManager::drawHUD(int lives, int points){
	glPushMatrix();
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);
	glColor3d(1.0, 1.0, 1.0);

	if(_numblocks == 0){
		hud = "VICTORY!!!!";
		c_hud = hud.c_str();
		glRasterPos2i(-6.0, 0.0);
		_ballmoving = false;
		for(int i=0; i<hud.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c_hud[i]);
	}

	else{
		ss << "POINTS: " << points;
		pointhud = ss.str();
		glRasterPos2i(12.0, 18.0);
		for(int i=0; i<pointhud.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, pointhud[i]);
		ss.str("");

	if(lives == 3) {
		hud = "LIVES = XXX";
		c_hud = hud.c_str();
		glRasterPos2i(-18.0, 18.0);
		for(int i=0; i<hud.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c_hud[i]);
	}

	if(lives == 2) {
		hud = "LIVES = XX";
		c_hud = hud.c_str();
		glRasterPos2i(-18.0, 18.0);
		for(int i=0; i<hud.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c_hud[i]);
	}

	if(lives == 1) {
		hud = "LIVES = X";
		c_hud = hud.c_str();
		glRasterPos2i(-18.0, 18.0);
		for(int i=0; i<hud.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c_hud[i]);
	}

	if(lives == 0) {
		hud = "Better luck next time!!!";
		c_hud = hud.c_str();
		glRasterPos2i(-8.0, 0.0);
		_ballmoving = false;
		for(int i=0; i<hud.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c_hud[i]);
	}
	}
		glDepthMask(GL_TRUE);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
		glPopMatrix();
	
	
}

void GameManager::startCamera(GLsizei w, GLsizei h){
	float x , xangle;
	float y, yangle;
	width = w;
	height = h;
	glViewport(0, 0, w, h);
	
	if(_nCamera == 1)
	_camera[0]->displayCamera(w,h);

	if(_nCamera == 2){
	 x = (_ship->getX());
	 y = (_ship->getY());
	 xangle = (_ball->getX());
	 yangle = (_ball->getY());
	_camera[1]->displayCamera(w,h, x, y, _nCamera); 
	}

	if(_nCamera==3){
	x = (_ship->getX());
	 y = (_ship->getY());
	_camera[2]->displayCamera(w,h, x, y, _nCamera); 
	}
	if(_nCamera == 4){
	 x = (_ship->getX());
	 y = (_ship->getY());
	 xangle = (_ball->getX());
	 yangle = (_ball->getY());
	_camera[3]->displayCamera(w,h, xangle, yangle, _nCamera); 
	}
}

bool GameManager::testCollisionWithBounds(){
	if(_ball->getY() >= topLimit) {
		_ydir = stdvalueb*sin((rand()%45-25+25)*M_PI/180); 
		return true;
	}
	else if(_ball->getY() <= bottomLimit)  {
		_ydir = stdvalueb*sin((rand()%(45-25+25))*M_PI/180);  
		_xdir = stdvalueb*cos((rand()%(45-25+25))*M_PI/180); 
		if(_ship->getHP() > 0){
		_ball->setX(_ship->getX());
		_ball->setY(_ship->getY()+0.5f);
		_ship->setHP(_ship->getHP()-1);
		}
		return true;
	}
	else if(_ball->getX() >= rightLimit)   {
		_xdir = stdvalueb*cos((rand()%(45-25+25))*M_PI/180); 
		return true;
	}
	else if(_ball->getX() <= leftLimit)    {
		_xdir = stdvalueb*cos((rand()%(45-25+25))*M_PI/180); 
		return true;
	}
	else return false;
}

bool GameManager::testCollisionWithShip(){
	if(_ball->getY() <= _ship->getY()+0.5f && 
		_ball->getX() > _ship->getLeftX()-0.5f && 
		_ball->getX() < _ship->getRightX()+0.5f) {
		_ydir = -_ydir;
		_xdir = _xdir;
		return true;
	}
	else if(_ball->getY() <= _ship->getY()+0.5f && 
		_ball->getX() > _ship->getLeftX()-0.5f && 
		_ball->getX() < _ship->getRightX()+0.5f){
		_xdir = -_xdir;
		return true;
	}
	return false;
}

bool GameManager::testCollisionWithBlocks(Block* a){
	if(a->alive()){	
	if((a->getX()-xblockdif < _ball->getX() && a->getX()+xblockdif > _ball->getX())) {
			if(a->getY()-yblockdif < _ball->getY() && a->getY()+yblockdif > _ball->getY()){
						_ydir = -_ydir;
						_xdir = _xdir;
						a->kill();
						_ship->addPoints(100);
						drawHUD(_ship->getHP(), _ship->getPoints());
						return true;
			
			}
		}
		else if(a->getY()-yblockdif < _ball->getY() && a->getY()+yblockdif > _ball->getY()) {
			if((a->getX()-xblockdif < _ball->getX() && a->getX()+xblockdif > _ball->getX())){
						_ydir = _ydir;
						_xdir = -_xdir;
						a->kill();
						_ship->addPoints(100);
						drawHUD(_ship->getHP(), _ship->getPoints());
						return true;
			}
		}
			else return false;
	}
}

void GameManager::moveBall(){ 
	if(_goingUp==false){
		if(_ball->getY() >= bottomLimit) _ball->moveDown(_ydir);
		else _goingUp = true;
	}
	
	if(_goingUp==true){
		if(_ball->getY() <= topLimit)	_ball->moveUp(_ydir);
		else _goingUp = false;
	}
}


void GameManager::moveSideBall(){ 
	if(_goingRight==false){
		if(_ball->getX() >= leftLimit) _ball->moveLeft(_xdir);
		else _goingRight = true;
	}
	
	if(_goingRight==true){
		if(_ball->getX() <= rightLimit)	_ball->moveRight(_xdir);
		else _goingRight = false;
	}
}



const unsigned int GameManager::LoadTexture( const string & textureFilename)
{
    unsigned int textureID;
    glGenTextures( 1, &textureID);
	BMPloader * bitmap = new BMPloader(textureFilename);
	if ( bitmap->Isvalid() )
	{
		glPixelStoref( GL_UNPACK_ALIGNMENT, 1);
		glEnable( GL_TEXTURE_2D);
        glBindTexture( GL_TEXTURE_2D, textureID);
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, bitmap->Width(), bitmap->Heigth(), 0, GL_RGB,
					 GL_UNSIGNED_BYTE, bitmap->Image());
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	}
	delete bitmap;
	return textureID;
}

/* unsigned int GameManager::GenerateBoard( const int NoDivisions)
{
    unsigned int board = glGenLists( 1);
    float materialDiffuse[] = {.54, .89, .63, 1.};
    glNewList( board, GL_COMPILE);
    glMaterialfv( GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialDiffuse);
    glPushMatrix(),
    glTranslatef( 0., 0., -2.5);
    glNormal3f( 0., 0., 1.);
    float x1, x2, y1, y2, s1, s2, t1, t2;
    y2 = -30;   t2 = 0;
    for ( int j=0; j<NoDivisions; j++) {
        y1 = y2;   t1 = t2;
        y2 = 10. * (j+1) / NoDivisions - 10. * .5;
        t2 = 1. * (j+1) / NoDivisions;
        x2 = -30.;   s2 = 0.;
        for ( int i=0; i<NoDivisions; i++) {
            x1 = x2;   s1 = s2;
            x2 = 10. * (i+1) / NoDivisions - 10 * .5;
            s2 = 1. * (i+1) / NoDivisions;
            glBegin( GL_TRIANGLE_STRIP);
            glTexCoord2f( s1, t1);
            glVertex3f(   x1, y1, 0.);
            glTexCoord2f( s2, t1);
            glVertex3f(   x2, y1, 0.);
            glTexCoord2f( s1, t2);
            glVertex3f(   x1, y2, 0.);
            glTexCoord2f( s2, t2);
            glVertex3f(   x2, y2, 0.);
            glEnd();
        }
    }
    glPopMatrix();
    glEndList();
    
    return board;
}*/

void GameManager::GenerateBoard() {

	Material* whiteplastic = new Material(0.0, 0.0, 0.0, 0.55, 0.55, 0.55, 0.70,
			0.70, 0.70, .75);
	whiteplastic->apply();
	glEnable(GL_TEXTURE_2D);
	float xyinc = 1.5;
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
	for (GLfloat x = -20; x < 20.; x += xyinc)
		for (GLfloat y = -20.; y < 20; y += xyinc) {
			glTexCoord2f(0, 0);
			glVertex3f(x, y, -1.);
			glTexCoord2f(0, 1);
			glVertex3f(x, y + xyinc, -1.);
			glTexCoord2f(1, 1);
			glVertex3f(x + xyinc, y + xyinc, -1.);
			glTexCoord2f(1, 0);
			glVertex3f(x + xyinc, y, -1.);
		}

	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

}

void GameManager::applyBackgroundTexture() {

	if (_texture == NULL) {
		glEnable(GL_TEXTURE_2D);
		_texture = LoadTexture("image.bmp");
		glDisable(GL_TEXTURE_2D);
	}

	float DiffuseTextureOn[] = { 1., 1., 1., 1. };

	std::cout << "texture " << std::endl;
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, DiffuseTextureOn);
	glEnable(GL_TEXTURE_2D);
	glBindTexture( GL_TEXTURE_2D, _texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//glDisable(GL_TEXTURE_2D);

}



