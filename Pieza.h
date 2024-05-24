#pragma once
#include "Casilla.h"
#include "Tablero.h"

struct Jugada
{
	Casilla inicio, fin;
};

class Pieza
{
	Pieza();
	~Pieza();

	virtual bool mover(struct Jugada&);
	void nuevaPosicion(struct Jugada&);
	void escribirPosicion(Casilla&, int);

	bool comprobarColision(struct Jugada&);
	int leerCasilla(Casilla&);
	int getTurno();

	Jugada jugada;

	static Tablero* pTablero;
};

