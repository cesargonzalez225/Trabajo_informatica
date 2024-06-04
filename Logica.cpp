#include "Tablero.h"
#include "Tablero.h"
#include "Casilla.h"
#include "Alfil.h"
#include "Caballo.h"
#include "peon.h"
#include "rey.h"
#include "Reina.h"
#include "Torre.h"
Tablero sumamatrices(Tablero x, Tablero y)
{
	Tablero tableroreturn;
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			tableroreturn.tablero[i][j] = x.tablero[i][j] * y.tablero[i][j];// Suma las matrices
		}
	}
	return tableroreturn;
	
}
Tablero vermovimiento(Tablero tablero, Casilla origen, int turno)
{
	Alfil alfiltest;
	Torre torretest;
	Peon peontest;
	Rey reytest;
	Reina reinatest;
	Caballo caballotest;
	Tablero tableroreturn;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{	
			tableroreturn.tablero[i][j] = 0;
		}
	}
	int p = tablero.tablero[origen.x][origen.y];
	int c;
	if(turno%2==0&& tablero.tablero[origen.x][origen.y]<0) {// turno blancas
		switch (p) {
		case -1:
			tableroreturn = peontest.movimiento(tablero,origen);
			break;
		case -3:
			tableroreturn = alfiltest.movimiento(tablero, origen);
			break;
		case -4:
			tableroreturn = caballotest.movimiento(tablero, origen);
			break;
		case -5:
			tableroreturn = torretest.movimiento(tablero, origen);
			break;
		case -7:
			tableroreturn = reinatest.movimiento(tablero, origen);
			break;
		case -8:
			tableroreturn = reytest.movimiento(tablero, origen);
			break;
		default:

		}
	}
	if (turno % 2 != 0 && tablero.tablero[origen.x][origen.y] > 0) {// turno negras
		switch (p) {
		case 1:
			tableroreturn = peontest.movimiento(tablero, origen);
			break;
		case 3:
			tableroreturn = alfiltest.movimiento(tablero, origen);
			break;
		case 4:
			tableroreturn = caballotest.movimiento(tablero, origen);
			break;
		case 5:
			tableroreturn = torretest.movimiento(tablero, origen);
			break;
		case 7:
			tableroreturn = reinatest.movimiento(tablero, origen);
			break;
		case 8:
			tableroreturn = reytest.movimiento(tablero, origen);
			break;
		default:

		}
	}
	return tableroreturn;
}
Tablero forzarcomer(Tablero tablero, Casilla ultimomov, int turno){
{

	
	
}
