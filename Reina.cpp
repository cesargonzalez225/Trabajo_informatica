#pragma once
#include "Reina.h"
#include "Alfil.h"
#include "Torre.h"
#include "Logica.h"
Reina::Reina(void)
{

}

Reina::~Reina(void)
{

}
Tablero Reina::movimiento(Tablero tablero, Casilla origen)
{
	Alfil alfildama;
	Torre torredama;
	int x2 = 1, y2 = 1;
	int x1 = origen.x;
	int y1 = origen.y;
	int c = 0, s = 0, i = 1;
	Tablero tableroreturn;
	Tablero TableroAlfil;
	Tablero TableroTorre;
	TableroAlfil= alfildama.movimiento(tablero, origen);
	TableroTorre = torredama.movimiento(tablero, origen);
	tableroreturn = sumamatrices(TableroAlfil, TableroTorre);
	return tableroreturn;
}
