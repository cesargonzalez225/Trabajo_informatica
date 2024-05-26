//#include "freeglut.h"
//#include "DibujarTablero.h"
//
//void dibujarTablero() {
//    glPushMatrix();
//    glTranslatef(-4.0, 0, -4.0);
//
//    float tamañoCuadrado = 1.0f;
//    int tamañoTablero = 8;
//    //Dibujar el tablero
//    for (int i = 0; i < tamañoTablero; ++i) {
//        for (int j = 0; j < tamañoTablero; ++j) {
//            if ((i + j) % 2 == 0) {
//                glColor3f(1.0, 1.0, 1.0); //blanco
//            }
//            else {
//                glColor3f(0.0, 0.0, 0.0); //negro
//            }
//
//            glBegin(GL_QUADS);
//            glVertex3f(j * tamañoCuadrado, 0, i * tamañoCuadrado);
//            glVertex3f((j + 1) * tamañoCuadrado, 0, i * tamañoCuadrado);
//            glVertex3f((j + 1) * tamañoCuadrado, 0, (i + 1) * tamañoCuadrado);
//            glVertex3f(j * tamañoCuadrado, 0, (i + 1) * tamañoCuadrado);
//            glEnd();
//        }
//    }
//
//    // Dibujar los bordes
//    glColor3f(0.5, 0.5, 0.5); // Gris
//    glLineWidth(5.0); // grosor del borde del tablero
//
//    glBegin(GL_LINE_LOOP);
//    glVertex3f(0, 0, 0);
//    glVertex3f(tamañoTablero * tamañoCuadrado, 0, 0);
//    glVertex3f(tamañoTablero * tamañoCuadrado, 0, tamañoTablero * tamañoCuadrado);
//    glVertex3f(0, 0, tamañoTablero * tamañoCuadrado);
//    glEnd();
//
//    glPopMatrix();
//}
