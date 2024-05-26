#include "DibujarPiezas.h"
//#include "Piezas.h"
#include <math.h>

DibujarPiezas::DibujarPiezas(void)
{
}

DibujarPiezas::~DibujarPiezas(void)
{
}

void DibujarPiezas::dibujaPieza(int x, int y, const char* tex)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(tex).id);
	glDisable(GL_LIGHTING);
	glColor3ub(100, 100, 100);
	glColor3f(1, 1, 1);
	glPushMatrix();

	
	glTranslatef(x + -2.95f, 0.2f, y + -5.15f);
	glRotatef(-90, 1.0f, 0.0f, 0.0f); 
	glRotatef(180, 0.0f, 1.0f, 0.0f); 
	glBegin(GL_POLYGON);
	for (float angle = 0; angle < 2 * 3.14; angle += 0.1F)
	{
		float co = cos(-angle);
		float si = sin(-angle);
		
		glTexCoord2d(0.5 + 0.49 * co, 0.5 - 0.49 * si);
		glVertex3f(0.5 + 0.4 * co, 0.5 + 0.4 * si, 0.001);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
}

void DibujarPiezas::dibujaPeonNegra(int x, int y)
{
	const char* text = "imagenes/peonNegro.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaPeonBlanca(int x, int y)
{
	const char* text = "imagenes/peonBlanco.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaAlfilNegra(int x, int y)
{
	const char* text = "imagenes/alfilNegro.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaAlfilBlanca(int x, int y)
{
	const char* text = "imagenes/alfilBlanco.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaTorreNegra(int x, int y)
{
	const char* text = "imagenes/torreNegra.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaTorreBlanca(int x, int y)
{
	const char* text = "imagenes/torreBlanca.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaCaballoNegra(int x, int y)
{
	const char* text = "imagenes/caballoNegro.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaCaballoBlanca(int x, int y)
{
	const char* text = "imagenes/caballoBlanco.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaReyNegra(int x, int y)
{
	const char* text = "imagenes/reyNegro.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaReyBlanca(int x, int y)
{
	const char* text = "imagenes/reyBlanco.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaReinaNegra(int x, int y)
{
	const char* text = "imagenes/damaNegra.png";
	dibujaPieza(x, y, text);
}

void DibujarPiezas::dibujaReinaBlanca(int x, int y)
{
	const char* text = "imagenes/damaBlanca.png";
	dibujaPieza(x, y, text);
}
