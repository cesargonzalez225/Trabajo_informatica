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
	virtual int setTipo(int turno) { return 0; }
	int leerCasilla(Casilla&);
	int getTurno();
	void deshacerMovimiento(struct Jugada&);

	Jugada jugada;

	static Tablero* punteroTablero;
};

