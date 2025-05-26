#pragma once
#include "Pantalla.h"
#include <string>
#include <vector>

class PantallaCoronando : public Pantalla {
private:
    std::string mensaje;
    std::vector<Boton> botones;

public:

    PantallaCoronando();
    void dibuja() override;
    char tipo(); //devolvera a lo que quieres coronar, y devolvera a jugando (tenfgo que comprobar que se pueda)
    //no se si tendre que crear un estado, o puedo pintar por encima y luego quitarla, probare

};

