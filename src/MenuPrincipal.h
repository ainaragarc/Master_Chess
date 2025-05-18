#pragma once
#include "Pantalla.h"
#include "GestorPantallas.h"

class MenuPrincipal : public Pantalla {
private:
    GestorPantallas* gestor;

public:
    MenuPrincipal(GestorPantallas* gestor);
    void dibuja() override;
    //void actualiza() override {}  de momento no hace falta
    void raton(int button, int state, int x, int y) override;
    void tecla(unsigned char key) override {}
};