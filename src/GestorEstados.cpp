#include "GestorEstados.h"
#include "PantallaInicio.h"
#include "MenuPrincipal.h"
#include "PantallaSeleccionTablero.h"
#include "PantallaSeleccionBot.h"
#include "PantallaGameOver.h"



#include <iostream>

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
    else if (estado_actual == VICTORIA_BLANCO) {
        gestor_pantallas.set_pantalla(new PantallaGameOver("BLANCAS"));
        
    }
    else if (estado_actual == VICTORIA_NEGRO) {
        gestor_pantallas.set_pantalla(new PantallaGameOver("NEGRAS"));
        
    }
    mundo.set_estado(this);//pasamos informacion del estado actual a mundo

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

    case VICTORIA_BLANCO:
        mundo.dibuja();
        gestor_pantallas.dibuja();
        
        break;
        
    case VICTORIA_NEGRO:
        mundo.dibuja();
        gestor_pantallas.dibuja();
       
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

                //Mostrar pantalla de selector de modo del bot
                gestor_pantallas.set_pantalla(new PantallaSeleccionBot(&gestor_pantallas));               
                break;

            case AccionTablero::TABLERO_GARDNER:
                selector->reset_accion();
                tipo_tablero_seleccionado = TipoTablero::GARDNER;

                //Mostrar pantalla de selector de modo del bot
                gestor_pantallas.set_pantalla(new PantallaSeleccionBot(&gestor_pantallas));              
                break;

            case AccionTablero::VOLVER:
                selector->reset_accion();
                gestor_pantallas.set_pantalla(new MenuPrincipal(&gestor_pantallas));
                break;

            default:
                break;
            }
        }
        
        PantallaSeleccionBot* selectorVS = dynamic_cast<PantallaSeleccionBot*>(pantalla);
        if (selectorVS) {
            switch (selectorVS->get_accion()) {
            case AccionBot::VS_BOT:
                selectorVS->reset_accion();
                tipo_VS_seleccionado = TipoVS::BOT;
                estado_actual = JUGANDO;
                inicializa();
                break;

            case AccionBot::VS_AMIGO:
                selectorVS->reset_accion();
                tipo_VS_seleccionado = TipoVS::AMIGO;
                estado_actual = JUGANDO;
                inicializa();
                break;

            case AccionBot::VOLVER:
                selectorVS->reset_accion();
                gestor_pantallas.set_pantalla(new PantallaSeleccionTablero(&gestor_pantallas));
                break;
            default:
                break;
            }
        }
    }

    if (estado_actual == JUGANDO) {
        mundo.mueve();
        // Turno del bot (negras)
        switch (tipo_VS_seleccionado)
        {
        case GestorEstados::TipoVS::BOT:
            if (mundo.get_turno() == Turno::NEGRO) { // Solo juega el bot si es su turno
                bot.juega(mundo);
            }
            break;
        default:
            break;
        }
    }
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

void GestorEstados::mover_raton(int x, int y) {
    if (estado_actual == MENU)
        gestor_pantallas.mover_raton(x, y);
}