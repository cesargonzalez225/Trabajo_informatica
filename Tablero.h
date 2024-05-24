#pragma once
class Tablero

{
    static int Inicio[8][8];
public:
	Tablero(void);
	virtual ~Tablero(void);

    int tablero[8][8];
	int leerCasilla(Casilla &casilla);
	void reset ();
};

