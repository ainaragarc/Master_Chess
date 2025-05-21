#pragma once
#include "Mundo.h"
#include "GestorPantallas.h"
class GestorEstados {

private:
    enum Estado { MENU, JUGANDO, PAUSA, FIN }estado_actual{MENU};//Define el estado del juego en el momento
    enum class TipoTablero { NINGUNO, BABY, GARDNER }tipo_tablero_seleccionado{ TipoTablero::NINGUNO };//Define el Tipo de Tablero en el momento
    Mundo mundo; 
    GestorPantallas gestor_pantallas;

public:
    
    void cambiar_estado(Estado nuevo) { estado_actual = nuevo; }//funcion para cambiar de estado
    Estado get_estado() const { return estado_actual; }

    void inicializa();
    void dibuja();
    void mueve();
    void tecla(unsigned char key);
    void raton(int button, int state, int x, int y);

    //funcion para poder acceder al gestor desde fuera
    GestorPantallas& get_gestor_pantallas() { return gestor_pantallas; }


    Bot bot;
};