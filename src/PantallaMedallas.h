#pragma once
#include "Pantalla.h"
#include <string>
#include "GestorPantallas.h"
#include <vector>
#include "PantallaSeleccionBot.h"
enum class Medallas { NINGUNO, VOLVER };

class PantallaMedallas:public Pantalla
{
	GestorPantallas* gestor;
	Medallas accion_pendiente = Medallas::NINGUNO;
public:
	PantallaMedallas(GestorPantallas* gestor);
	void dibuja() override;
	void dibuja_medallas();
	void raton(int button, int state, int x, int y) override;

	//comunicacion con GestorEstados
	Medallas get_accion() const { return accion_pendiente; }
	void reset_accion() { accion_pendiente = Medallas::NINGUNO; }
};

