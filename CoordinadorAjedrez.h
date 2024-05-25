#pragma once
#include "Mundo.h"
#include "ETSIDI.h"
#include "Tablero.h"
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
protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO, FIN, GAMEOVER, PAUSA };
	Estado estado;
	Casilla origen, destino;
};
