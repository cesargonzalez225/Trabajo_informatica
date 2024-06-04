#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
public:
	Reina(void);
	virtual ~Reina(void);

	Tablero movimiento(Tablero tablero, Casilla origen);
};