#include "GestorEstados.h"
#include "PantallaInicio.h"
#include "MenuPrincipal.h"

void GestorEstados::inicializa() {//podemos usarla para inicializar, aunque se puede inicializar en otro sitio
    if (estado_actual == MENU) {
        gestor_pantallas.set_pantalla(new PantallaInicio(&gestor_pantallas));
    }
    if (estado_actual == JUGANDO)
        mundo.inicializa();
}

void GestorEstados::dibuja() {
    switch (estado_actual) {
    case MENU:
        gestor_pantallas.dibuja();
        break;
    case JUGANDO:
        mundo.dibuja();
        break;
    case PAUSA:
        // dibujar pausa
        break;
    default:
        break;
    }
}

void GestorEstados::mueve() {
   if (estado_actual == MENU) {
        gestor_pantallas.actualiza();

        //comprobamos si la pantalla actual es menuprincipal
        Pantalla* pantalla = gestor_pantallas.get_pantalla();
        auto* menu = dynamic_cast<MenuPrincipal*>(pantalla);
        
        if (menu) {
            switch (menu->get_accion()) {
            case AccionMenu::NUEVA_PARTIDA: //al seleccionar el boton de nueva partida iniciamos mundo
                menu->reset_accion();
                estado_actual = JUGANDO;
                inicializa();
                break;

            case AccionMenu::SALIR:
                menu->reset_accion();
                exit(0); //salir directamente del juego
                break;

            default:
                break;
            }
        }

   }
   if (estado_actual == JUGANDO)
        mundo.mueve();
}

void GestorEstados::tecla(unsigned char key) {
    if (estado_actual == MENU)
        gestor_pantallas.tecla(key);
}

void GestorEstados::raton(int button, int state, int x, int y) {
    if (estado_actual == MENU)
        gestor_pantallas.raton(button, state, x, y);
    if (estado_actual == JUGANDO)
        mundo.gestionar_click(button, state, x, y);
}