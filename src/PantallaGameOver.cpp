
#include "PantallaGameOver.h"
#include "BrochaPantallas.h"
#include "freeglut.h"

PantallaGameOver::PantallaGameOver(const std::string& ganador) {
    mensaje = "VICTORIA DE " + ganador;
}

void PantallaGameOver::dibuja() {
    BrochaPantallas::limpiar_pantalla(ColorTextos(250.0f, 250.0f, 250.0f));  // Fondo 
    ColorTextos colorTexto = ColorTextos(1.0f, 1.0f, 1.0f);
    BrochaPantallas::dibujar_texto(mensaje, Coordenada{ -0.5f, 0.1f }, colorTexto);  //texto negro
   
}

