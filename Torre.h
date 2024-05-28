#pragma once
#include "Pieza.h"
#include "Alfil.h"
class Torre : public Pieza
{
public:
	Torre(void);
	virtual ~Torre(void);

	Tablero movimiento(Tablero tablero, Casilla origen);
};