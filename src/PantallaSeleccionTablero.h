#pragma once
#include "Pantalla.h"
#include "GestorPantallas.h"
#include <vector>
enum class AccionTablero {
    NINGUNO,
    TABLERO_BABY,
    TABLERO_GARDNER
};
class PantallaSeleccionTablero : public Pantalla
{
    GestorPantallas* gestor;
    std::vector<Boton> botones;
    AccionTablero accion_pendiente = AccionTablero::NINGUNO;//inicializamos el estado en ninguna accion (espera a que selecciones una opcion)


public:
    PantallaSeleccionTablero(GestorPantallas* gestor);
    void dibuja() override;
    void raton(int button, int state, int x, int y) override;
    void tecla(unsigned char key) override {}

    //comunicacion con GestorEstados
    AccionTablero get_accion() const { return accion_pendiente; }
    void reset_accion() { accion_pendiente = AccionTablero::NINGUNO; }

   
};

