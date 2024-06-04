#pragma once
#include "Peon.h"

Tablero Peon::movimiento(Tablero tablero, Casilla origen)
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
			c = 1;
			if (tablero.tablero[x1][y1] > 0)// Peon negro
			{
				
				//Caso 1:Se mueve 1 solo para arriba, movimiento normal
				if (x2 - x1 == (0) && y2-y1 == 1)
				{
					if (tablero.tablero[x1][y2] == 0)
							c = 0;
				}
				//Caso 2:Se mueve dos para arriba, movimento doble
				else if ((x2-x1 == 0 && y2-y1 == 2) && y1 == 2)//Comprueba que se quiera subir dos y que este en la fila 2
				{
					if (tablero.tablero[x1][y2-1] == 0 && tablero.tablero[x1][y2] == 0)
						c = 0;			//comprueba que las dos casillas de arriba esten vacias	
				}
				//Caso 3:Come en diagonal hacia la nuestra derecha, tambien al paso
				else if (x2-x1 == (1) && y2-y1 == 1)
				{
					if (tablero.tablero[x2][y2] < 0)//comprueba que la ficha que te quieres comer es enemiga
						c = 0;
					if (tablero.tablero[x2+1][y1] == -1)//comprueba que la ficha que te tienes al lado es un peon blanco
						c = 0;
				}
				//Caso 4:Come en diagonal hacia nuestra izquierda, tambien al paso
				else if (x2 - x1 == (-1) && y2 - y1 == 1)
				{
					if (tablero.tablero[x2][y2] < 0)//comprueba que la ficha que te quieres comer es enemiga
						c = 0;
					if (tablero.tablero[x2-1][y1] == -1)//comprueba que la ficha que te tienes al lado es un peon blanco
						c = 0;
				}
			}
			if (tablero.tablero[x1][y1] < 0)// Peon blanco
			{

				//Caso 1:Se mueve 1 solo para arriba, movimiento normal
				if (x2 - x1 == (0) && y2 - y1 == -1)
				{
					if (tablero.tablero[x1][y2] == 0)
						c = 0;
				}
				//Caso 2:Se mueve dos para arriba, movimento doble
				else if ((x2 - x1 == 0 && y2 - y1 == -2) && y1 == 7)//Comprueba que se quiera subir dos y que este en la fila 2
				{
					if (tablero.tablero[x1][y2 + 1] == 0 && tablero.tablero[x1][y2] == 0)
						c = 0;			//comprueba que las dos casillas de arriba esten vacias	
				}
				//Caso 3:Come en diagonal hacia la nuestra derecha, tambien al paso
				else if (x2 - x1 == (1) && y2 - y1 == -1)
				{
					if (tablero.tablero[x2][y2] > 0)//comprueba que la ficha que te quieres comer es enemiga
						c = 0;
					if (tablero.tablero[x2 + 1][y1] == 1)//comprueba que la ficha que te tienes al lado es un peon blanco
						c = 0;
				}
				//Caso 4:Come en diagonal hacia nuestra izquierda, tambien al paso
				else if (x2 - x1 == (-1) && y2 - y1 == -1)
				{
					if (tablero.tablero[x2][y2] > 0)// comprueba que la ficha que te quieres comer es enemiga
						c = 0;
					if (tablero.tablero[x2 - 1][y1] == 1)// comprueba que la ficha que te tienes al lado es un peon blanco
						c = 0;
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