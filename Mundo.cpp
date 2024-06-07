#include "Mundo.h"
#include "Tablero.h"

Mundo::Mundo()
{
}

Mundo::~Mundo()
{
}

void Mundo::dibuja(Tablero& tablero)
{
    tablero.dibuja();
    dibujarPiezas(tablero);
}

void Mundo::dibujarPiezas(Tablero& tablero)
{
	int pieza;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			DibujarPiezas dibujarPiezas;
	
			int m = i;
			int n = j;
			pieza = tablero.tablero[n][m];

			switch (pieza)
			{
			case -1:
				dibujarPiezas.dibujaPeonBlanca(m, n);
				break;
			case -3:
				dibujarPiezas.dibujaCaballoBlanca(m, n);
				break;
			case -4:
				dibujarPiezas.dibujaAlfilBlanca(m, n);
				break;
			case -5:
				dibujarPiezas.dibujaTorreBlanca(m, n);
				break;
			case -7:
				dibujarPiezas.dibujaReinaBlanca(m, n);
				break;
			case -8:
				dibujarPiezas.dibujaReyBlanca(m, n);
				break;

			case 1:
				dibujarPiezas.dibujaPeonNegra(m, n);
				break;
			case 3:
				dibujarPiezas.dibujaCaballoNegra(m, n);
				break;
			case 4:
				dibujarPiezas.dibujaAlfilNegra(m, n);
				break;
			case 5:
				dibujarPiezas.dibujaTorreNegra(m, n);
				break;
			case 7:
				dibujarPiezas.dibujaReinaNegra(m, n);
				break;
			case 8:
				dibujarPiezas.dibujaReyNegra(m, n);
				break;
                
			case 0:
				break;
			}
		}
	}
}
