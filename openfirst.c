#include<GL/glut.h>
#include "minion.c"
main()
{
GLuint image;

/* assign it a reference. You can use any number */
glGenTextures(1, &gimp_image);

/* load the image into memory. Replace gimp_image with whatever the array is called in the .c file */
gluBuild2DMipmaps(GL_TEXTURE_2D, gimp_image.bytes_per_pixel, gimp_image.width, gimp_image.height, GL_RGBA, GL_UNSIGNED_BYTE, gimp_image.pixel_data);

/* enable texturing. If you don't do this, you won't get any image displayed */
glEnable(GL_TEXTURE_2D);

/* draw the texture to the screen, on a white box from (0,0) to (1, 1). Other shapes may be used. */
glColor3f(1.0, 1.0, 1.0);

/* you need to put a glTexCoord and glVertex call , one after the other, for each point */
glBegin(GL_QUADS);
glTexCoord2d(0.0, 1.0); glVertex2d(0.0, 0.0);
glTexCoord2d(0.0, 0.0); glVertex2d(0.0, 1.0);
glTexCoord2d(1.0, 0.0); glVertex2d(1.0, 1.0);
glTexCoord2d(1.0, 1.0); glVertex2d(1.0, 0.0);
glEnd();

/* clean up */
glDisable(GL_TEXTURE_2D);
glDeleteTextures(1, &logo);

return 0;
}
