#pragma once

#include "Pantalla.h"
#include "GestorPantallas.h"
#include <string>

class PantallaInicio : public Pantalla {
private:
    float tiempo_carga = 0.0f;         //tiempo instant�neo en segundos
    const float tiempo_total = 6.0f;   //duraci�n total de la carga en segundos
    GestorPantallas* gestor = nullptr; //referencia al gestor para cambiar de pantalla

public:
    
    void dibuja() override;
    void actualiza() override;
    //Para seleccionar la pantalla de selecci�n de tablero
    void set_pantallaselect_tablero();
    void mover_raton(int, int) override {} //funcion vacia para que no se use la funcion mover_raton

    PantallaInicio(GestorPantallas* gestor): gestor(gestor) {}//constructor que recibe un puntero
};