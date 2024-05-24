#pragma once
#include "Pieza.h"

Pieza::~Pieza()
{
}

bool Pieza::mover(Jugada &)
{
    return false;
}

void Pieza::nuevaPosicion(Jugada &)
{
}

void Pieza::escribirPosicion(Casilla &, int)
{
}

bool Pieza::comprobarColision(Jugada &)
{
    return false;
}

int Pieza::leerCasilla(Casilla &)
{
    return 0;
}

int Pieza::getTurno()
{
    return 0;
}
