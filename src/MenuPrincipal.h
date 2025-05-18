#pragma once
#include "Pantalla.h"
#include "GestorPantallas.h"
#include <vector>

//creamos un struct para los distintos estados dentro del menu
enum class AccionMenu {
    NINGUNA,
    NUEVA_PARTIDA,
    SALIR
};

class MenuPrincipal : public Pantalla {
private:
    GestorPantallas* gestor;
    std::vector<Boton> botones;
    AccionMenu accion_pendiente = AccionMenu::NINGUNA;//inicializamos el estado en ninguna accion (espera a que selecciones una opcion)

public:
    MenuPrincipal(GestorPantallas* gestor);
    void dibuja() override;
    //void actualiza() override {}  de momento no hace falta
    void raton(int button, int state, int x, int y) override;
    void tecla(unsigned char key) override {}

    //comunicacion con GestorEstados
    AccionMenu get_accion() const { return accion_pendiente; }
    void reset_accion(){ accion_pendiente = AccionMenu::NINGUNA; }
};