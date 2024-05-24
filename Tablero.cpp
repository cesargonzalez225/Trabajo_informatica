#pragma once
#include "Tablero.h"
#include "Casilla.h"

Tablero::~Tablero(void)
{
    
}

Tablero::Tablero(void)
{
	for (int i=0; i<8; i++) 
    {
		for (int j=0; j<8; j++) 
        {
			tablero[i][j] = Inicio[i][j];
		}
	}
}

int Tablero::Inicio[8][8]=
{ {5,3,4,8,7,4,3,5} , {1,1,1,1,1,1,1,1} , {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} , {0,0,0,0,0,0,0,0} , {-1,-1,-1,-1,-1,-1,-1,-1} , {-5,-3,-4,-8,-7,-4,-3,-5} };

int Tablero::leerCasilla(Casilla &casilla)
{
  return tablero[casilla.x][casilla.y];
}

void Tablero::reset()
{
	for (int i=0; i<8; i++) 
    {
		for (int j=0; j<8; j++) 
        {
			tablero[i][j] = Inicio[i][j];
		}
	}
}