#pragma once
#include <math.h>
#include "Pieza.h"
#include "Tablero.h"
#include "iostream"
Pieza::Pieza()
{

}
Pieza::~Pieza()
{

}
void Pieza::vermovimiento(Tablero& tablero, Casilla origen, int turno)
{
	forzarcomer(tablero, turno);
	movimientos(tablero, origen, turno);
	iluminado = multiplicamatrices(matriz, matrizcomer);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablero.iluminacion[i][j] = iluminado.tablero[i][j];
		}
	}
}
void Pieza::movimientos(Tablero tablero, Casilla origen, int turno)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			matriz.tablero[i][j] = 0;
		}
	}
	int p = tablero.tablero[origen.y - 1][origen.x - 1];
	int c;
	if (turno % 2 == 0 && tablero.tablero[origen.y - 1][origen.x - 1] < 0) {// turno blancas
		switch (p) {
		case -1:
			movimientoPeon(tablero, origen);
			break;
		case -3:
			movimientoCaballo(tablero, origen);
			break;
		case -4:
			movimientoAlfil(tablero, origen);//caballo
			break;
		case -5:
			movimientoTorre(tablero, origen);//torre
			break;
		case -8:
			movimientoReina(tablero, origen);//reina
			break;
		case -7:
			movimientoRey(tablero, origen);//rey
			break;
		default:
			;
		}
	}
	if (turno % 2 != 0 && tablero.tablero[origen.y - 1][origen.x - 1] > 0) {// turno negras
		switch (p) {
		case 1:
			movimientoPeon(tablero, origen);
			break;
		case 3:
			movimientoCaballo(tablero, origen);
			break;
		case 4:
			movimientoAlfil(tablero, origen);//caballo
			break;
		case 5:
			movimientoTorre(tablero, origen);//torre
			break;
		case 8:
			movimientoReina(tablero, origen);//reina
			break;
		case 7:
			movimientoRey(tablero, origen);//rey
			break;
		default:
			;
		}
	}
}
void Pieza::movimientoPeon(Tablero tablero, Casilla origen)
 {
	 using namespace std;
	 int x2 = 1, y2 = 1;
	 int x1 = origen.x;
	 int y1 = origen.y;
	 int c = 0;

	 for (x2 = 1; x2 < 9; x2++)
	 {
		 for (y2 = 1; y2 < 9; y2++)
		 {
			 c = 0;
			 if (tablero.tablero[y1-1][x1-1] > 0)// Peon negro
			 {
				 //Caso 1:Se mueve 1 solo para arriba, movimiento normal
				 if (x2 - x1 == 0 && y2 - y1 == 1)
				 {
					 if (tablero.tablero[y2-1][x2-1] == 0)
						 c = 1;
				 }
				 //Caso 2:Se mueve dos para arriba, movimento doble
				 else if ((x2 - x1 == 0 && y2 - y1 == 2) && y1 == 2)//Comprueba que se quiera subir dos y que este en la fila 2
				 {
					 if (tablero.tablero[y2-2][x2 - 1] == 0 && tablero.tablero[y2-1][x2-1] == 0)
						 c = 1;			//comprueba que las dos casillas de arriba esten vacias	
				 }
				 //Caso 3:Come en diagonal hacia la nuestra derecha, tambien al paso
				 else if (x2 - x1 == (1) && y2 - y1 == 1)
				 {
					 if (tablero.tablero[y2-1][x2-1] < 0)//comprueba que la ficha que te quieres comer es enemiga
						 c = 1;
					 /*if (tablero.tablero[y2 - 1][x2] == -1)//comprueba que la ficha que te tienes al lado es un peon blanco
						 c = 1;*/
				 }
				 //Caso 4:Come en diagonal hacia nuestra izquierda, tambien al paso
				 else if (x2 - x1 == (-1) && y2 - y1 == 1)
				 {
					 if (tablero.tablero[y2-1][x2-1] < 0)//comprueba que la ficha que te quieres comer es enemiga
						 c = 1;
					 /*if (tablero.tablero[y2 - 1][x2 - 2] == -1)//comprueba que la ficha que te tienes al lado es un peon blanco
						 c = 1;*/
				 }
			 }
			 if (tablero.tablero[y1-1][x1-1] < 0)// Peon blanco
			 {
				 //Caso 1:Se mueve 1 solo para arriba, movimiento normal
				 if (x2 - x1 == 0 && y2 - y1 == -1)
				 {
					 if (tablero.tablero[y2-1][x2-1] == 0)
						 c = 1;
				 }
				 //Caso 2:Se mueve dos para arriba, movimento doble
				 else if ((x2 - x1 == 0 && y2 - y1 == -2) && y1 == 7)//Comprueba que se quiera subir dos y que este en la fila 2
				 {
					 if (tablero.tablero[y2][x2 -1] == 0 && tablero.tablero[y2-1][x2-1] == 0)
						 c = 1;			//comprueba que las dos casillas de arriba esten vacias	
				 }
				 //Caso 3:Come en diagonal hacia la nuestra derecha, tambien al paso
				 else if (x2 - x1 == 1 && y2 - y1 == -1)
				 {
					 if (tablero.tablero[y2-1][x2-1] > 0)//comprueba que la ficha que te quieres comer es enemiga
						 c = 1;
					 /*if (tablero.tablero[x2 + 1][y1] == 1)//comprueba que la ficha que te tienes al lado es un peon blanco
						 c = 1;*/
				 }
				 //Caso 4:Come en diagonal hacia nuestra izquierda, tambien al paso
				 else if (x2 - x1 == (-1) && y2 - y1 == -1)
				 {
					 if (tablero.tablero[y2-1][x2-1] > 0)// comprueba que la ficha que te quieres comer es enemiga
						 c = 1;
					 /*if (tablero.tablero[y2 - 1][x1 - 2] == 1)// comprueba que la ficha que te tienes al lado es un peon blanco
						 c = 1;*/
				 }
			 }
			 if (c == 0) {
				 matriz.tablero[y2-1][x2-1] = 0;
			 }
			 else {
				 matriz.tablero[y2-1][x2-1] = 1;
			 }
			 
		 }
		
	 }
 }
 void Pieza::movimientoRey(Tablero tablero, Casilla origen)
 {
	 int x2 = 1, y2 = 1;
	 int x1 = origen.x;
	 int y1 = origen.y;
	 int c = 0, s = 0, i = 1;

	 for (x2 = 1; x2 < 9; x2++)
	 {
		 for (y2 = 1; y2 < 9; y2++)
		 {
			 c = 0;


			 if ((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) <= 2) && ((tablero.tablero[y1 - 1][x1 - 1] < 0 && tablero.tablero[y2 - 1][x2 - 1] >= 0) || (tablero.tablero[y1 - 1][x1 - 1] > 0 && tablero.tablero[y2 - 1][x2 - 1] <= 0)))//Comprueba que pueda hacer el movimiento comprobando si la suma de los catetos al cudrado es igual a 5
				 c = 1;

			 if (c == 1) {
				 matriz.tablero[y2 - 1][x2 - 1] = 1;
			 }
			 else {
				 matriz.tablero[y2 - 1][x2 - 1] = 0;
			 }
		 }
	 }
 }
 void Pieza::movimientoTorre(Tablero tablero, Casilla origen)
 {
	 int x2 = 1, y2 = 1;
	 int x1 = origen.x;
	 int y1 = origen.y;
	 int c = 0, s = 0, i = 1;

	 for (x2 = 1; x2 < 9; x2++)
	 {
		 for (y2 = 1; y2 < 9; y2++)
		 {
			 i = 1;
			 c = 0;
			 if ((x2 - x1) != 0 && (y2 - y1) != 0) {//Comprueba que tenga movimiento recto
				 c = 1;
			 }
			 else if ((tablero.tablero[y1 - 1][x1 - 1] < 0 && tablero.tablero[y2 - 1][x2 - 1] < 0) || (tablero.tablero[y1 - 1][x1 - 1] > 0 && tablero.tablero[y2 - 1][x2 - 1] > 0)) { //Mira si es una pieza enemiga o vacia
				 c = 1;
			 }
			 else if ((x2 - x1) > 0 && (y2 - y1) == 0)// Caso 1 Comprobacion derecha
			 {
				 while (c == 0 && x1 + i != x2)//Repetir bucle hasta que haya una ficha en medio o que llegue a p2
				 {
					 if (tablero.tablero[y1 - 1][x1 + i - 1] != 0)//Si hay una ficha c=1
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
					 if (tablero.tablero[y1 - 1][x1 - i - 1] != 0)//Si hay una ficha c=1
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
					 if (tablero.tablero[y1 - i - 1][x1 - 1] != 0)//Si hay una ficha c=1
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
					 if (tablero.tablero[y1 + i - 1][x1 - 1] != 0)//Si hay una ficha c=1
					 {
						 c = 1;
					 }
					 i++;
				 }
			 }
			 if (c == 0) {
				 matriz.tablero[y2 - 1][x2 - 1] = 1;
			 }
			 else {
				 matriz.tablero[y2 - 1][x2 - 1] = 0;
			 }
		 }
	 }
 }
 void Pieza::movimientoAlfil(Tablero tablero, Casilla origen)
 {
	 int x2 = 1, y2 = 1;
	 int x1 = origen.x;
	 int y1 = origen.y;
	 int c = 0, s = 0, i = 1;

	 for (x2 = 1; x2 < 9; x2++)
	 {
		 for (y2 = 1; y2 < 9; y2++)
		 {
			 c = 0;
			 if ((tablero.tablero[y1 - 1][x1 - 1] < 0 && tablero.tablero[y2 - 1][x2 - 1] < 0) || (tablero.tablero[y1 - 1][x1 - 1] > 0 && tablero.tablero[y2 - 1][x2 - 1] > 0)) {	//Mira si es una pieza enemiga o vacia
				 c = 1;
			 }
			 else if (abs(x2 - x1) != abs(y2 - y1)) {		//Mira si esta fuera de diagonales 
				 c = 1;
			 }
			 else if ((x2 - x1) > 0 && (y2 - y1) > 0)// Caso 1 Comprobacion abajo derecha
			 {
				 while (c == 0 && x1 + i != x2)//Repetir bucle hasta que haya una ficha en medio o que llegue a p2
				 {
					 if (tablero.tablero[y1][x1] != 0)//Si hay una ficha c=1
					 {
						 c = 1;
					 }
					 i++;
				 }
			 }
			 else if ((x2 - x1) > 0 && (y2 - y1) < 0)// Caso 2 Comprobacion arriba derecha
			 {
				 while (c == 0 && x1 + i != x2)//Repetir bucle hasta que haya una ficha en medio o que llegue a p2
				 {
					 if (tablero.tablero[y1 - 2][x1] != 0)//Si hay una ficha c=1
					 {
						 c = 1;
					 }
					 i++;
				 }
			 }
			 else if ((x2 - x1) < 0 && (y2 - y1) > 0)// Caso 3 Comprobacion abajo izquierda
			 {
				 while (c == 0 && x1 - i != x2)//Repetir bucle hasta que haya una ficha en medio o que llegue a p2
				 {
					 if (tablero.tablero[y1][x1 - 2] != 0)//Si hay una ficha c=1
					 {
						 c = 1;
					 }
					 i++;
				 }
			 }
			 else if ((x2 - x1) < 0 && (y2 - y1) < 0)// Caso 4 Comprobacion arriba izquierda
			 {
				 while (c == 0 && x1 - i != x2)//Repetir bucle hasta que haya una ficha en medio o que llegue a p2
				 {
					 if (tablero.tablero[y1 - 2][x1 - 2] != 0)//Si hay una ficha c=1
					 {
						 c = 1;
					 }
					 i++;
				 }
			 }
			 if (c == 0) {
				 matriz.tablero[y2 - 1][x2 - 1] = 1;
			 }
			 else {
				 matriz.tablero[y2 - 1][x2 - 1] = 0;
			 }
		 }
	 }
 }
 void Pieza::movimientoCaballo(Tablero tablero, Casilla origen)
 {
	 int x2 = 1, y2 = 1;
	 int x1 = origen.x;
	 int y1 = origen.y;
	 int c = 0, s = 0, i = 1;

	 for (x2 = 1; x2 < 9; x2++)
	 {
		 for (y2 = 1; y2 < 9; y2++)
		 {
			 c = 0;

			 if ((((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) != 5) || (tablero.tablero[y1-1][x1-1] < 0 && tablero.tablero[y2-1][x2-1] < 0) || (tablero.tablero[y1-1][x1-1] > 0 && tablero.tablero[y2-1][x2-1] > 0))//Comprueba que pueda hacer el movimiento comprobando si la suma de los catetos al cudrado es igual a 5
				 c = 1;

			 if (c == 0) {
				 matriz.tablero[y2-1][x2-1] = 1;
			 }
			 else {
				 matriz.tablero[y2-1][x2-1] = 0;
			 }
		 }
	 }
 }
 void Pieza::movimientoReina(Tablero tablero, Casilla origen)
 {
	 Tablero TableroAlfil;
	 Tablero TableroTorre;
	 movimientoTorre(tablero, origen);
	 TableroTorre = matriz;
	 movimientoAlfil(tablero, origen);
	 TableroAlfil = matriz;
	 matriz = sumamatrices(TableroAlfil, TableroTorre);
 }
 void Pieza::forzarcomer(Tablero tablero, int turno)//devuelve una matriz con 1s y 0s que restringe donde se puede mover cualquier pieza
 {//Hay que multiplicar la matriz con la de vermovimiento para ver cuales son las casillas reales a las que se puede mover

	 Casilla origen;
	 int x1, y1, x2, y2, i, j;
	 Tablero movimientostotal;
	 Tablero piezascontrario;
	 for (x1 = 0; x1 < 8; x1++)//Se hace una matriz que tiene como 0 las casillas a las que ninguna pieza se puede mover y >=1 a las que si
	 {
		 for (y1 = 0; y1 < 8; y1++)
		 {

			 if (tablero.tablero[x1][y1] < 0 && turno % 2 == 0)//comprueba que sea turno blancas y que sea una pieza blanca
			 {
				 origen.x = x1;
				 origen.y = y1;
				 movimientos(tablero, origen, turno);//saca las casillas a las que una pieza se puede mover
			 }
			 movimientostotal = sumamatrices(movimientostotal, matriz); //va sacando las casillas a las que el conjunto de las piezas se pueden mover

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
	 matrizcomer = multiplicamatrices(movimientostotal, piezascontrario);

	 for (int i = 0; i < 8; i++)//Se hace la matriz a devolver con 0s y 1s ya que puede haber valores mayor a 1
	 {
		 for (int j = 0; j < 8; j++)
		 {
			 if (matrizcomer.tablero[i][j] >= 1)//trasnforma los >=1 en 1 
				 matrizcomer.tablero[i][j] = 1;
		 }
	 }

	 //SI NO SE PUEDE COMER NINGUNA PIEZA 
	 int cont = 0;
	 for (int i = 0; i < 8; i++)//Comprueba si hay al menos un 1
	 {
		 for (int j = 0; j < 8; j++)
		 {
			 if (matrizcomer.tablero[i][j] >= 1)
				 cont++;
		 }
	 }
	 if (cont == 0)//si devuelve todo 0s se cambia a 1s para que las piezas puedan hacer cualquier movimiento ya que no tienen la obligacion de comer
	 {
		 for (int i = 0; i < 8; i++)
		 {
			 for (int j = 0; j < 8; j++)
			 {
				 matrizcomer.tablero[i][j] = 1;
			 }
		 }
	 }
 }
 Tablero Pieza::sumamatrices(Tablero x, Tablero y)//suma las matrices
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
 Tablero Pieza::multiplicamatrices(Tablero x, Tablero y)//multiplica los terminos de dentro 1 a 1 
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
