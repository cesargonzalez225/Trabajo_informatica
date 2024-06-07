#pragma once
#include "Casilla.h"
#include "Tablero.h"


class Pieza
{
    public:
		Pieza();
		~Pieza();
		Tablero iluminado;
		Tablero matriz;
		Tablero matrizcomer;
		Tablero sumamatrices(Tablero x, Tablero y);
		Tablero multiplicamatrices(Tablero x, Tablero y);
		void movimientos(Tablero tablero, Casilla origen, int turno);//antigua ver movimiento
		void movimientoPeon(Tablero tablero, Casilla origen);
		void movimientoReina(Tablero tablero, Casilla origen);
		void movimientoCaballo(Tablero tablero, Casilla origen);
		void movimientoAlfil(Tablero tablero, Casilla origen);
		void movimientoRey(Tablero tablero, Casilla origen);
		void movimientoTorre(Tablero tablero, Casilla origen);
		void forzarcomer(Tablero tablero, int turno);
		void vermovimiento(Tablero& tablero, Casilla origen, int turno);
};

