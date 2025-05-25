#pragma once
#include <string>
#include "Pantalla.h"

class BrochaPantallas {
public:
    //limpia pantalla y pone fondo
    static void limpiar_pantalla(ColorTextos color);

    //bibuja texto en la posicion que quieras
    static void dibujar_texto(const std::string& texto, Coordenada pos, ColorTextos color);

    //dibuja una barra de carga horizontal
    static void dibujar_barra_carga(float progreso, Coordenada desde, Coordenada hasta, ColorTextos color);

    //funcion para convertir coordenadas
    static Coordenada convertir_click_a_opengl(int x, int y);

    //compruba si se ha hecho cllick
    static bool es_clic_izquierdo(int button, int state);
};