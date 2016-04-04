/* This is open Gl notes for future reference*/
OpenGL is a software interface to graphics hardware. This interface consists of about 150 distinct
commands that you use to specify the objects and operations needed to produce interactive
three−dimensional applications

The major graphics operations which OpenGL performs to render an
image on the screen. 
1. Construct shapes from geometric primitives, thereby creating mathematical descriptions of objects.
(OpenGL considers points, lines, polygons, images, and bitmaps to be primitives.)
2. Arrange the objects in three−dimensional space and select the desired vantage point for viewing the
composed scene.
3. Calculate the color of all the objects. The color might be explicitly assigned by the application,
determined from specified lighting conditions, obtained by pasting a texture onto the objects, or
some combination of these three actions.
4. Convert the mathematical description of objects and their associated color information to pixels on
the screen. This process is called rasterization.
During these stages, OpenGL might perform other operations, such as eliminating parts of objects that
are hidden by other objects. In addition, after the scene is rasterized but before it’s drawn on the screen,
you can perform some operations on the pixel data if you want.


OpenGL Command Syntax:
Suffix Data Type Typical Corresponding OpenGL Type Definition
C−Language Type
b
s
i
f
d
ub
us
ui 8−bit integer
16−bit integer
32−bit integer
32−bit floating−point
64−bit floating−point
8−bit unsigned integer
16−bit unsigned integer
32−bit unsigned integer signed char
short
int or long
float
double
unsigned char
unsigned short
unsigned int or unsigned
long
GLbyte
GLshort
GLint, GLsizei
GLfloat, GLclampf
GLdouble, GLclampd
GLubyte, GLboolean
GLushort
GLuint, GLenum, GLbitfield
