#pragma once
#include <string>
#include "Pantalla.h"

class BrochaPantallas {
public:
    //limpia pantalla y pone fondo
    static void limpiar_pantalla(float r, float g, float b);

    //bibuja texto en la posicion que quieras
    static void dibujar_texto(const std::string& texto, float x, float y, float r = 1, float g = 1, float b = 1);

    //dibuja una barra de carga horizontal
    static void dibujar_barra_carga(float progreso, float x1, float y1, float x2, float y2, float r, float g, float b);
};