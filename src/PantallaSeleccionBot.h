#pragma once
#include "Pantalla.h"
#include "GestorPantallas.h"
#include <vector>

enum class AccionBot {NINGUNO, VS_BOT, VS_AMIGO};

class PantallaSeleccionBot : public Pantalla {
    GestorPantallas* gestor;
    std::vector<Boton> botones;
    AccionBot accion_pendiente = AccionBot::NINGUNO;    //inicializamos el estado en ninguna accion (espera a que selecciones una opcion)

public: 
    PantallaSeleccionBot(GestorPantallas* gestor);
    void dibuja() override;
    void raton(int button, int state, int x, int y) override;
    void tecla(unsigned char key) override {}

    //comunicacion con GestorEstados
    AccionBot get_accion() const { return accion_pendiente; }
    void reset_accion() { accion_pendiente = AccionBot::NINGUNO; }
};
