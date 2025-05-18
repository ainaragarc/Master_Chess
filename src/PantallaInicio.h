#pragma once

#include "Pantalla.h"
#include "GestorPantallas.h"
#include <string>

class PantallaInicio : public Pantalla {
private:
    float tiempo_carga = 0.0f;         //tiempo instantáneo en segundos
    const float tiempo_total = 6.0f;   //duración total de la carga en segundos
    GestorPantallas* gestor = nullptr; //referencia al gestor para cambiar de pantalla

public:
    
    void dibuja() override;
    void actualiza() override;

    PantallaInicio(GestorPantallas* gestor): gestor(gestor) {}//constructor que recibe un puntero
};