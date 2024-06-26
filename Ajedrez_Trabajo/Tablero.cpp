#pragma once
#include "Freeglut.h"
#include "Tablero.h"
#include "Casilla.h"


Tablero::~Tablero(void)
{

}

Tablero::Tablero(void)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablero[i][j] = Inicio[i][j];
		}
	}
}

int Tablero::Inicio[8][8] =
{ {5,3,4,8,7,4,3,5} , {1,1,1,1,1,1,1,1} , {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0} , {-1,-1,-1,-1,-1,-1,-1,-1} , {-5,-3,-4,-8,-7,-4,-3,-5} };

void Tablero::dibuja()
{

	glPushMatrix();
	glTranslatef(-4, 0.1, -6.2);
	float tamaņoCuadrado = 1.0f;
	int tamaņoTablero = 8;


	//Dibujar el tablero
	for (int i = 0; i < tamaņoTablero; ++i) {
		for (int j = 0; j < tamaņoTablero; ++j) {
			//multimiclar matriz javi por el for
			if ((i + j) % 2 == 0) {
				glColor3f(1.0, 1.0, 1.0); //blanco
			}
			else {
				glColor3f(0.0, 0.0, 0.0); //negro
			}

			glBegin(GL_QUADS);
			glVertex3f(j * tamaņoCuadrado, 0, i * tamaņoCuadrado);
			glVertex3f((j + 1) * tamaņoCuadrado, 0, i * tamaņoCuadrado);
			glVertex3f((j + 1) * tamaņoCuadrado, 0, (i + 1) * tamaņoCuadrado);
			glVertex3f(j * tamaņoCuadrado, 0, (i + 1) * tamaņoCuadrado);
			glEnd();
		}
	}

	// Dibujar los bordes
	glColor3f(0.5, 0.5, 0.5); // Gris
	glLineWidth(5.0); // grosor del borde del tablero

	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0);
	glVertex3f(tamaņoTablero * tamaņoCuadrado, 0, 0);
	glVertex3f(tamaņoTablero * tamaņoCuadrado, 0, tamaņoTablero * tamaņoCuadrado);
	glVertex3f(0, 0, tamaņoTablero * tamaņoCuadrado);
	glEnd();

	glPopMatrix();

}

int Tablero::leerCasilla(Casilla& casilla)
{
	return tablero[casilla.x][casilla.y];
}

void Tablero::reset()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablero[i][j] = Inicio[i][j];
		}
	}
}