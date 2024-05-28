#pragma once
#include "Pieza.h"
#include "Tablero.h"
class Alfil : public Pieza
{
public:

	Alfil(void);
	virtual ~Alfil(void);
	Tablero tableroreturn;
	Tablero movimiento(Tablero tablero, Casilla origen);
};