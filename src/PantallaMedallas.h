#pragma once
#include "Pantalla.h"
#include <string>
#include "GestorPantallas.h"
#include <vector>
#include "PantallaSeleccionBot.h"
class PantallaMedallas:public Pantalla
{
	GestorPantallas* gestor;
public:
	void dibuja() override;
	PantallaMedallas(GestorPantallas* gestor);
	void raton(int button, int state, int x, int y) override;
};

