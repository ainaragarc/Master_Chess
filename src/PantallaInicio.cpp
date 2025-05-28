#include "PantallaInicio.h"
#include "BrochaPantallas.h"
#include "MenuPrincipal.h"
#include "PantallaSeleccionTablero.h"

void PantallaInicio::dibuja() {
	BrochaPantallas::limpiar_pantalla(ColorTextos(0.1f, 0.1f, 0.2f));
	ColorTextos colorTexto = ColorTextos(1.0f, 1.0f, 1.0f);
	BrochaPantallas::dibujar_texto("MASTERCHESS", Coordenada{ -0.3f, 0.6f },colorTexto);
	//NO SE PUEDE METER AUN, ROMPE LAS COORDENADAS
	//BrochaPantallas::insertarimagen("imagenes/inicio.png", 1.0, 1.0, 1.0, 1.0);
	BrochaPantallas::dibujar_barra_carga(tiempo_carga / tiempo_total, Coordenada{ -0.5f, -0.2f }, Coordenada{ 0.5f, -0.1f }, ColorTextos(0.2f, 0.8f, 0.3f));
}

void PantallaInicio::actualiza() {
	tiempo_carga += 0.05f;
	if (tiempo_carga >= tiempo_total) {
		gestor->set_pantalla(new MenuPrincipal(gestor));
	}
}

void PantallaInicio::set_pantallaselect_tablero() {
		gestor->set_pantalla(new PantallaSeleccionTablero(gestor));
}