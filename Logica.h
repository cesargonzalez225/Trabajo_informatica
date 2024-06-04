#pragma once

#include "Tablero.h"
#include "Casilla.h"
#include "Alfil.h"
#include "Caballo.h"
#include "peon.h"
#include "rey.h"
#include "Reina.h"
#include "Torre.h"

Tablero sumamatrices(Tablero x, Tablero y);
Tablero vermovimiento(Tablero tablero, Casilla origen, int turno);
Tablero forzarcomer(Tablero tablero, Casilla ultimomov, int turno);