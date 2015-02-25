#include <stdlib.h>
#include "GameManager.h"
#include <GL/glut.h>

/* ARKANOID_OP - codigo final CG13/14
   68512 - Pedro Martins
   73351 - Joao Carraquico
   72843 - Ricardo Coelho da Silva
*/

GLint ww, hh;
GameManager *newGame;
static int FPS = 120;

void init(){
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);	

	GLfloat DiffuseLight_color[] = {0.7,0.7,0.7,1.0}; 
	GLfloat AmbientLight_color[] = {0.5,0.5,0.5,1.0};
	GLfloat SpecularLight_color[] = {0.5,0.5,0.5,1.0};
	GLfloat light_position[] = {0.0f, 0.0f, 10.0f, 0.0f};

	glLightfv(GL_LIGHT1,GL_SPECULAR,SpecularLight_color);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,DiffuseLight_color); 
	glLightfv(GL_LIGHT1,GL_AMBIENT,AmbientLight_color);
	glLightfv(GL_LIGHT1,GL_POSITION,light_position);

	
}

void myReshape(GLsizei w, GLsizei h) {
	ww = w;
	hh = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20.0f, 20.0f, -20.0f, 20.0f, -20.0f, 20.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, ww, hh);
	newGame->drawGame();
	glFlush();
}

void myKeyboard(unsigned char key, int x, int y){
	newGame->keyboard(key,x,y);
}

void mySpecialKeyboard(int key, int x, int y){
	newGame->SpecialKeyboard(key,x,y);
}

void myIdle(){
	glutPostRedisplay();
}
void myTimer(int v) {
	glutPostRedisplay();
	newGame->pointlight();
    glutTimerFunc(1000/FPS, myTimer, 0);

}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize (720, 720);
	glutInitWindowPosition (0, 0);
	glutCreateWindow("Welcome to ARKANOID_OP. Press P to start the game. L, C and B are lighting options");
	init();
	newGame = new GameManager();
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecialKeyboard);
	myTimer(0);
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMainLoop();
	return 0;
}