#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
struct position
{
    float x;
    float y;
};
typedef struct position Position;

Position start;
Position finish;

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void circle(int a0, int b0, int a1, int b1)
{
    int i, x, y, x1, y1, r, p;

    x1 = (a0+a1)/2;
    y1 = (b0+b1)/2;

    r = sqrt((((a1-x1)*(a1-x1))+((b1-y1)*(b1-y1))));

    p = (5/4-r);
    x = 0;
    y = r;
    while(x <= y)
    {
        setPixel( x+x1,  y+y1);
        setPixel( x+x1, -y+y1);
        setPixel(-x+x1, -y+y1);
        setPixel(-x+x1,  y+y1);
        setPixel( y+x1,  x+y1);
        setPixel( y+x1, -x+y1);
        setPixel(-y+x1, -x+y1);
        setPixel(-y+x1,  x+y1);

        x = x+1;
        if (p<0)
            p = p+2*x+1;
        else {
            y = y-1;
            p = p+2*x-2*y+1;
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPushMatrix();

    circle(start.x, start.y, finish.x, finish.y);

    glPopMatrix();

    glutSwapBuffers();
}

void reshape( int w, int h)
{
    glViewport( 0, 0, w, h);
    glMatrixMode( GL_PROJECTION);
    glLoadIdentity();
    glOrtho( 0, w, h, 0, -1, 1);
}

void mouse(int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:

           if(state == GLUT_DOWN)
           {
               start.x = x; //x1
               start.y = y; //y1
           }

           if(state == GLUT_UP)
           {
               finish.x = x; //x2
               finish.y = y; //y2
           }
           break;

           glutPostRedisplay();
    }
}

void motion( int x, int y)
{
    finish.x = x;
    finish.y = y;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}


