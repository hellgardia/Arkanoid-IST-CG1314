#ifndef __GAMEMANAGER__H__
#define __GAMEMANAGER__H__


#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <GL/glut.h>
#include <string.h>
#include "Ship.h"
#include "Ball.h"
#include "Block.h"
#include "RedBlock.h"
#include "BronzeBlock.h"
#include "CyanBlock.h"
#include "GreenBlock.h"
#include "YellowBlock.h"
#include "WhiteBlock.h"
#include "Boundaries.h"
#include "Camera.h"
#include "Ortho.h"
#include "Perspective.h"
#include "BMPLoader.h"

#define xblockdif 0.80f
#define yblockdif 0.35f
#define stdvalueb 0.15f
#define blockspace 1.80f
#define topLimit 19.0f
#define bottomLimit -19.0f
#define leftLimit -19.0f
#define rightLimit 19.0f
#define backRow 13.5f
#define firstRow 12.0f
#define secondRow 10.5f
#define thirdRow 9.0f
#define fourthRow 7.5f
#define fifthRow 6.0f



class GameManager{


	std::string pointhud ;
	const char* c_hud ;
	const char* c_hud2 ;
	std::ostringstream ss;
	std::string hud;
	std::string hud2;
	std::string spoints;
	int _points;
	int _totalBlocks;
	std::string convertInt(int number);
	Ship *_ship;
	Ball *_ball;
	Boundaries *_bounds;
	std::vector<Block*> _blocks;
	std::vector<Camera*> _camera;
	std::map<int, Material*> _materials;

	GLsizei width;
	GLsizei height;


protected:
	unsigned int _nCamera;
public:
	bool _light;
	bool _goingUp;
	bool _goingDown;
	bool _goingRight;
	bool _ballmoving;
	int _numblocks;
	unsigned int _texture;
	float _ydir; //se a 0, movimento para baixo
	float _xdir; //se a 0, movimento para a esquerda
	GameManager();

	~GameManager();

	void spotlight();
	void pointlight();
	void startCamera(GLsizei w, GLsizei h);
	void changeCamera(unsigned int newCam);
	void updateCamera();
	void drawBlocks();
	void keyboard(unsigned char key, int x, int y);
	void SpecialKeyboard(int key, int x, int y);
	void update();
	void drawGame();
	void drawHUD(int lives, int points);
	bool testCollisionWithBounds();
	bool testCollisionWithShip();
	bool testCollisionWithBlocks(Block* a);
	void moveBall();
	void moveSideBall();
	void applyBackgroundTexture();
	const unsigned int LoadTexture( const string & textureFilename);
	void GenerateBoard();

};







#endif