
#include "Freeglut.h"
#include "Mundo.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

Mundo mundo;

void OnDraw(void);

int main(int argc, char* argv[]) 
{
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Tablero");

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1, 150);

    glutDisplayFunc(OnDraw);

    mundo.dibuja();

    glutMainLoop();

    return 0;
}

void OnDraw(void) 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 15, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);

    glutSwapBuffers();
}
