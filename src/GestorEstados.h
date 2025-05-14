#pragma once
#include "Mundo.h"

class GestorEstados {

private:
    enum Estado { MENU, JUGANDO, PAUSA, FIN }estado_actual{};
    //Mundo mundo; descomentar cuando este terminada la implementación

public:
    
    void cambiar_estado(Estado nuevo) { estado_actual = nuevo; }//funcion para cambiar de estado
    Estado get_estado() const { return estado_actual; }

    void inicializa();
    void dibuja();
    void mueve();
    void tecla(unsigned char key);
    void raton(int button, int state, int x, int y);
};