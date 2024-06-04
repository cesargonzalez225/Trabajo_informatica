#pragma once
#include "Caballo.h"

Caballo::Caballo(void)
{
}

Caballo::~Caballo(void)
{
}

Tablero Caballo::movimiento(Tablero tablero, Casilla origen)
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
			c = 0;

				if (((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) != 5)//Comprueba que pueda hacer el movimiento comprobando si la suma de los catetos al cudrado es igual a 5
					c = 1;
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
