#pragma once
#include "Mundo.h"
#include "ETSIDI.h"
#include "Tablero.h"
#include "Pieza.h"
class CoordinadorAjedrez
{
public:
	CoordinadorAjedrez();
	int leerCasilla(Casilla& casilla);
	virtual ~CoordinadorAjedrez();
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	void raton(Casilla&);
	Tablero tablero;
	enum Turno {BLANCAS, NEGRAS};
	Turno turno;
	int accion; // 0:Ninguna pieza seleccionada  1:Una pieza seleccionada 2:Una pieza y un destino seleccionado
	void finalcheck(Tablero Tablero);
protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO, FIN, GAMEOVER, PAUSA };
	Estado estado;
	Casilla origen, destino;
	Pieza pieza;
};
