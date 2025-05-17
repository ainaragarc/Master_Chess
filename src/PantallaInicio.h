#pragma once

#include "Pantalla.h"
#include "GestorPantallas.h"
#include <string>

class PantallaInicio : public Pantalla {
private:
    GestorPantallas* gestor = nullptr; //referencia al gestor para cambiar de pantalla

public:
    
    void dibuja() override;
    void actualiza() override;

    PantallaInicio(GestorPantallas* gestor): gestor(gestor) {}//constructor que recibe un puntero
};