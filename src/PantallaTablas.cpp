#include "PantallaTablas.h"
#include "BrochaPantallas.h"

void PantallaTablas::dibuja() {

    ColorTextos colorTexto = ColorTextos(1.0f, 1.0f, 1.0f);
    BrochaPantallas::dibujar_texto("TABLAS", Coordenada{-0.5f, 0.1f}, colorTexto);  //texto negro

}