#include <GLUT/glut.h>
#include "load-mesh.h"

void display(void);
void reshape(int, int);

int main(int argc, char** argv)
{
    load_mesh("/Users/Dong/Documents/Projects/graphics/xcode/PA3/PA3/bunny.obj");
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
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
    glTranslatef(0.1, -1, -1.5);
    glScalef(10, 10, 10);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 1000);
    
    glViewport(0, 0, 512, 512);
    
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < gTriangles.size(); i++) {
        int k0 = gTriangles[i].indices[0];
        int k1 = gTriangles[i].indices[1];
        int k2 = gTriangles[i].indices[2];
        
        Vector3 fstNorm = gNormals[k0];
        Vector3 sndNorm = gNormals[k1];
        Vector3 thrdNorm = gNormals[k2];
        
        Vector3 fstPos = gPositions[k0];
        Vector3 sndPos = gPositions[k1];
        Vector3 thrdPos = gPositions[k2];
        
        glNormal3f(fstNorm.x, fstNorm.y, fstNorm.z);
        glVertex3f(fstPos.x, fstPos.y, fstPos.z);
        
        glNormal3f(sndNorm.x, sndNorm.y, sndNorm.z);
        glVertex3f(sndPos.x, sndPos.y, sndPos.z);
        
        glNormal3f(thrdNorm.x, thrdNorm.y, thrdNorm.z);
        glVertex3f(thrdPos.x, thrdPos.y, thrdPos.z);
    }
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