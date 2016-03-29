#include <GLUT/glut.h>


void display(void);
void reshape(int, int);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    glutInitWindowSize(512, 512);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("PA3");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glClearColor(0,0,0,1);
    
    glutMainLoop();
    return 0;
}

void display()
{
    /* clear the color buffer (resets everything to black) */
    glClear(GL_COLOR_BUFFER_BIT);
    
    /* set the current drawing color to red */
    glColor3f(1, 0, 0);
    
    glBegin(GL_TRIANGLES);
    
    glVertex2f(10, 10);
    glVertex2f(250, 400);
    glVertex2f(400, 10);
    
    glEnd();
    
    /* swap the back and front buffers so we can see what we just drew */
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0,0,width,height);
    
    /* switch to the projection matrix */
    glMatrixMode(GL_PROJECTION);
    
    /* clear the projection matrix */
    glLoadIdentity();
    
    /* set the camera view, orthographic projection in 2D */
    gluOrtho2D(0,width,0,height);
    
    /* switch back to the model view matrix */
    glMatrixMode(GL_MODELVIEW);
}