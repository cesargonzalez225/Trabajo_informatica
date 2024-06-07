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
	else if (estado == GAMEOVER)
	{
		ETSIDI::stopMusica();
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		ETSIDI::stopMusica();
		if (key == 'c')
			estado = INICIO;
	}
}

void CoordinadorAjedrez::raton(Casilla& casilla)
{
	using namespace std;
	std::cout << "Pieza:" << tablero.tablero[casilla.y - 1][casilla.x - 1] << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << tablero.tablero[i][j];
		}
		std::cout << endl;
	}
	if (casilla.x > 0 && casilla.x < 9 && casilla.y>0 && casilla.y < 9)
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
		ETSIDI::printxy("PULSE LA TECLA-E- PARA EMPEZAR", -3, -12);
		ETSIDI::printxy("PULSE LA TECLA-S- PARA SALIR", -3, -20);
		ETSIDI::printxy("Coding Grandmasters", -4, -45);



		glEnable(GL_TEXTURE_2D);




	}

	}
}
