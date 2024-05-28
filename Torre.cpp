#pragma once

#include "Torre.h"
#include <math.h>
Torre::Torre(void)
{

}

Torre::~Torre(void)
{

}

Tablero Torre::movimiento(Tablero tablero, Casilla origen)
{

	int x2 = 1, y2 = 1;
	int x1 = origen.x;
	int y1 = origen.y;
	int c = 0, s = 0, i = 1;
	Tablero tableroreturn;

	for (x2 = 1; x2 < 9; x2++)
	{
		for (y2 = 1; y2 < 9; y2++)
		{
			if ((x2 - x1) != 0 && (y2 - y1) != 0) {//Comprueba que tenga movimiento recto
				c = 1;
			}
			else if ((tablero.tablero[x1][y1] < 0 && tablero.tablero[x2][y2] < 0) || (tablero.tablero[x1][y1] > 0 && tablero.tablero[x2][y2] > 0)) { //Mira si es una pieza enemiga o vacia
				c = 1;
			}
			else if ((x2 - x1) > 0 && (y2 - y1) == 0)// Caso 1 Comprobacion derecha
			{
				while (c == 0 && x1 + i != x2)//Repetir bucle hasta que haya una ficha en medio o que llegue a p2
				{
					if (tablero.tablero[x1 + i][y1] != 0)//Si hay una ficha c=1
					{
						c = 1;
					}
					i++;
				}
			}
			else if ((x2 - x1) < 0 && (y2 - y1) == 0)// Caso 2 Comprobacion izquierda
			{
				while (c == 0 && x1 - i != x2)//Repetir bucle hasta que haya una ficha en medio o que llegue a p2
				{
					if (tablero.tablero[x1 - i][y1] != 0)//Si hay una ficha c=1
					{
						c = 1;
					}
					i++;
				}
			}
			else if ((x2 - x1) == 0 && (y2 - y1) < 0)// Caso 3 Comprobacion arriba
			{
				while (c == 0 && y1 - i != y2)//Repetir bucle hasta que haya una ficha en medio o que llegue a p2
				{
					if (tablero.tablero[x1][y1-i] != 0)//Si hay una ficha c=1
					{
						c = 1;
					}
					i++;
				}
			}
			else if ((x2 - x1) == 0 && (y2 - y1) > 0)// Caso 4 Comprobacion abajo
			{
				while (c == 0 && y1 + i != y2)//Repetir bucle hasta que haya una ficha en medio o que llegue a p2
				{
					if (tablero.tablero[x1][y1 + i] != 0)//Si hay una ficha c=1
					{
						c = 1;
					}
					i++;
				}
			}
			if (c == 0) {
				tableroreturn.tablero[x2][y2] = 1;
			}
			else {
				tableroreturn.tablero[x2][y2] = 0;
			}
		}
	}
	return tableroreturn;
}
