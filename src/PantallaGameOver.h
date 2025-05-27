#pragma once
#include "Pantalla.h"
#include "Mundo.h"
#include <string>

class PantallaGameOver : public Pantalla {
private:
    std::string mensaje;

public:
    PantallaGameOver(const std::string& ganador);
    void dibuja() override;
    
};

