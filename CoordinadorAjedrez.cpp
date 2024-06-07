#include "CoordinadorAjedrez.h"
#include <stdio.h>
#include "DibujarPiezas.h"
#include "iostream"

CoordinadorAjedrez::CoordinadorAjedrez()
{
	estado = INICIO;
	turno = BLANCAS;
	accion = 0;
	origen.x = -1;
	origen.y = -1;
	destino.x = -1;
	destino.y = -1;
}
CoordinadorAjedrez::~CoordinadorAjedrez()
{
}
void CoordinadorAjedrez::tecla(unsigned char key)
{
	if (estado == INICIO)
	{

		if (key == 'e')
		{
			ETSIDI::stopMusica();
			ETSIDI::play("sonidos/pistola.wav");
			mundo.dibuja(tablero);
			//	mundo.inicializa();
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		ETSIDI::stopMusica();
		//mundo.tecla(key);
		if (key == 'p')
		{
			ETSIDI::playMusica("sonidos/spaceinvaders.mp3", true);
			estado = PAUSA;
		}
	}
	else if (estado == PAUSA)
	{
		if (key == 'p')
		{
			ETSIDI::stopMusica();
			estado = JUEGO;
		}

	}
	else if (estado == GANANBLANCAS)
	{
		ETSIDI::stopMusica();
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == GANANNEGRAS)
	{
		ETSIDI::stopMusica();
		if (key == 'c')
			estado = INICIO;
	}
}

void CoordinadorAjedrez::raton(Casilla& casilla)
{
	using namespace std;
	std::cout << "Pieza:" << tablero.tablero[casilla.y-1][casilla.x-1] << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << tablero.tablero[i][j];
		}
		std::cout << endl;
	}
	if (casilla.x > 0 && casilla.x<9 && casilla.y>0 && casilla.y < 9)
	{
		if ((turno == NEGRAS && tablero.tablero[casilla.y - 1][casilla.x - 1] > 0) || (turno == BLANCAS && tablero.tablero[casilla.y - 1][casilla.x - 1] < 0))
		{
			origen.x = casilla.x;
			origen.y = casilla.y;
			accion = 1;
			std::cout << accion << endl;
		}
		else if (origen.x != -1 && (tablero.tablero[casilla.y - 1][casilla.x - 1] == 0 || (turno == NEGRAS && tablero.tablero[casilla.y - 1][casilla.x - 1] < 0) || (turno == BLANCAS && tablero.tablero[casilla.y - 1][casilla.x - 1] > 0)))
		{
			destino.x = casilla.x;
			destino.y = casilla.y;
			accion = 2;
			std::cout << accion << endl;
		}
	}

}

void CoordinadorAjedrez::dibuja() {
	int turnonum;
	using namespace std;
	if (estado == INICIO) {
		//glTranslatef(-4, 1, -4);
		/*gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);*/
		glTranslatef(-4, 1, -4);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Ajedrez",
			0, 0);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA-E- PARA EMPEZAR",-3, -12);
		ETSIDI::printxy("PULSE LA TECLA-S- PARA SALIR", -3, -20);
		ETSIDI::printxy("Coding Grandmasters", -4, -45);



		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/titulo.png").id);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDisable(GL_LIGHTING);

		int tam = 5;
		glPushMatrix();
		glTranslatef(4.0f, 0.0f, 0.1f);
		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 0.9);
		glTexCoord2d(0, 0); glVertex3d(-tam, 0, -tam);
		glTexCoord2d(1, 0); glVertex3d(tam, 0, -tam);
		glTexCoord2d(1, 1); glVertex3d(tam, 0, tam);
		glTexCoord2d(0, 1); glVertex3d(-tam, 0, tam);
		glEnd();
		glPopMatrix();

		glDisable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/texto.png").id);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDisable(GL_LIGHTING);

		tam = 1.1;
		int alarg = 3;
		glPushMatrix();
		glTranslatef(4.0f, 2.0f, 4.0f);
		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);
		glTexCoord2d(0, 0); glVertex3d(-tam - alarg, 0, -tam);
		glTexCoord2d(1, 0); glVertex3d(tam + alarg, 0, -tam);
		glTexCoord2d(1, 1); glVertex3d(tam + alarg, 0, tam);
		glTexCoord2d(0, 1); glVertex3d(-tam - alarg, 0, tam);
		glEnd();
		glPopMatrix();

		glDisable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);


	}
	else if (estado == JUEGO)
	{
		finalcheck(tablero);
		if (turno == BLANCAS)
			turnonum = 2;
		else
			turnonum = 1;
		if (accion == 1) {
			pieza.vermovimiento(tablero, origen, turnonum);
		}
		else if (accion == 2){
			if (tablero.mover(origen, destino) == 1) {
				accion = 0;
				origen.x = -1;
				origen.y = -1;
				tablero.ceroilum();
				if (turno == NEGRAS)
					turno = BLANCAS;
				else if (turno == BLANCAS)
					turno = NEGRAS;
			}
			else
				accion = 1;
			destino.x = -1;
			destino.y = -1;
		}
		mundo.dibuja(tablero);
	}
	else if (estado == GANANBLANCAS)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/gananNegras.png").id);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDisable(GL_LIGHTING);

		int tam = 2;
		int alarg = 3;
		glPushMatrix();
		glTranslatef(0.0f, 1.0f, -1.2f);
		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);
		glTexCoord2d(0, 0); glVertex3d(-tam - alarg, 0, -tam);
		glTexCoord2d(1, 0); glVertex3d(tam + alarg, 0, -tam);
		glTexCoord2d(1, 1); glVertex3d(tam + alarg, 0, tam);
		glTexCoord2d(0, 1); glVertex3d(-tam - alarg, 0, tam);
		glEnd();
		glPopMatrix();

		glDisable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
	}
	else if (estado == GANANNEGRAS)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/gananNegras.png").id);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDisable(GL_LIGHTING);

		int tam = 2;
		int alarg = 3;
		glPushMatrix();
		glTranslatef(0.0f, 1.0f, -1.2f);
		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);
		glTexCoord2d(0, 0); glVertex3d(-tam - alarg, 0, -tam);
		glTexCoord2d(1, 0); glVertex3d(tam + alarg, 0, -tam);
		glTexCoord2d(1, 1); glVertex3d(tam + alarg, 0, tam);
		glTexCoord2d(0, 1); glVertex3d(-tam - alarg, 0, tam);
		glEnd();
		glPopMatrix();

		glDisable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
	}
	else if (estado == PAUSA)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/pausa.png").id);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDisable(GL_LIGHTING);

		int tam = 2;
		int alarg = 3;
		glPushMatrix();
		glTranslatef(0.0f, 1.0f, -1.2f);
		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);
		glTexCoord2d(0, 0); glVertex3d(-tam - alarg, 0, -tam);
		glTexCoord2d(1, 0); glVertex3d(tam + alarg, 0, -tam);
		glTexCoord2d(1, 1); glVertex3d(tam + alarg, 0, tam);
		glTexCoord2d(0, 1); glVertex3d(-tam - alarg, 0, tam);
		glEnd();
		glPopMatrix();

		glDisable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
	}
}
void CoordinadorAjedrez::finalcheck(Tablero tablero)
{
	int pb = 0, pn = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tablero.tablero[i][j] < 0)
				pb = 1;
			if (tablero.tablero[i][j] > 0)
				pn = 1;
		}
	}
	if (pb == 0)
		estado = GANANNEGRAS;
	if (pn == 0)
		estado = GANANBLANCAS;

}
