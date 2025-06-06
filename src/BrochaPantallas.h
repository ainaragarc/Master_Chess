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

    static void insertarimagen(const char* direccion, double x1, double y1, double x2, double y2);

    static void dibujar_recuadro(Coordenada desde, Coordenada hasta, ColorTextos color, float opacidad = 1.0f);

    static void configurar_proyeccion_pantalla(double num);

    static float calcular_ajuste_centrado_texto(const std::string& texto, float ventana_pixeles = 600.0f);
};