/*******************************************************
* Homework 2: OpenGL                                  *
* CS 148 (Summer 2016), Stanford University           *
*-----------------------------------------------------*
* First, you should fill in problem1(), problem2(),   *
* and problem3() as instructed in the written part of *
* the problem set.  Then, express your creativity     *
* with problem4()!                                    *
*                                                     *
* Note: you will only need to add/modify code where   *
* it says "TODO".                                     *
*                                                     *
* The left mouse button rotates, the right mouse      *
* button zooms, and the keyboard controls which       *
* problem to display.                                 *
*                                                     *
* For Linux/OS X:                                     *
* To compile your program, just type "make" at the    *
* command line.  Typing "make clean" will remove all  *
* computer-generated files.  Run by typing "./hw2"    *
*                                                     *
* For Visual Studio:                                  *
* You can create a project with this main.cpp and     *
* build and run the executable as you normally would. *
*******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = { 0,1,4,1 };
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples
float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1(){
	/*the number is the number of teapot, I think the teapot doesnt have the same rhythm 
	So I transform the teapot in each its own way*/
	//Most of them are rotates by z because i set coordinates at x,y,0//
	glPushMatrix();
	glTranslatef(1, 1, 0); //#1
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 1, 0, 0);
	glutSolidTeapot(0.3);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.25, 1.5, 0); //#2
	glRotatef(150, 0, 0, 1);
	glutSolidTeapot(0.3);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.75, 2, 0);//#3
	glRotatef(120, 0, 0, 1);
	glutSolidTeapot(0.3);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.65, 2, 0);//#4
	glRotatef(80, 0, 0, 1);
	glutSolidTeapot(0.3);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3.3, 1.5, 0);//#5
	glRotatef(30, 0, 0, 1);
	glutSolidTeapot(0.3);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3.75, 1, 0);//#6
	glutSolidTeapot(0.3);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.25, 0.5, 0);//#7
	glRotatef(225, 0, 0, 1);
	glutSolidTeapot(0.3);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2, 0, 0);//#8
	glRotatef(250, 0, 0, 1);
	glutSolidTeapot(0.3);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3, 0, 0);//#9
	glRotatef(300, 0, 0, 1);
	glutSolidTeapot(0.3);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3.5, 0.5, 0);//#10
	glRotatef(330, 0, 0, 1);
	glutSolidTeapot(0.3);
	glPopMatrix();

}

void problem2() {
	// TODO: Your code here!
	/*I found a rhythm of a ladder so I decide to use loop (more efficent)
	I estimate there are more than 10 steps so I create a loop 15(just to make sure)*/
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glutSolidCube(0.3);
	//This function fill out the x but doesnt change the y, x will be increase from the previous one (This is known as the BASE)
	for (int i = 0; i <= 15; i++) {
		glTranslatef(0.25, 0, 0);
		glutSolidCube(0.3);
	}
	glPopMatrix();
	glPushMatrix();
	//the matrix is reset, this time, the function begin at 0.25. x and y will increase from the previous one. This is just to fill out the "MIDDLE PART"
	for (int i = 0; i <= 15; i++) {
		glTranslatef(0.25, 0.01, 0);
		glutSolidCube(0.3);
	}
	glPopMatrix();
	glPushMatrix();
	//the matrix is reset and like the above. This is just to fill out the "MIDDLE PART"
	for (int i = 0; i <= 15; i++) {
		glTranslatef(0.25, 0.025, 0);
		glutSolidCube(0.3);
	}
	glPopMatrix();
	glPushMatrix();
	///the matrix is reset, and like the above. But this time it will make a like a ladder, however because there is missing ""MIDDLE PART". I have to create 2 function above
	for (int i = 0; i <= 15; i++) {
		glTranslatef(0.25, 0.04, 0);
		glutSolidCube(0.3);
	}
	glPopMatrix();

}

void problem3() {
	// TODO: Your code here!
	/*we will start at x=0.5, y=0.5
	then reset the matrix set new coordinate x+=1, y =0
	the loop will just add x+=0.5, y+=0.5*/
	glPushMatrix();
	for (int i = 0; i <= 5; i++) {//create 6 teapot in a diagonal with x and y increase from previous values//
		glTranslatef(0.5, 0.5, 0);
		glutSolidTeapot(0.3);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1, 0, 0);
	for (int i = 0; i <= 4; i++) {//Reset matrix, create 5 teapot in a diagonal with x and y increase from previous values//
		glTranslatef(0.5, 0.5, 0);
		glutSolidTeapot(0.3);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2, 0, 0);
	for (int i = 0; i <= 3; i++) {//Reset matrix, create 4 teapot in a diagonal with x and y increase from previous values//
		glTranslatef(0.5, 0.5, 0);
		glutSolidTeapot(0.3);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3, 0, 0);
	for (int i = 0; i <= 2; i++) {//Reset matrix, create 3 teapot in a diagonal with x and y increase from previous values//
		glTranslatef(0.5, 0.5, 0);
		glutSolidTeapot(0.3);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4, 0, 0);
	for (int i = 0; i <= 1; i++) {//Reset matrix, create 2 teapot in a diagonal with x and y increase from previous values//
		glTranslatef(0.5, 0.5, 0);
		glutSolidTeapot(0.3);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(5.5, 0.5, 0);//Reset matrix, create 1 teapot with x-5.5,y=0.5
	glutSolidTeapot(0.3);
	glPopMatrix();
}

void problem4() {
	
	glPushMatrix();
	for (int y = 1; y <= 4; y++) {//draw thumb
		glTranslatef(0, 0.5, 0);
		glutSolidCube(0.55);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.25, 0.2, 0);//extend finger
	for (int y = 1; y <=3; y++) {
		glTranslatef(0, 0.3, 0);
		glutSolidCube(0.55);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5, 0.2, 0);
	for (int y = 1; y <= 3; y++) {//extend
		glTranslatef(0, 0.3, 0);
		glutSolidCube(0.55);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.65, 0.05, 0.25);//finger collapse in z
	for (int y = 1; y <= 4; y++) {
		glTranslatef(0, 0.3, 0);
		glutSolidCube(0.25);
	}

	glPopMatrix();
	glPushMatrix();
	glTranslatef(2, 1, 0.25); //Teapot
	glutSolidTeapot(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.65, 0.05, 0.35);//finger collapse in z
	for (int y = 1; y <= 4; y++) {
		glTranslatef(0, 0.3, 0);
		glutSolidCube(0.25);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.65, 0.05, 0.55);//finger collapse in z
	for (int y = 1; y <= 4; y++) {
		glTranslatef(0, 0.3, 0);
		glutSolidCube(0.25);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.4, 0.05, 0.545);//finger collapse in z end closer to thumb (X)
	for (int y = 1; y <= 4; y++) {
		glTranslatef(0, 0.3, 0);
		glutSolidCube(0.25);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.325, 0.05, 0.535);//finger collapse in z end closer to thumb (X)
	for (int y = 1; y <= 4; y++) {
		glTranslatef(0, 0.3, 0);
		glutSolidCube(0.25);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.325, 0.05, 0.35); //finger touch the hand
	for (int y = 1; y <= 4; y++) {
		glTranslatef(0, 0.3, 0);
		glutSolidCube(0.25);
	}
	glPopMatrix();
}

void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); // x axis
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); // y axis
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, windowWidth, windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot, 0, 1, 0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1, (y - lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key - '0';
	if (key == 'q' || key == 'Q' || key == 27) {
		exit(0);
	}
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}