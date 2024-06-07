#pragma once

class Tablero
{
    static int Inicio[8][8];

public:
	Tablero(void);
	virtual ~Tablero(void);

int tablero[8][8]; //matriz de piezas del tablero
int iluminacion[8][8]; //matriz de casillas iluminadas del tablero

void dibuja();
int mover(Casilla, Casilla);
void ceroilum();
};

