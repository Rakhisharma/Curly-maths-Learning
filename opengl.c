#include<GL/gl.h>
#include<GL/glut.h>
main() 
{
	InitializeAWindowPlease();
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	/*
	 * glOrtho(0.0, 1.0, 0.0, 1.0, −1.0, 1.0);
	*/
	glBegin(GL_POLYGON);
	glVertex3f (0.25, 0.25, 0.0);
	glVertex3f (0.75, 0.25, 0.0);
	glVertex3f (0.75, 0.75, 0.0);
	glVertex3f (0.25, 0.75, 0.0);
	glEnd();
	glFlush();
	UpdateTheWindowAndCheckForEvents();
}
