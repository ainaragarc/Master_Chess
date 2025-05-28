#pragma once
#include "Pantalla.h"
#include "GestorPantallas.h"
#include "Mundo.h"

enum class AccionPausa {
    NINGUNA,
    REANUDAR,
    RENDIRSE,
    GUARDAR,
    SALIR_JUEGO
};

class PantallaPausa : public Pantalla {
private:
    GestorPantallas* gestor;
    Mundo* mundo;  // Para dibujar el tablero
    AccionPausa accion = AccionPausa::NINGUNA;

public:
    PantallaPausa(GestorPantallas* gestor, Mundo* mundo);

    void dibuja() override;
    void raton(int button, int state, int x, int y) override;

    AccionPausa get_accion() const { return accion; }
    void reset_accion() { accion = AccionPausa::NINGUNA; }
};