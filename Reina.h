#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
public:
	Reina(void);
	virtual ~Reina(void);

	bool mover (struct Jugada&);
};