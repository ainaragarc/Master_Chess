#include "GestorEstados.h"
#include "PantallaInicio.h"
#include "MenuPrincipal.h"
#include "PantallaSeleccionTablero.h"
#include "PantallaSeleccionBot.h"
#include "PantallaSeleccionNivel.h"
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
        gestor_pantallas.dibuja();
        break;
        
    case VICTORIA_NEGRO:
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
            default:
                break;
            }
        }
        
        // Aquí la logica para seleccionar el tipo de contringante
        PantallaSeleccionBot* selectorVS = dynamic_cast<PantallaSeleccionBot*>(pantalla);
        if (selectorVS) {
            switch (selectorVS->get_accion()) {
            case AccionBot::VS_BOT:
                selectorVS->reset_accion();
                tipo_VS_seleccionado = TipoVS::BOT;

                //Mostrar pantalla de selector de modo del nivel
                gestor_pantallas.set_pantalla(new PantallaSeleccionNivel(&gestor_pantallas));
                
                break;
            case AccionBot::VS_AMIGO:
                selectorVS->reset_accion();
                tipo_VS_seleccionado = TipoVS::AMIGO;
                estado_actual = JUGANDO;
          
                break;
            default:
                break;
            }
        }

        // Aquí la logica para seleccionar el nivel del bot
        PantallaSeleccionNivel* selectorNivel = dynamic_cast<PantallaSeleccionNivel*>(pantalla);
        if (selectorNivel) {
            switch (selectorNivel->get_accion()) {
            case AccionNivel::Nivel1:
                selectorNivel->reset_accion();
                tipo_Nivel_seleccionado = NivelBot::NIVEL1;
                estado_actual = JUGANDO;
                inicializa();
                break;
            case AccionNivel::Nivel2:
                selectorNivel->reset_accion();
                tipo_Nivel_seleccionado = NivelBot::NIVEL2;
                estado_actual = JUGANDO;
                inicializa();
                break;
            case AccionNivel::Nivel3:
                selectorNivel->reset_accion();
                tipo_Nivel_seleccionado = NivelBot::NIVEL3;
                estado_actual = JUGANDO;
                inicializa();
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
                switch (tipo_Nivel_seleccionado)
                {
                case GestorEstados::NivelBot::NIVEL1:
                    bot.juegaNivel1(mundo);
                    break;
                case GestorEstados::NivelBot::NIVEL2:
                    bot.juegaNivel2(mundo);
                    break;
                case GestorEstados::NivelBot::NIVEL3:
                    bot.juegaNivel3(mundo);
                    break;
                default:
                    break;
                }
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