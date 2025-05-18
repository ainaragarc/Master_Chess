#include "MenuPrincipal.h"
#include "BrochaPantallas.h"

MenuPrincipal::MenuPrincipal(GestorPantallas* gestor) : gestor(gestor) {}

void MenuPrincipal::dibuja() {
    BrochaPantallas::limpiar_pantalla(0.15f, 0.15f, 0.15f);
    BrochaPantallas::dibujar_texto("MENU PRINCIPAL", -0.3f, 0.2f);
}

void MenuPrincipal::raton(int button, int state, int x, int y) {

}

