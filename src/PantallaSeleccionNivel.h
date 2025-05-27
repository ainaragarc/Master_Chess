#pragma once

#include "Pantalla.h"
#include "GestorPantallas.h"
#include <vector>

enum class AccionNivel { NINGUNO, Nivel1, Nivel2, Nivel3 };

class PantallaSeleccionNivel : public Pantalla {
    GestorPantallas* gestor;
    AccionNivel accion_pendiente = AccionNivel::NINGUNO;    //inicializamos el estado en ninguna accion (espera a que selecciones una opcion)

public:
    PantallaSeleccionNivel(GestorPantallas* gestor);
    void dibuja() override;
    void raton(int button, int state, int x, int y) override;
    void tecla(unsigned char key) override {}

    //comunicacion con GestorEstados
    AccionNivel get_accion() const { return accion_pendiente; }
    void reset_accion() { accion_pendiente = AccionNivel::NINGUNO; }
};