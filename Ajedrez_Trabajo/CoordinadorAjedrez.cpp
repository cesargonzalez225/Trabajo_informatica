#include "CoordinadorAjedrez.h"
#include <stdio.h>
#include "DibujarPiezas.h"

CoordinadorAjedrez::CoordinadorAjedrez()
{
	estado = INICIO;
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
			mundo.dibuja();
		//	mundo.inicializa();
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		//mundo.tecla(key);
		if (key == 'p')
			estado = PAUSA;
	}
	else if (estado == PAUSA)
	{
		estado = JUEGO;
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
}

void CoordinadorAjedrez::raton(Casilla& casilla)
{
	if (casilla.x > -1 && casilla.x<8 && casilla.y>-1 && casilla.y < 8)
	{
		if ((origen.x == -100 && origen.y == -100) && mundo.tablero.leerCasilla(casilla) != 0 /*&& mundo.tablero.leerCasilla(casilla) / abs(mundo.tablero.leerCasilla(casilla)) == mundo.tablero.getTurno()*/)
		{
			origen.x = casilla.x;
			origen.y = casilla.y;
			/*printf("%d", origen.x);
			printf("%d", origen.y);*/

		}
		else if (destino.x == -100 && destino.y == -100 && origen.x != -100 && origen.y != -100)
		{
			destino.x = casilla.x;
			destino.y = casilla.y;
		}

		if (origen.x != -100 && origen.y != -100 && destino.x != -100 && destino.y != -100)
		{
			/*jugada jugadaAct;
			jugadaAct.origen = origen;
			jugadaAct.destino = destino;

			error = logicaAjedrez.jugadaAjedrez(jugadaAct);
			origen.x = -100; origen.y = -100; destino.x = -100; destino.y = -100;*/
		}
	}

}

void CoordinadorAjedrez::dibuja() {
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
	}
	else if (estado == JUEGO
		)
	{
		mundo.dibuja();
	}
	else if (estado == GAMEOVER
		)
	{
		mundo.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido",
			-5, 10);
		ETSIDI::printxy("Pulsa-C- para continuar",
			-5, 5);
	}
	else if (estado == FIN
		)
	{
		//mundo.dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!",
			-5, 10);
		ETSIDI::printxy("Pulsa-C- para continuar", -5, 9);
	}
}

