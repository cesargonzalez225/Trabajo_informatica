#pragma once
#include "Tablero.h"
#include "Casilla.h"

Tablero::~Tablero(void)
{
    
}

Tablero::Tablero(void)
{
	for (int i=0; i<8; i++) 
    {
		for (int j=0; j<8; j++) 
        {
			tablero[i][j] = Inicio[i][j];
			iluminacion[i][j] = 0;
		}
	}
}

int Tablero::Inicio[8][8]=
{ {5,3,4,8,7,4,3,5} , {1,1,1,1,1,1,1,1} , {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0} , {-1,-1,-1,-1,-1,-1,-1,-1} , {-5,-3,-4,-8,-7,-4,-3,-5} };

void Tablero::dibuja()
{
glPushMatrix();
glTranslatef(-4, 0.1, -6.2);
float tamañoCuadrado = 1.0f;
int tamañoTablero = 8;

//Dibujar el tablero
for (int i = 0; i < tamañoTablero; ++i) 
{
	for (int j = 0; j < tamañoTablero; ++j) 
	{
		if (iluminacion[i][j] == 1) //Fija el código de colores a utilizar en la primera casilla
		{
			glColor3f(0.7, 0.1, 0.7);
		}
		else //Fija los colores del resto, diferenciando si la casilla tiene una posicion par o impar (sumando columnas y filas)
		{
			if ((i + j) % 2 == 0) 
			{
				glColor3f(0.1, 0.1, 0.7); //blanco
			}
			else 
			{
				glColor3f(0.0, 0.0, 0.2); //negro
			}
		}

		glBegin(GL_QUADS);
		glVertex3f(j * tamañoCuadrado, 0, i * tamañoCuadrado);
		glVertex3f((j + 1) * tamañoCuadrado, 0, i * tamañoCuadrado);
		glVertex3f((j + 1) * tamañoCuadrado, 0, (i + 1) * tamañoCuadrado);
		glVertex3f(j * tamañoCuadrado, 0, (i + 1) * tamañoCuadrado);
		glEnd();
	}
}

	// Dibujar los bordes
	glColor3f(0.5, 0.5, 0.5); // Gris
	glLineWidth(5.0); // grosor del borde del tablero

	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, 0);
	glVertex3f(tamañoTablero * tamañoCuadrado, 0, 0);
	glVertex3f(tamañoTablero * tamañoCuadrado, 0, tamañoTablero * tamañoCuadrado);
	glVertex3f(0, 0, tamañoTablero * tamañoCuadrado);
	glEnd();

glPopMatrix();

}
