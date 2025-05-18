#include "GestorEstados.h"
#include "PantallaInicio.h"
#include "MenuPrincipal.h"
#include "PantallaSeleccionTablero.h"

void GestorEstados::inicializa() {
    if (estado_actual == MENU) {
        gestor_pantallas.set_pantalla(new PantallaInicio(&gestor_pantallas));
    }
    else if (estado_actual == JUGANDO) {
        switch (tipo_tablero_seleccionado) {
        case TipoTablero::BABY:
            mundo.inicializa_tablero_baby();
            break;
        case TipoTablero::GARDNER:
            mundo.inicializa_tablero_gardner();
            break;
        default:
            break;
        }
    }
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

        Pantalla* pantalla = gestor_pantallas.get_pantalla();
        MenuPrincipal* menu = dynamic_cast<MenuPrincipal*>(pantalla);

        if (menu) {
            switch (menu->get_accion()) {
            case AccionMenu::NUEVA_PARTIDA:
                menu->reset_accion();
                // Aquí cambiamos la pantalla al selector de tablero
                gestor_pantallas.set_pantalla(new PantallaSeleccionTablero(&gestor_pantallas));
                return; // cortamos aquí para esperar la siguiente iteración
            case AccionMenu::SALIR:
                menu->reset_accion();
                exit(0);
            default:
                break;
            }
        }

       
        PantallaSeleccionTablero* selector = dynamic_cast<PantallaSeleccionTablero*>(pantalla);
        if (selector) {
            switch (selector->get_accion()) {
            case AccionTablero::TABLERO_BABY:
                selector->reset_accion();
                tipo_tablero_seleccionado = TipoTablero::BABY;
                estado_actual = JUGANDO;
                inicializa();
                break;
            case AccionTablero::TABLERO_GARDNER:
                selector->reset_accion();
                tipo_tablero_seleccionado = TipoTablero::GARDNER;
                estado_actual = JUGANDO;
                inicializa();
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