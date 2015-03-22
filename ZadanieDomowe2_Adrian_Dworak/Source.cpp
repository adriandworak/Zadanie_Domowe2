#include <iostream>

#include <GL/freeglut.h>

const int glutWindowWidth = 640;
const int glutWindowHeight = 480;

struct Figura
{
	double x, y;
	double kolor = 0;
	int wybor=0;
}; 

Figura kwadrat, kolo, szesciokat;

float proportion = (float)glutWindowWidth / (float)glutWindowHeight;
float x, y;
void keyFunc(unsigned char key, int a, int b){

		if (key == 'q' && kwadrat.kolor != 1.0 && kolo.kolor != 1.0 && szesciokat.kolor != 1.0)
			kwadrat.kolor = 1.0, key = 'x';
		if (key == 'e' && kwadrat.kolor == 1.0)
		{
			kwadrat.kolor = 0.0;
			kolo.kolor = 1.0;
			key = 'x';
		}
		if (key == 'q' && kolo.kolor == 1.0)
		{
			kwadrat.kolor = 1.0;
			kolo.kolor = 0.0;
			key = 'x';
		}
		if (key == 'e' && kolo.kolor == 1.0)
		{
			kolo.kolor = 0.0;
			szesciokat.kolor = 1.0;
			key = 'x';
		}
		if (key == 'q' && szesciokat.kolor == 1.0)
		{
			szesciokat.kolor = 0.0;
			kolo.kolor = 1.0;
			key = 'x';
		}
	

		switch (key)
		{
		case 'w':
			if (kwadrat.kolor == 1.0)
			kwadrat.y += 0.1;
			if (kolo.kolor == 1.0)
				kolo.y += 0.1;
			if (szesciokat.kolor == 1.0)
				szesciokat.y += 0.1;
			break;
		case 'd':
			if (kwadrat.kolor == 1.0)
			kwadrat.x += 0.1;
			if (kolo.kolor == 1.0)
				kolo.x += 0.1;
			if (szesciokat.kolor == 1.0)
				szesciokat.x += 0.1;
			break;
		case 's':
			if (kwadrat.kolor == 1.0)
			kwadrat.y += -0.1;
			if (kolo.kolor == 1.0)
				kolo.y += -0.1;
			if (szesciokat.kolor == 1.0)
				szesciokat.y += -0.1;
			break;
		case 'a':
			if (kwadrat.kolor == 1.0)
			kwadrat.x += -0.1;
			if (kolo.kolor == 1.0)
				kolo.x += -0.1;
			if (szesciokat.kolor == 1.0)
				szesciokat.x += -0.1;
			break;
		case 'i':
			if (kwadrat.kolor == 1.0)
				kwadrat.wybor = 0;
			if (kolo.kolor == 1.0)
				kolo.wybor = 1;
			if (szesciokat.kolor == 1.0)
				szesciokat.wybor = 1;
			break;
		case 'o':
			if (kolo.kolor == 1.0)
				kolo.wybor = 0;
			if (kwadrat.kolor == 1.0)
				kwadrat.wybor = 1;
			if (szesciokat.kolor == 1.0)
				szesciokat.wybor = 2;
			break;
		case 'p':
			if (kolo.kolor == 1.0)
				kolo.wybor = 2;
			if (kwadrat.kolor == 1.0)
				kwadrat.wybor = 2;
			if (szesciokat.kolor == 1.0)
				szesciokat.wybor = 0;
			break;
	}
}


static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	proportion = ar;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void idle(void)
{
	glutPostRedisplay();
}
void DrawRectangle(void)
{
	glPushMatrix();
	glTranslated(-3, -2, 0);
	glTranslated(0, kwadrat.y, 0);
	glTranslated(kwadrat.x, 0, 0);
	glColor3d(kwadrat.kolor, 0, 0);
	glBegin(GL_POLYGON);
	if (kwadrat.wybor !=1 && kwadrat.wybor !=2)
	{
		glVertex3d(0, 0, 0);
		glVertex3d(1, 0, 0);
		glVertex3d(1, 1, 0);
		glVertex3d(0, 1, 0);
	}
	if (kwadrat.wybor == 1)
	{
		for (float a = 0; a < 2 * 3.14; a += 0.2)
		{
			glVertex3d(0.6*cos(a)+0.5, 0.6*sin(a)+0.5, 0);
		}
	}
	if (kwadrat.wybor==2)
	{
		glVertex3d(0.25, 0, 0);
		glVertex3d(0.75, 0, 0);
		glVertex3d(1, 0.5, 0);
		glVertex3d(0.75, 1, 0);
		glVertex3d(0.25, 1, 0);
		glVertex3d(0, 0.5, 0);
	}
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslated(-1, -2, 0);
		glTranslated(0, kolo.y, 0);
		glTranslated(kolo.x, 0, 0);
		glColor3d(kolo.kolor, 0, 0);
		glBegin(GL_POLYGON);
		if (kolo.wybor != 1 && kolo.wybor != 2)
		{
			for (float a = 0; a < 2 * 3.14; a += 0.2)
				glVertex3d(0.6*cos(a)+0.5, 0.6*sin(a)+0.5, 0);
		}
		if (kolo.wybor == 1)
		{
			glVertex3d(0, 0, 0);
			glVertex3d(1, 0, 0);
			glVertex3d(1, 1, 0);
			glVertex3d(0, 1, 0);
		}
		if (kolo.wybor == 2)
		{
			glVertex3d(0.25, 0, 0);
			glVertex3d(0.75, 0, 0);
			glVertex3d(1, 0.5, 0);
			glVertex3d(0.75, 1, 0);
			glVertex3d(0.25, 1, 0);
			glVertex3d(0, 0.5, 0);
		}
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(1, -2, 0);
		glTranslated(0, szesciokat.y, 0);
		glTranslated(szesciokat.x, 0, 0);
		glColor3d(szesciokat.kolor, 0, 0);
		glBegin(GL_POLYGON);



		if (szesciokat.wybor != 1 && szesciokat.wybor != 2)
		{
			glVertex3d(0.25, 0, 0);
			glVertex3d(0.75, 0, 0);
			glVertex3d(1, 0.5, 0);
			glVertex3d(0.75, 1, 0);
			glVertex3d(0.25, 1, 0);
			glVertex3d(0, 0.5, 0);
		}
		if (szesciokat.wybor == 1)
		{
			glVertex3d(0, 0, 0);
			glVertex3d(1, 0, 0);
			glVertex3d(1, 1, 0);
			glVertex3d(0, 1, 0);
		}
		if (szesciokat.wybor == 2)
		{
			for (float a = 0; a < 2 * 3.14; a += 0.2)
				glVertex3d(0.6*cos(a) + 0.5, 0.6*sin(a) + 0.5, 0);
		}
		glEnd();
		glPopMatrix();
		
}

static void display(void)
{
	// wyczyszenie sceny
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	DrawRectangle();
	glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	// it's still possible to use console to print messages
	printf("Hello openGL world!");
	kolo.kolor = 0.0;
	szesciokat.kolor = 0.0;
	kwadrat.kolor = 0.0;
	// the same can be done with cout / cin
	glutInitWindowSize(glutWindowWidth, glutWindowHeight);
	glutInitWindowPosition(40, 40);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("OpenGLUT Shapes");
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	// set white as clear colour
	glClearColor(0.536, 0.3425, 0.4663, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glutKeyboardFunc(keyFunc);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glutMainLoop();
	return 0;
}