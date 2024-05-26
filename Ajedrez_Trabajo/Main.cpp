#include "ETSIDI.h"
#include "Freeglut.h"
#include "Mundo.h"
#include "CoordinadorAjedrez.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#include "iostream"
using namespace std;

Mundo mundo;
CoordinadorAjedrez Ajedrez;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void ControlRaton(int button, int state, int x, int y);

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Tablero1");

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1, 150);

    glutDisplayFunc(OnDraw);
    glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
    glutKeyboardFunc(OnKeyboardDown);
    glutMouseFunc(ControlRaton);
    glutMainLoop();

    return 0;
}

void OnDraw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);

    // Draw the textured background
   glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo9.png").id);
   glDisable(GL_LIGHTING);

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glTexCoord2d(0, 0); glVertex3d(-10, 0, -10);
    glTexCoord2d(1, 0); glVertex3d(10, 0, -10);
    glTexCoord2d(1, 1); glVertex3d(10, 0, 10);
    glTexCoord2d(0, 1); glVertex3d(-10, 0, 10);
    glEnd();
    //glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

   
    Ajedrez.dibuja();

    glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
    //poner aqui el código de teclado
    Ajedrez.tecla(key);
    glutPostRedisplay();
}

void ControlRaton(int button, int state, int x, int y)
{
    float w = glutGet(GLUT_WINDOW_WIDTH);
    float h = glutGet(GLUT_WINDOW_HEIGHT);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        Casilla casilla;
        x = x - 256;
        y = y- 79;
        if (0 <= x && x <= 35) {
            casilla.x = 1;
        }
        else if (35 < x && x <= 70) {
            casilla.x = 2;
        }
        else if (70 < x && x <= 105) {
            casilla.x = 3;
        }
        else if (105 < x && x <= 140) {
            casilla.x = 4;
        }
        else if (140 < x && x <= 175) {
            casilla.x = 5;
        }
        else if (175 < x && x <= 210) {
            casilla.x = 6;
        }
        else if (210 < x && x <= 245) {
            casilla.x = 7;
        }
        else if (245 < x && x <= 280) {
            casilla.x = 8;
        }

        if (0 <= y && y <= 35) {
            casilla.y = 1;
        }
        else if (35 < y && y <= 70) {
            casilla.y = 2;
        }
        else if (70 < y && y <= 105) {
            casilla.y = 3;
        }
        else if (105 < y && y <= 140) {
            casilla.y = 4;
        }
        else if (140 < y && y <= 175) {
            casilla.y = 5;
        }
        else if (175 < y && y <= 210) {
            casilla.y = 6;
        }
        else if (210 < y && y <= 245) {
            casilla.y = 7;
        }
        else if (245 < y && y <= 280) {
            casilla.y = 8;
        }

        std::cout << "Casilla:" << casilla.x << "," << casilla.y << endl;
        Ajedrez.raton(casilla);
    }

}

void OnTimer(int value)
{
    //poner aqui el código de animacion
   // Ajedrez.mueve();
    //no borrar estas lineas
    glutTimerFunc(25, OnTimer, 0);
    glutPostRedisplay();
}