
#include "PantallaGameOver.h"
#include "BrochaPantallas.h"
#include "freeglut.h"
#include "Mundo.h"

PantallaGameOver::PantallaGameOver(const std::string& ganador) {
    mensaje = ganador;
   
}

void PantallaGameOver::dibuja() {
   
    if (mensaje == "BLANCAS") {
        BrochaPantallas::insertarimagen("imagenes/Victoria para blancas.png");
    }
    if (mensaje == "NEGRAS") {
        BrochaPantallas::insertarimagen("imagenes/Victoria para negras.png");
    }
   
}

