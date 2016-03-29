#include <GL/glew.h>
#include <GLUT/GLUT.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include "load-mesh.h"

void init(void);
void display(void);
void reshape(int, int);
void init_timer();
void start_timing();
float stop_timing();

float  gTotalTimeElapsed = 0;
int    gTotalFrames		 = 0;
GLuint gTimer;

int main(int argc, char** argv)
{
    load_mesh("/Users/Dong/Documents/Projects/graphics/xcode/PA3/PA3/bunny.obj");
    glutInit(&argc, argv);
    
    glutInitWindowSize(512, 512);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("PA3");
    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glClearColor(0,0,0,1);
    
//    init_timer();
    glutMainLoop();
    return 0;
}
void init() {
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    float ka[] = {1, 1, 1, 0};
    float kd[] = {1, 1, 1, 0};
    float ks[] = {0, 0, 0, 0};
    float p = 0;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ka);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, p);
    
    float Ia[] = {0.2, 0.2, 0.2, 0};
    float l[] = {1, 1, 1, 0};
    float la[] = {0, 0, 0, 0};
    float ld[] = {1, 1, 1, 0};
    float ls[] = {0, 0, 0, 0};
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Ia);
    glLightfv(GL_LIGHT0, GL_POSITION, l);
    glLightfv(GL_LIGHT0, GL_AMBIENT, la);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ld);
    glLightfv(GL_LIGHT0, GL_SPECULAR, ls);
    
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    start_timing();
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
    
//    float timeElapsed = stop_timing();
//    gTotalFrames++;
//    gTotalTimeElapsed += timeElapsed;
//    float fps = gTotalFrames / gTotalTimeElapsed;
//    char string[1024] = {0};
//    sprintf(string, "OpenGL Bunny : %0.2f FPS", fps);
//    glutSetWindowTitle(string);
//    glutPostRedisplay();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
    glTranslatef(0.1, -1, -1.5);
    glScalef(10, 10, 10);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 1000);
    
    glViewport(0, 0, 512, 512);
    glViewport(0,0,width,height);
}

void render() {
    GLuint vertexArray;
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
}


void init_timer()
{
    glGenQueries(1, &gTimer);
}

void start_timing()
{
    glBeginQuery(GL_TIME_ELAPSED, gTimer);
}

float stop_timing()
{
    glEndQuery(GL_TIME_ELAPSED);
    
    GLint available = GL_FALSE;
    while (available == GL_FALSE)
        glGetQueryObjectiv(gTimer, GL_QUERY_RESULT_AVAILABLE, &available);
    
    GLint result;
    glGetQueryObjectiv(gTimer, GL_QUERY_RESULT, &result);
    
    float timeElapsed = result / (1000.0f * 1000.0f * 1000.0f);
    return timeElapsed;
}