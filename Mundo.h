#pragma once
#include "Pieza.h"
#include "Tablero.h"

class Mundo 
{
private:
    Tablero tablero;

public:
	Mundo();
	virtual ~Mundo();

    void dibuja();
};