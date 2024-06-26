//#include "freeglut.h"
//#include "DibujarTablero.h"
//
//void dibujarTablero() {
//    glPushMatrix();
//    glTranslatef(-4.0, 0, -4.0);
//
//    float tamaņoCuadrado = 1.0f;
//    int tamaņoTablero = 8;
//    //Dibujar el tablero
//    for (int i = 0; i < tamaņoTablero; ++i) {
//        for (int j = 0; j < tamaņoTablero; ++j) {
//            if ((i + j) % 2 == 0) {
//                glColor3f(1.0, 1.0, 1.0); //blanco
//            }
//            else {
//                glColor3f(0.0, 0.0, 0.0); //negro
//            }
//
//            glBegin(GL_QUADS);
//            glVertex3f(j * tamaņoCuadrado, 0, i * tamaņoCuadrado);
//            glVertex3f((j + 1) * tamaņoCuadrado, 0, i * tamaņoCuadrado);
//            glVertex3f((j + 1) * tamaņoCuadrado, 0, (i + 1) * tamaņoCuadrado);
//            glVertex3f(j * tamaņoCuadrado, 0, (i + 1) * tamaņoCuadrado);
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
//    glVertex3f(tamaņoTablero * tamaņoCuadrado, 0, 0);
//    glVertex3f(tamaņoTablero * tamaņoCuadrado, 0, tamaņoTablero * tamaņoCuadrado);
//    glVertex3f(0, 0, tamaņoTablero * tamaņoCuadrado);
//    glEnd();
//
//    glPopMatrix();
//}
