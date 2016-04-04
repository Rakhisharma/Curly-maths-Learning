#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glVertex2s(2, 3);
	glVertex3d(0.0, 0.0, 3.1415926535898);
	glVertex4f(2.3, 1.0, −2.2, 2.0);
	GLdouble dvect[3] = {5.0, 9.0, 1992.0};
	glVertex3dv(dvect);

}
void init (void) 
{
	/* select clearing (background) color
	 * glClearColor (0.0, 0.0, 0.0, 0.0);
	 * initialize viewing values
	 */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
/*	glOrtho(0.0, 1.0, 0.0, 1.0, −1.0, 1.0);

	*/
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (250, 250);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("hello");
	init ();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	/* ISO C requires main to return int. */
}
