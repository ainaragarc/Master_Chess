#include "PantallaInicio.h"
#include "BrochaPantallas.h"
#include "MenuPrincipal.h"

void PantallaInicio::dibuja() {
	BrochaPantallas::limpiar_pantalla(Color(0.1f, 0.1f, 0.2f));
	Color colorTexto = Color(1.0f, 1.0f, 1.0f);
	BrochaPantallas::dibujar_texto("MASTERCHESS", Coordenada{ -0.3f, 0.6f },colorTexto);
	BrochaPantallas::dibujar_barra_carga(tiempo_carga / tiempo_total, Coordenada{ -0.5f, -0.2f }, Coordenada{ 0.5f, -0.1f },Color(0.2f, 0.8f, 0.3f));
}

void PantallaInicio::actualiza() {
	tiempo_carga += 0.05f;
	if (tiempo_carga >= tiempo_total) {
		gestor->set_pantalla(new MenuPrincipal(gestor));
	}
}