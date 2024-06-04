#pragma once

#include "Pieza.h"

class Rey : public Pieza
{
public:
	Rey(void);
	virtual ~Rey(void);
	Tablero movimiento(Tablero tablero, Casilla origen);
};
