#include <GL/gl.h>
#include <GL/glut.h>
#define drawOneLine(x1,y1,x2,y2) glBegin(GL_LINES); \
	glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();
void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}
void display(void)
{
	int i;
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLineWidth (5.0);
	glLineStipple (1, 0x0101); /* dotted */
	drawOneLine (200.0, 125.0, 150.0, 125.0);
	glLineStipple (1, 0x00FF); /* dashed */
	drawOneLine (150.0, 125.0, 250.0, 125.0);
	glLineStipple (1, 0x1C47); /* dash/dot/dash */
	drawOneLine (250.0, 125.0, 350.0, 125.0);
	/* in 2nd row, 3 wide lines, each with different stipple */
	glLineWidth (4.50);
	glLineStipple (1, 0x0101); /* dotted */
	drawOneLine (120.0, 100.0, 150.0, 100.0);
	glLineStipple (1, 0x00FF); /* dashed */
	drawOneLine (150.0, 100.0, 250.0, 100.0);
	glLineStipple (1, 0x1C47); /* dash/dot/dash */
	drawOneLine (250.0, 100.0, 350.0, 100.0);
	
	/* in 3rd row, 6 lines, with dash/dot/dash stipple */
	/* as part of a single connected line strip
	 * */
	 glLineWidth (3.50);
	glLineStipple (1, 0x1C47); /* dash/dot/dash */
	glBegin (GL_LINE_STRIP);
	for (i = 0; i < 7; i++)
		glVertex2f (80.0 + ((GLfloat) i * 45.0), 75.0);
	glEnd ();
	/* in 4th row, 6 independent lines with same stipple */
	glLineWidth (2.50);
	for (i = 0; i < 6; i++) {
		drawOneLine (52.0 + ((GLfloat) i * 50.0), 50.0,
				52.0 + ((GLfloat)(i+1) * 50.0), 50.0);
	}
	/* in 5th row, 1 line, with dash/dot/dash stipple
	 * */
	/* and a stipple repeat factor of 5
	 * */
	 glLineWidth (1.0);
	glLineStipple (5, 0x1C47); /* dash/dot/dash */
	drawOneLine (50.0, 25.0, 350.0, 25.0);
	glDisable (GL_LINE_STIPPLE);
	glFlush ();
}
void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (400, 150);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
