#include "PantallaInicio.h"
#include "BrochaPantallas.h"

void PantallaInicio::dibuja() {
	BrochaPantallas::limpiar_pantalla(0.1f, 0.1f, 0.2f);
	BrochaPantallas::dibujar_texto("MASTERCHESS", -0.3f, 0.6f);
}

void PantallaInicio::actualiza() {

}