#include <GL/gl.h> //include the gl header file
#include <GL/glut.h> //include the glut header file

void display (void) {
	glClearColor (0.0,0.0,0.0,1.0); //clear the color of the window
	glClear (GL_COLOR_BUFFER_BIT); //Clear teh Color Buffer (more buffers later on)
	glLoadIdentity(); //load the Identity Matrix
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //set the view
	glFlush(); //flush it all to the screen
}

int main (int argc, char **argv) {
	glutInit (&argc, argv); //initialize the program.
	glutInitDisplayMode (GLUT_SINGLE); //set up a basic display buffer (only singular for now)
	glutInitWindowSize (500, 500); //set whe width and height of the window
	glutInitWindowPosition (100, 100); //set the position of the window
	glutCreateWindow ("A basic OpenGL Window"); //set the caption for the window
	glutDisplayFunc (display); //call the display function to draw our world
	glutMainLoop (); //initialize the OpenGL loop cycle
	return 0;
}
