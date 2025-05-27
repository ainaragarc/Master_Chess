#pragma once
#include "Pantalla.h"
#include <string>
#include "GestorPantallas.h"
#include <vector>


enum class AccionCoronar { NINGUNO, CABALLO, TORRE, DAMA, ALFIL };

class PantallaCoronando : public Pantalla {
    GestorPantallas* gestor;
    AccionCoronar accion_pendiente = AccionCoronar::NINGUNO;

public:
    
    PantallaCoronando(GestorPantallas* gestor);
    void dibuja() override;
	
    void raton(int button, int state, int x, int y) override {};
    void tecla(unsigned char key) override;

    //comunicacion con GestorEstados
    AccionCoronar get_accion() const { return accion_pendiente; }
    void reset_accion() { accion_pendiente = AccionCoronar::NINGUNO; }
};

