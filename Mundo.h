#pragma once
#include "Pieza.h"
#include "Tablero.h"

class Mundo 
{
public:
	Mundo();
	virtual ~Mundo();

    	void dibuja(Tablero& );
	void dibujarPiezas(Tablero& );
};
