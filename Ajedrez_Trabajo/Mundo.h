#pragma once
//#include "Pieza.h"
#include "Tablero.h"
#include "DibujarPiezas.h"

class Mundo
{

public:
	Mundo();
	virtual ~Mundo();

	void empezar();
	void dibuja();
	void dibujarPiezas();

	Tablero tablero;
};