#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include "imageloader.h"

using namespace std;


//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
		//as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint grass_textureId; //The id of the texture
GLuint bricks_textureId; //The id of the texture
GLuint roof_textureId; //The id of the texture
GLuint door_textureId; //The id of the texture
GLuint window_textureId; //The id of the texture

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	Image* grassimage = loadBMP("grass.bmp");
	Image* bricksimage = loadBMP("bricks.bmp");
	Image* roofimage = loadBMP("roof.bmp");
	Image* doorimage = loadBMP("door.bmp");
	Image* windowimage = loadBMP("window.bmp");

	grass_textureId = loadTexture(grassimage);
	bricks_textureId = loadTexture(bricksimage);
	roof_textureId = loadTexture(roofimage);
	door_textureId = loadTexture(doorimage);
	window_textureId = loadTexture(windowimage);

	delete grassimage;
	delete bricksimage;
	delete roofimage;
	delete doorimage;
	delete windowimage;
}


void Draw() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); 
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glLoadIdentity();

	
	//door
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, door_textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(240, 300, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(290, 280, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(290, 200, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(240, 225, 0);
	glEnd();

	//window
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, window_textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(360, 265, 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(415, 280, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(415, 210, 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(360, 195, 0);
	glEnd();

	//front roof

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, roof_textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);*/
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(250, 400, 0);
	glTexCoord2f(2.0f, 0.0f);
	glVertex3f(420, 355, 0);
	glTexCoord2f(2.0f, 2.0f);
	glVertex3f(350, 270, 0);
	glTexCoord2f(0.0f, 2.0f);
	glVertex3f(175, 325, 0);
	glEnd();

	//roof triangle

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, bricks_textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(350, 275, 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(380, 350, 0);
	glTexCoord2f(0.0f, 2.0f);
	glVertex3f(425, 300, 0);
	glEnd();

	

	//right wall

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, bricks_textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(350, 275, 0);
	glTexCoord2f(2.0f, 0.0f);
	glVertex3f(425, 300, 0);
	glTexCoord2f(2.0f, 2.0f);
	glVertex3f(425, 200, 0);
	glTexCoord2f(0.0f, 2.0f);
	glVertex3f(350, 175, 0);
	glEnd();
	
	//back roof

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, roof_textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(380, 350, 0);
	glTexCoord2f(0.5f, 0.0f);
	glVertex3f(420, 355, 0);
	glTexCoord2f(0.5f, 0.5f);
	glVertex3f(450, 295, 0);
	glTexCoord2f(0.0f, 0.5f);
	glVertex3f(415, 295, 0);
	glEnd();

	//front wall

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, bricks_textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(200, 350, 0);
	glTexCoord2f(2.0f, 0.0f);
	glVertex3f(350, 275, 0);
	glTexCoord2f(2.0f, 2.0f);
	glVertex3f(350, 175, 0);
	glTexCoord2f(0.0f, 2.0f);
	glVertex3f(200, 250, 0);
	glEnd();

	//grass

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grass_textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glTexCoord2f(5.0f, 0.0f);
	glVertex3f(0, 300, 0);
	glTexCoord2f(5.0f, 5.0f);
	glVertex3f(500, 300, 0);
	glTexCoord2f(0.0f, 5.0f);
	glVertex3f(500, 0, 0);
	glEnd();

	
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}


void Initialize() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 500, 0, 500, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("House Texture");
	Initialize();
	initRendering();
	glColor3f(1.0, 1.0, 1.0);
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}