#pragma once

#include "Pieza.h"

class Caballo : public Pieza
{
public:
	Caballo(void);
	virtual ~Caballo(void);

	Tablero movimiento(Tablero tablero, Casilla origen);
};