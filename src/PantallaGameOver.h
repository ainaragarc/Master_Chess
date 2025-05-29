#pragma once
#include "Pantalla.h"
#include "Mundo.h"
#include "GestorPantallas.h"
#include <vector>
#include <string>
enum class Game_over { NINGUNO, VOLVER };

class PantallaGameOver : public Pantalla {
private:
    GestorPantallas* gestor;
    Mundo* mundo;
    std::string mensaje;
    Game_over accion_pendiente = Game_over::NINGUNO;
public:
    PantallaGameOver(GestorPantallas* gestor, Mundo* mundo, const std::string& ganador);
    
    void dibuja() override;

    void raton(int button, int state, int x, int y) override;

    //comunicacion con GestorEstados
    Game_over get_accion() const { return accion_pendiente; }
    void reset_accion() { accion_pendiente = Game_over::NINGUNO; }
};

