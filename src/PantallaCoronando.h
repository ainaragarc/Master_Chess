#pragma once
#include "Pantalla.h"
#include <string>
#include "GestorPantallas.h"
#include "GestorEstados.h"  
#include <vector>


enum class AccionCoronar { NINGUNO, CABALLO, TORRE, DAMA, ALFIL };

class PantallaCoronando : public Pantalla {
private:
    std::string mensaje;
    GestorPantallas* gestor;
    AccionCoronar accion_pendiente = AccionCoronar::NINGUNO;

public:

    void dibuja() override;
    char tipo(); //devolvera a lo que quieres coronar, y devolvera a jugando (tenfgo que comprobar que se pueda)
    //no se si tendre que crear un estado, o puedo pintar por encima y luego quitarla, probare

    PantallaCoronando(GestorPantallas* gestor);

    void raton(int button, int state, int x, int y) override;

    //comunicacion con GestorEstados
    AccionCoronar get_accion() const { return accion_pendiente; }
    void reset_accion() { accion_pendiente = AccionCoronar::NINGUNO; }

};

