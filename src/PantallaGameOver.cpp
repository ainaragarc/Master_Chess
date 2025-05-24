
#include "PantallaGameOver.h"
#include "BrochaPantallas.h"
#include "freeglut.h"

PantallaGameOver::PantallaGameOver(const std::string& ganador) {
    mensaje = "VICTORIA DE " + ganador;
}

void PantallaGameOver::dibuja() {
    BrochaPantallas::limpiar_pantalla(250.0f, 250.0f, 250.0f);  // Fondo 
    BrochaPantallas::dibujar_texto(mensaje, -0.5f, 0.1f, 1.0f, 1.0f, 1.0f);  //texto negro
   
}

