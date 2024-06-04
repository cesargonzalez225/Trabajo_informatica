#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
public:
	Peon(void);
	virtual ~Peon(void);

	Tablero movimiento(Tablero tablero, Casilla origen);
};