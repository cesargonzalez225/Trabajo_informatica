#include "Tablero.h"
#include "Tablero.h"
#include "Casilla.h"
#include "Alfil.h"
#include "Caballo.h"
#include "peon.h"
#include "rey.h"
#include "Reina.h"
#include "Torre.h"
#include "Logica.h"
Tablero sumamatrices(Tablero x, Tablero y)//suma las matrices
{
	Tablero tableroreturn;
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			tableroreturn.tablero[i][j] = x.tablero[i][j] + y.tablero[i][j];// Suma las matrices
		}
	}
	return tableroreturn;
	
}
Tablero multiplicamatrices(Tablero x, Tablero y)//multiplica los terminos de dentro 1 a 1 
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
			;
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
			;
		}
	}
	return tableroreturn;
}
Tablero forzarcomer(Tablero tablero, int turno)//devuelve una matriz con 1s y 0s que restringe donde se puede mover cualquier pieza
{//Hay que multiplicar la matriz con la de vermovimiento para ver cuales son las casillas reales a las que se puede mover
	
	Casilla origen;
	int x1, y1, x2, y2, i, j;
	Tablero movimientos1, movimientostotal;
	Tablero piezascontrario;
	Tablero tableroreturn;
	for (x1 = 0; x1 < 8;x1 ++)//Se hace una matriz que tiene como 0 las casillas a las que ninguna pieza se puede mover y >=1 a las que si
	{
		for (y1 = 0; y1 < 8; y1++)
		{
			
			if (tablero.tablero[x1][y1] < 0 && turno%2 == 0)//comprueba que sea turno blancas y que sea una pieza blanca
			{
				origen.x = x1;
				origen.y = y1;
				movimientos1 = vermovimiento(tablero, origen, turno);//saca las casillas a las que una pieza se puede mover
			}
			movimientostotal = sumamatrices(movimientostotal, movimientos1); //va sacando las casillas a las que el conjunto de las piezas se pueden mover

		}
	}
	for (int i = 0; i < 8; i++)//Se hace una matriz que tiene las piezas contrarias como 1 y el resto 0
	{
		for (int j = 0; j < 8; j++)
		{
			if ((tablero.tablero[i][j] > 0 && turno % 2 == 0) || (tablero.tablero[i][j] < 0 && turno % 2 != 0))//busca las piezas contrarias 
				piezascontrario.tablero[i][j] = 1;
			else
				piezascontrario.tablero[i][j] = 0;
		}
	}

	//se multiplican ambas matrices valores 1 a 1 para tener las unicas casillas a las que se pueden mover donde hay piezas enemigas
	tableroreturn = multiplicamatrices(movimientostotal, piezascontrario);

	for (int i = 0; i < 8; i++)//Se hace la matriz a devolver con 0s y 1s ya que puede haber valores mayor a 1
	{
		for (int j = 0; j < 8; j++)
		{
			if (tableroreturn.tablero[i][j] >= 1)//trasnforma los >=1 en 1 
				tableroreturn.tablero[i][j] = 1;
		}
	}

	//SI NO SE PUEDE COMER NINGUNA PIEZA 
	int cont = 0;
	for (int i = 0; i < 8; i++)//Comprueba si hay al menos un 1
	{
		for (int j = 0; j < 8; j++)
		{
			if (tableroreturn.tablero[i][j] >= 1)
				cont++;
		}
	}
	if (cont == 0)//si devuelve todo 0s se cambia a 1s para que las piezas puedan hacer cualquier movimiento ya que no tienen la obligacion de comer
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
					tableroreturn.tablero[i][j] = 1;
			}
		}
	}
	return tableroreturn;
}
