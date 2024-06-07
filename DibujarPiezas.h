#pragma once
#include "Casilla.h"
#include "freeglut.h"
#include "ETSIDI.h"

class DibujarPiezas
{

public:
	DibujarPiezas(void);
	~DibujarPiezas(void);


	void dibujaPeonNegra(int x, int y);
	void dibujaPeonBlanca(int x, int y);
	void dibujaAlfilNegra(int x, int y);
	void dibujaAlfilBlanca(int x, int y);
	void dibujaTorreNegra(int x, int y);
	void dibujaTorreBlanca(int x, int y);
	void dibujaCaballoNegra(int x, int y);
	void dibujaCaballoBlanca(int x, int y);
	void dibujaReyNegra(int x, int y);
	void dibujaReyBlanca(int x, int y);
	void dibujaReinaNegra(int x, int y);
	void dibujaReinaBlanca(int x, int y);
	void dibujaPieza(int x, int y, const char* tex);
};

