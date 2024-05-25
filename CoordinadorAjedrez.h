#pragma once
#include "Mundo.h"
#include "ETSIDI.h"
class CoordinadorAjedrez
{
public:
	CoordinadorAjedrez();
	virtual ~CoordinadorAjedrez();
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO, FIN, GAMEOVER, PAUSA };
	Estado estado;
};
